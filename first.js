var serialPort = require('serialport');
var SerialPort = serialPort.SerialPort;
var number = require('string');// process.argv[2];
const readline = require('readline');

const rl = readline.createInterface({
input: process.stdin,
output: process.stdout
});
var myPort = new SerialPort('COM3',{
  baudRate: 9600,
  parser:serialPort.parsers.readline("\n")

});

myPort.on('open',onOpen);
myPort.on('data',onData);


function onOpen(){
  console.log("open");
}

function onData(data){
  console.log("data is:"+ " " + data);
  rl.on('line',(number) =>{
  // console.log(`The number is entered`);
  myPort.write(number);
  });
   
}




