const express = require('express');
const app = express();
const cors = require("cors");
const port = 3001

app.use(cors());
app.use(express.json());

app.use("/authentication", require("./routes/users"));
app.use("/other", require("./routes/connections"));

app.listen(port, () => {
    console.log(`App running on port ${port}.`)
  })