let sessionCookie = 0;

function csrfCheck() {
    fetch("csrf.php", {
        method: 'POST',
        body: JSON.stringify(),
        headers: { 'content-type': 'application/json' }
    })
    .then(response => response.json())
    .then (data => setCSRF(data))
    .catch(error => console.error('Error:',error));
}

function setCSRF (data) {
    sessionCookie = data.token;
}

let currentMonth = new Month(2020, 10);
let monthNames = ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"]
function fillCalendarDates() {
    let firstDate = currentMonth.getDateObject(1);
    let firstDay = firstDate.getDay();
    let lastDate = currentMonth.nextMonth().getDateObject(0);
    let numDates = lastDate.getDate();
    let indexStart = firstDay;
    let indexEnd = indexStart + numDates; 
    let date = 1;
    let output = document.getElementById("month_year");
    output.innerHTML = monthNames[currentMonth.month] + " " + currentMonth.year;
    //clear table of data\
    for (i = 0; i < 42; i++) {
        document.getElementById(String(i)).innerHTML = "x";
    }
    for (index = indexStart; index < indexEnd; index++) {
        indexStr = String(index);
        document.getElementById(indexStr).innerHTML = date;
        date++;
    } 
}

function Event(event_name, event_date, event_time, event_id, event_tag) { //does not account for user, month, year because those are preparam
    this.name = event_name;
    this.date = event_date;
    this.time = event_time;
    this.id = event_id;//
    this.tag = event_tag;
}
function TodayEvent(event_name, event_time, event_id, event_tag) { //does not account for user, month, year because those are preparam
    this.name = event_name;
    this.time = event_time;
    this.id = event_id;//
    this.tag = event_tag;
}

function callEventsAjax(month, year) {
    const event_month = month // Get the username from the form
    const event_year = year; // Get the password from the form

    // Make a URL-encoded string for passing POST data:
    const data = { 'event_month': event_month, 'event_year': event_year };

    fetch("callevents.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => {
            let returnData = compileData(data);
            fillCalendarEvents(returnData);
        })
        .catch(err => console.error(err));
        
}
function callEventsAjaxFiltered(month, year, tag) {
    const event_month = month // Get the month from the form
    const event_year = year; // Get the year from the form
    const event_tag = tag;

    // Make a URL-encoded string for passing POST data:
    const data = { 'event_month': event_month, 'event_year': event_year, 'event_tag' : event_tag };

    fetch("calleventsfiltered.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => {
            let returnData = compileData(data);
            fillCalendarEvents(returnData);
        })
        .catch(err => console.error(err));
        
}

function compileData(data){
    let returnData = [];
    let names = data.event_names;
    let dates = data.event_dates;
    let times = data.event_times;
    let ids = data.event_ids;
    let tags = data.event_tags;
    if (names!= undefined) {
        for (i = 0; i < names.length; i++) {
            let new_event = new Event(names[i], dates[i], times[i], ids[i], tags[i]);
            returnData.push(new_event);
        }
    }
    return returnData;
}

function compileDataToday(data){
    let returnData = [];
    let names = data.event_names;
    let times = data.event_times;
    let ids = data.event_ids;
    let tags = data.event_tags;
    if (names!= undefined) {
        for (i = 0; i < names.length; i++) {
            let new_event = new TodayEvent(names[i], times[i], ids[i], tags[i]);
            returnData.push(new_event);
        }
    }
    return returnData;
}

function fillCalendarEvents(eventarray) {
    let firstDate = currentMonth.getDateObject(1);
    let firstDay = firstDate.getDay();
    let lastDate = currentMonth.nextMonth().getDateObject(0);
    let numDates = lastDate.getDate();
    let indexStart = firstDay;
    let indexEnd = indexStart + numDates; 
    let date = 1;
    let output = document.getElementById("month_year");
    output.innerHTML = monthNames[currentMonth.month] + " " + currentMonth.year;
    //clear table of data\
    for (i = 0; i < 42; i++) {
        document.getElementById(String(i)).innerHTML = "x";
    }
    for (index = indexStart; index < indexEnd; index++) {
        indexStr = String(index);
        document.getElementById(indexStr).innerHTML = date;
        //if exists
        if (eventarray!= undefined) {
            for (i = 0; i < eventarray.length; i++) {
                if (eventarray[i].date == date) {
                    //time display
                    let timeleftcol = (Math.ceil(eventarray[i].time/100));
                    let modtimeleftcol = (Math.ceil(eventarray[i].time/100) * 100);
                    let timerightcol = eventarray[i].time % modtimeleftcol;
                    if (timeleftcol < 10) {
                        timeleftcol = "0" + String(timeleftcol);
                    }
                    if (timerightcol < 10) {
                        timerightcol = "0" + String(timerightcol);
                    }
    
                    document.getElementById(indexStr).innerHTML = document.getElementById(indexStr).innerHTML + "<br>" +
                    "Event Name: " + eventarray[i].name + "<br>" +
                    "Event Time: " + timeleftcol + ":" + timerightcol + "<br>" +
                    "Event ID: " + eventarray[i].id + "<br>" +
                    "Tag: " + eventarray[i].tag + "<br>";
                }
            }
        }
        date++;
    } 
    callEventsTodayAjax();
}


//add, delete, edit events
function addEventAjax() {

        const event_month_curr = currentMonth.month;
        const event_year_curr = currentMonth.year;
        const event_month = document.getElementById("add_event_month").value - 1;
        const event_year = document.getElementById("add_event_year").value;
        const event_date = document.getElementById("add_event_date").value;
        const event_name = document.getElementById("add_event_name").value;
        const event_time = document.getElementById("add_event_time").value;
        const share_username = document.getElementById("share_username").value;
        let event_tag_var = "";
        let tag_check = document.getElementsByName("add_tag");
        for (i = 0; i < tag_check.length; i++) {
            if (tag_check[i].checked) {
                event_tag_var = tag_check[i].value;
            }
        }
        const event_tag = event_tag_var;
        if (event_month == -1 || event_year == 0 || event_date == 0|| event_name == 0 || event_time == 0) {
            alert("You entered a null or invalid value! Try again.")
        }
        else {
        const data = { 'event_month': event_month, 'event_year': event_year, 'event_date': event_date, 'event_name': event_name, 'event_time': event_time, 'share_username': share_username, 'event_tag' : event_tag, 'token': sessionCookie};

        fetch("addevent.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => console.log(data.success ? "You have added an event!" : `No event added ${data.message}`))
        .catch(err => console.error(err));
        callEventsAjax(event_month_curr, event_year_curr);
    }
}

function deleteEventAjax() {
    const event_month_curr = currentMonth.month;
    const event_year_curr = currentMonth.year;
    const event_id = document.getElementById("del_by_event_id").value;
    if (event_id == 0) {
        alert("You entered a null value!");
    }
    else {
        const data = { 'event_id' : event_id, 'token': sessionCookie };
        fetch("deleteevent.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        // csrfCheck();
        .then(response => response.json())
        .then(data => console.log(data.success ? "You have deleted an event!" : `No event deleted ${data.message}`))
        .catch(err => console.error(err));
        // csrfCheck();
        callEventsAjax(event_month_curr, event_year_curr);
    }

}

function editEventAjax() {
        const event_month_curr = currentMonth.month;
        const event_year_curr = currentMonth.year;
        const event_id = document.getElementById("edit_event_id").value;
        const event_month = document.getElementById("edit_event_month").value - 1;
        const event_year = document.getElementById("edit_event_year").value;
        const event_date = document.getElementById("edit_event_date").value;
        const event_name = document.getElementById("edit_event_name").value;
        const event_time = document.getElementById("edit_event_time").value;
        let event_tag_var = "";
        let tag_check = document.getElementsByName("edit_tag");
        for (i = 0; i < tag_check.length; i++) {
            if (tag_check[i].checked) {
                event_tag_var = tag_check[i].value;
            }
        }
        const event_tag = event_tag_var;
        if (event_month == -1 || event_year == 0 || event_date == 0|| event_name == 0 || event_time < 0 || event_time > 2359) {
            alert("You entered a null or invalid value! Try again.")
        }
        else {
        const data_del = { 'event_id' : event_id };
        fetch("deleteevent.php", {
            method: 'POST',
            body: JSON.stringify(data_del),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => console.log(data.success ? "edit delete work" : `edit delete fail ${data.message}`))
        .catch(err => console.error(err));

        const data_add = { 'event_month': event_month, 'event_year': event_year, 'event_date': event_date, 'event_name': event_name, 'event_time': event_time, 'event_id': event_id, 'event_tag' : event_tag, 'token': sessionCookie};
        fetch("addeventforedit.php", {
            method: 'POST',
            body: JSON.stringify(data_add),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => console.log(data.success ? "edit add work!" : `edit add fail ${data.message}`))
        .catch(err => console.error(err));
        callEventsAjax(event_month_curr, event_year_curr);

        }

    }

    function fillEventsToday(eventarray) {
        document.getElementById("events_today").innerHTML = "Your Events Today: "
        if (eventarray != null) {
            for (i = 0; i < eventarray.length; i++) {
                let timeleftcol = (Math.ceil(eventarray[i].time/100));
                let modtimeleftcol = (Math.ceil(eventarray[i].time/100) * 100);
                let timerightcol = eventarray[i].time % modtimeleftcol;
                if (timeleftcol < 10) {
                    timeleftcol = "0" + String(timeleftcol);
                }
                if (timerightcol < 10) {
                    timerightcol = "0" + String(timerightcol);
                }
                let todayevent = "Event Name: " + eventarray[i].name + " at " + timeleftcol + ":" + timerightcol + "<br>" +
                "Event ID: " + eventarray[i].id + "<br>" +
                "Tag: " + eventarray[i].tag;
                document.getElementById("events_today").innerHTML = document.getElementById("events_today").innerHTML + "<br>" + todayevent + "<br>";
                if (eventarray[i].tag == "high_priority") {
                    alert("You have a high priority event today!");
                }
            }
        }
        else {
            document.getElementById("events_today").innerHTML = document.getElementById("events_today").innerHTML + "No Events Set For Today!";
        }
    }

    function callEventsTodayAjax() {
        let d = new Date();
        const curr_month = d.getMonth();
        const curr_date = d.getDate();
        const curr_year = d.getFullYear();
        const data = { 'event_month': curr_month, 'event_year': curr_year, 'event_date' : curr_date};

    fetch("calleventstoday.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => {
            let returnData = compileDataToday(data);
            fillEventsToday(returnData);
        })
        .catch(err => console.error(err));
        
    }
//event listeners
document.addEventListener("DOMContentLoaded", function(event){
    $('.login_page').toggle(true);
    $('.dashboard_page').toggle(false);
    fillCalendarDates();
    //overwrite here if needed, console error pops up if logged out, no issues
    fetch("loggedin.php", {
        method: 'POST',
        body: JSON.stringify(),
        headers: { 'content-type': 'application/json' }
    })
    .then(response => response.json())
    .then(function(response) {
        if(response.success) {
            $('.login_page').toggle(false);
            $('.dashboard_page').toggle(true);  
            callEventsAjax(currentMonth.month, currentMonth.year);
            final = true;
        }
    })
}, false);
document.getElementById("next_month_btn").addEventListener("click", function(event){
    currentMonth = currentMonth.nextMonth();
    if (final == false) {
        fillCalendarDates();
    }
    else {
        fetch("loggedin.php", {
            method: 'POST',
            body: JSON.stringify(),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(function(response) {
            if(response.success) {
                callEventsAjax(currentMonth.month, currentMonth.year);  
            } 
        })
    }
}, false);
document.getElementById("prev_month_btn").addEventListener("click", function(event){
    currentMonth = currentMonth.prevMonth();
    if (final == false) {
        fillCalendarDates();
    }
    else {
        fetch("loggedin.php", {
            method: 'POST',
            body: JSON.stringify(),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(function(response) {
            if(response.success) {
                callEventsAjax(currentMonth.month, currentMonth.year);
            }
        }) 
    }
}, false);

//new code for displaying date
let date_time = new Date();
document.getElementById("date_time").innerHTML = "Current date and time: " + date_time;
//end
document.getElementById("addevent").addEventListener("click", addEventAjax, false);
document.getElementById("deleteevent").addEventListener("click", deleteEventAjax, false);
document.getElementById("editevent").addEventListener("click", editEventAjax, false);
document.getElementById("filter_high").addEventListener("click", function(event){callEventsAjaxFiltered(currentMonth.month, currentMonth.year, "high_priority")}, false);
document.getElementById("filter_med").addEventListener("click", function(event){callEventsAjaxFiltered(currentMonth.month, currentMonth.year, "med_priority")}, false);
document.getElementById("filter_low").addEventListener("click", function(event){callEventsAjaxFiltered(currentMonth.month, currentMonth.year, "low_priority")}, false);
document.getElementById("filter_monky").addEventListener("click", function(event){callEventsAjaxFiltered(currentMonth.month, currentMonth.year, "monky_priority")}, false);
document.getElementById("filter_all").addEventListener("click", function(event){callEventsAjax(currentMonth.month, currentMonth.year)}, false);
//document.getElementById("shareevent").addEventListener("click", shareEventAjax, false);
