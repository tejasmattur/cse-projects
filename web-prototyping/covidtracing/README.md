## COVID tracing application ##
Created By Justin Neff and Tejas Mattur

Overview: A COVID multitool application. Alerts users and advises them to get tested if daily symptom log indicates that they have a potential COVID infection.  Users are able to run a COVID-tracing function that alerts user if any contact with a COVID-positive user was made to the tertiary level (e.g. A-D is a tertiary contact if: A-B, B-C, C-D, are primary contacts) and outputs a "size of network" color (described below, essentially a warning system of the range of contact). A few other useful features were added as seen below. Essentially, we envisioned this being a tool that universities could use. If every student inputted connections and symptoms daily, the university could easily customize their COVID approach based on their observed data, and students could act more knowledgeably and safely.



Functionalities:

* Users are notified if they exposed to a COVID-positive user with direct, secondary, and tertiary contact tracing.

* Users can register, login, and logout.

* Users can log daily symptoms and latest COVID test result.

* If symptoms indicate a potential covid positive cases, users are alerted to get tested and update their latest COVID test result.

* Users can input/edit/delete other users they’ve seen from day to day.

* Users are notified if their network of individuals up to the tertiary level exceeds a safety threshold—alert level. For example, 0-20 contact traced exposures day = yellow, 20-40 = orange, 40+ = red. 

* Database created that contains Users, COVID Status, Daily Symptoms, Active Contacts (within two weeks), COVID-Positive Tracing Standing (None, Direct, Secondary, Tertiary, etc), etc. 

* "Check User Safety" button, which upon input of any user within the network tabulated in our app, will check the COVID-status of said user as well as determine their network safety and display this information on the page. This could be useful to run before seing a user. 

* "Risk" attribute that assigns to every user, based off of two components: the logged symptoms by a user as well as their COVID network status that is determined after contact tracing is applied. For example, a user's risk will be elevated if contact tracing determines that they have a connection to a COVID-positive user.

Justin Neff
LinkedIn: https://www.linkedin.com/in/justinneff5/
GitHub: https://github.com/justinneff5
