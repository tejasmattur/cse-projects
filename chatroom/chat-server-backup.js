// Require the packages we will use:
const http = require("http"),
    fs = require("fs");

const port = 3456;
const file = "client.html";
// Listen for HTTP connections.  This is essentially a miniature static file server that only serves our one file, client.html, on port 3456:
const server = http.createServer(function (req, res) {
    // This callback runs when a new connection is made to our HTTP server.

    fs.readFile(file, function (err, data) {
        // This callback runs when the client.html file has been read from the filesystem.

        if (err) return res.writeHead(500);
        res.writeHead(200);
        res.end(data);
    });
});
server.listen(port);


//setup

let users = {}; //key: username, value: socket.id
let rooms = {"Lobby": undefined}; // key: room name, value: room creator
let locations = {}; // key: user, value: room
let room_passwords = {"Lobby": ""}; //key: room name, value: password. When password = "", public room
let banned_users = {}; //key: room, value: set() of banned users

// Import Socket.IO and pass our HTTP server object to it.
const socketio = require("socket.io")(server, {
    wsEngine: 'ws'
});


// Attach our Socket.IO server to our HTTP server to listen
const io = socketio.listen(server);
io.sockets.on("connection", function (socket) {
    
    // This callback runs when a new Socket.IO connection is established.

    socket.on('add_user', function (data) {
        // This callback runs when the server receives a new message from the client.

        //if user in users, drop socket.id val from dict and add new one
        let new_user = data["user"];
        users[new_user] = socket.id;
        //below here same
        socket.user = new_user;
        socket.room = "Lobby";
        socket.join(socket.room);
        locations[data["user"]] = "Lobby";
        io.to(socket.room).emit("login_update", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms, user:socket.user});
        io.to(socket.room).emit("display_rooms", {rooms_keys:Object.keys(rooms), passwords:Object.values(room_passwords)});
        io.sockets.emit("display_users", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
    });

    socket.on('create_room', function (data) {
        // This callback runs when the server receives a new message from the client.
        rooms[data["room"]] = data["user"];
        locations[data["user"]] = data["room"];
        room_passwords[data["room"]] = data["password"]; 
        socket.room = data["room"];//in to room
        socket.leave("Lobby");
        socket.join(socket.room);
        io.to(socket.room).emit("room_joined", {rooms_keys: Object.keys(rooms), room: socket.room, locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
        io.sockets.emit("display_rooms", {rooms_keys:Object.keys(rooms), passwords:Object.values(room_passwords)});
        io.sockets.emit("display_users", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
    });

    socket.on('join_room', function (data) {
        // This callback runs when the server receives a new message from the client.
        if ((data["room"] in banned_users) && (banned_users[data["room"]].includes(data["user"]))) {
                locations[data["user"]] = "Lobby";
                socket.room = "Lobby";
                // socket.leave("Lobby");
                // socket.join(socket.room);
                // io.to(socket.room).emit("room_joined",{rooms_keys: Object.keys(rooms), room: socket.room, locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
                io.to(socket.room).emit("room_left",{room: "Lobby", rooms_keys:Object.keys(rooms), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
                io.to(socket.room).emit("message_to_client", {message: "You are banned from this room!", user:data["user"]});
        }
        else {
                locations[data["user"]] = data["room"];
                socket.room = data["room"];
                socket.leave("Lobby");
                socket.join(socket.room);
                io.to(socket.room).emit("room_joined",{rooms_keys: Object.keys(rooms), room: socket.room, locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
                io.sockets.emit("display_users", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
            }
        
    });

    socket.on('leave_room', function (data) {
        // This callback runs when the server receives a new message from the client.
        locations[data["user"]] = "Lobby";
        socket.room = "Lobby";
        socket.leave(data["room"]);
        socket.join(socket.room);
        io.to(socket.room).emit("room_left",{room: "Lobby", rooms_keys:Object.keys(rooms), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
        io.sockets.emit("display_users", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
    });


    socket.on('delete_room', function (data) {
        let del_room = data["room"];
        let potential_admin = data["user"];
        for (let x of Object.keys(rooms)) {
            if (del_room == Object.keys(x)) { // if the room name = x name
                if (rooms[x] == potential_admin) { // if username = x value (username) //idfk
                    let verify = prompt("Are you sure you'd like to delete this room?", "Yes");
                    if (verify == "Yes") {
                        //locations[potential_admin] = "Lobby";
                        // for (y in locations) {
                        //     if (Object.values(y) == "del_room") { //should move all users back to lobby?
                        //         locations[Object.keys(y)] = "Lobby"; //leave room????
                        //     }
                        // }
                        for (let y of Object.keys(locations)) {
                            if (locations[y] == del_room) {
                                locations[y] = "Lobby";
                                let temp_socket_id = users[y];
                                let temp_socket = io.sockets.sockets.get(temp_socket_id);
                                temp_socket.leave(del_room);
                                temp_socket.room = "Lobby";
                                temp_socket.join(temp_socket.room);
                                io.to(temp_socket_id).emit("room_left",{rooms_keys: Object.keys(rooms), room: "Lobby", locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
                            }
                        }
                        rooms.delete("del_room");
                        room_passwords.delete("del_room");
                        //alert("This Room Was Deleted!"); //only alerts to user, need an alert to all users
                        locations[data["user"]] = "Lobby";

                        //problem with this line
                        io.to(socket.id).emit("room_left",{rooms_keys: Object.keys(rooms), room: "Lobby", locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
                        //sockets....

                        // io.sockets.emit("display_rooms", {rooms_keys:Object.keys(rooms), passwords:Object.values(room_passwords)});
                    }
                    else {
                        //alert("Room Not Deleted");
                        io.to(users[potential_admin]).emit("message_to_client", {message: "Not Deleted! For No Verify", user:potential_admin})
                    }
                }
            }
            else {
                io.to(users[potential_admin]).emit("message_to_client", {message: "Not Deleted! For No Admin", user:potential_admin})
                //alert("You are not the admin!");
                //do nothing else?? how
            }
        }
        //io.sockets.emit("room_joined",{rooms_keys: Object.keys(rooms), room: data["room"], locations_keys: Object.keys(locations), locations: locations, rooms: rooms, room_passwords: room_passwords, passwords_keys: Object.keys(room_passwords)});
        io.sockets.emit("display_rooms", {rooms_keys:Object.keys(rooms), passwords:Object.values(room_passwords)});
        // io.sockets.emit("display_users", {rooms_keys:Object.keys(rooms), users: Object.keys(users), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});

    });

    socket.on("ban_user", function(data){ 
        let banning_user = data["banning_user"];
        let banned_user = data["banned_user"];
        let room = data["room"];
        let banned_id = users[banned_user];
        let banned_socket = io.sockets.sockets.get(banned_id);
        //2 conditions: banning user is admin, banned user exists, banned user is in room (2 might be trivially included in 3)
        if (rooms[room] == banning_user) {
            if (room in banned_users) {
                banned_users[room].push(banned_user); //adds banned user to set of banned users under room key
            }
            else {
                banned_users[room] = new Array(); //no banned users yet, creates new set for key
                banned_users[room].push(banned_user); //adds banned user to set
            }
            if (locations[banned_user] == room) {
                locations[banned_user] = "Lobby"; //would like kick function here
                banned_socket.room = "Lobby";
                banned_socket.leave(room);
                banned_socket.join(banned_socket.room);
                io.to(banned_id).emit("room_left", {room: "Lobby", rooms_keys:Object.keys(rooms), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
            }

            //sockets again
            io.sockets.emit("user_banned", {rooms:rooms, locations:locations, users:users, room_passwords:room_passwords, banned_users:banned_users});
            //fuck me

            let msg = "You have been banned from " + room;
            io.to(banned_id).emit("message_to_client", { message: msg, user: data["banning_user"]});
        }
        else {
            io.sockets.emit("message_to_client", {message: "You cannot ban this user!", user:banning_user, room:room});
        }
    });

    socket.on('kick_user', function(data){
        let kicking_user = data["kicking_user"];
        let kicked_user = data["kicked_user"];
        let room = data["room"];
        let kicked_id = users[kicked_user];
        let kicked_socket = io.sockets.sockets.get(kicked_id);
        if (rooms[room] == kicking_user) {
            if (locations[kicked_user] == room) {
                locations[kicked_user] = "Lobby"; //would like kick function here
                kicked_socket.room = "Lobby";
                kicked_socket.leave(room);        
                kicked_socket.join(kicked_socket.room);
                io.to(kicked_id).emit("room_left", {room: "Lobby", rooms_keys:Object.keys(rooms), locations:locations, locations_keys: Object.keys(locations), rooms:rooms});
                let msg = "You have been kicked from " + room;
                io.to(kicked_id).emit("message_to_client", { message: msg, user: data["kicking_user"]});    
            }
            // io.sockets.emit("user_kicked", {rooms:rooms, locations:locations, users:users, room_passwords:room_passwords, banned_users:banned_users});
        }
        else {
            io.to(users[kicking_user]).emit("message_to_client", {message: "You cannot kick this user!", user:kicking_user, room:room});
        }
    });


    // socket.on('get_kicked', function (data) {
    //     socket.leave(data["room"]);
    //     socket.room = "Lobby";
    //     socket.join(socket.room);
    // });

    socket.on('message_to_server', function (data) {
        // This callback runs when the server receives a new message from the client.
        console.log("message: " + data["message"]); // log it to the Node.JS output
        socket.room = data["room"];
        socket.join(socket.room);
        io.to(socket.room).emit("message_to_client", { message: data["message"], user:data["user"], room: socket.room}) // broadcast the message to other users
    });

    socket.on('private_message_to_server', function(data) {
        let target = data["target_user"];
        to_id = users[target];
        msg = data["message"];
        msg = "(private message) " + msg;
        io.to(to_id).emit("message_to_client", { message: msg, user: data["from_user"]});
    });
});
