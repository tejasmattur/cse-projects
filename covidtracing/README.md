## COVID tracing application ##
Created By Justin Neff and Tejas Mattur

* Users are notified if they exposed to a COVID-positive user with direct, secondary, and tertiary contact tracing.

* Users can register, login, and logout

* Users can log daily symptoms and latest COVID test result

* If symptoms indicate a potential covid positive cases, users are alerted to get tested and update their latest COVID test result

* Users can input/edit/delete other users they’ve seen from day to day

* Users are notified if their network of individuals up to the tertiary level exceeds a safety threshold—alert level. For example, 0-20 contact traced exposures day = yellow, 20-40 = orange, 40+ = red. 

* Database created that contains Users, COVID Status, Daily Symptoms, Active Contacts (within two weeks), COVID-Positive Tracing Standing (None, Direct, Secondary, Tertiary, etc), etc. 

* We added a "Check User Safety" button, which upon input of any user within the network tabulated in our app, will check the COVID-status of said user as well as determine their network safety and display this information on the page. This could be useful to run before seing a user. 

* We created a "Risk" attribute that assigns to every user that's based off of two components: the logged symptoms by a user as well as their COVID network status that is determined after contact tracing is applied. For example, a user's risk will be elevated if contact tracing determines that they have a connection to a COVID-positive user.
