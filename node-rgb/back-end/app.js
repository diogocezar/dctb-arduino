const SerialPort = require("serialport");
const portName = "/dev/cu.usbmodem146301";
const Readline = require("@serialport/parser-readline");
const express = require("express");
const app = express();
const cors = require("cors");

try {
  port = new SerialPort(portName, {
    baudRate: 9600
  });

  const parser = port.pipe(new Readline({ delimiter: "\r\n" }));

  port.on("open", function() {
    parser.on("data", console.log);
  });
} catch (err) {
  console.log("Error on serial communication.");
}

app.use(cors());

app.get("/change/:r/:g/:b", function(req, res) {
  const { r, g, b } = req.params;
  port.write(`${r}R${g}G${b}B`);
  res.status(200).json({ success: true });
});

app.listen(9999);
