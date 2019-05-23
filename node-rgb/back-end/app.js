const SerialPort = require("serialport");
const portName = "/dev/cu.usbmodem146201";
const Readline = require("@serialport/parser-readline");
const express = require("express");
const app = express();

port = new SerialPort(portName, {
  baudRate: 9600
});

const parser = port.pipe(new Readline({ delimiter: "\r\n" }));

port.on("open", function() {
  console.log("open serial communication");
  parser.on("data", console.log);
  // (async () => {
  //   for (;;) {
  //     port.write(`240R17G17B`);
  //     await delay(1000);
  //     port.write(`17R252G94B`);
  //     await delay(1000);
  //     port.write(`244R17G252B`);
  //     await delay(1000);
  //   }
  // })();
});

app.get("/change/:r/:g/:b", function(req, res) {
  const { r, g, b } = req.params;
  port.write(`${r}R${g}G${b}B`);
  res.send("ok");
});

app.listen(9999);
