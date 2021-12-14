let final = false;
function updateLogin (data) {
    $('.login_page').toggle(!data.success);
    $('.dashboard_page').toggle(data.success);
    final = true;
    callEventsAjax(currentMonth.month, currentMonth.year);
}

function updateLogout (data) {
    $('.login_page').toggle(data.success);
    $('.dashboard_page').toggle(!data.success);
    final = false;
    fillCalendarDates();
}

function loginAjax(event) {
    const username = document.getElementById("username").value; // Get the username from the form
    const password = document.getElementById("password").value; // Get the password from the form

    // Make a URL-encoded string for passing POST data:

    const data = { 'username': username, 'password': password };

    fetch("login.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        // csrfCheck();
        .then(response => response.json())
        .then (data => updateLogin(data))
        .catch(err => console.error(err));
        // csrfCheck();
}
function registerAjax(event) {
    const username = document.getElementById("new_username").value; // Get the username from the form
    const password = document.getElementById("new_password").value; // Get the password from the form

    // Make a URL-encoded string for passing POST data:
    const data = { 'new_username': username, 'new_password': password };

    fetch("register.php", {
            method: 'POST',
            body: JSON.stringify(data),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        .then(data => console.log(data.success ? "You've been registered!" : `You were not registered ${data.message}`))
        .catch(err => console.error(err));
}
function logoutAjax(event) {
    fetch("logout.php", {
            method: 'POST',
            body: JSON.stringify(),
            headers: { 'content-type': 'application/json' }
        })
        .then(response => response.json())
        // .then(data => console.log(data.success ? "You've been logged out!" : `You were not logged out ${data.message}`))
        .then (data => updateLogout(data))
        .catch(err => console.error(err));
}

document.getElementById("login").addEventListener("click", loginAjax, false);
document.getElementById("register").addEventListener("click", registerAjax, false);
document.getElementById("logout").addEventListener("click", logoutAjax, false);
