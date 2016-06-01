#Communication between Arduino
If you want to send data between Arduino boards you can do this following this simple method.

###To do this you'll need:
* Arduino (which send data) with free *PWM* pin (pin marked with '~' symbol)
* Arduino (which read data) with free analog pin (pin starting with A letter)
* few wires
* 1 capacitor
* 1 resistor

###How to make it
####Connecting
You need to connect *PWM* pin in first Arduino to capacitor through resistor. Then connect capacitor to analog pin in second Arduino.

**If resistor or capacitor is too small or too big results will be very inaccurate.**
####Sending data
On first Arduino you need to scale data you want to send, because *PWM* sends 0-5V signal, but you send value from 0 (0V) to 255 (5V).
####Reading data
Then on second Arduino you need to read voltage on analog pin and scale it again, because it reads values from 0 to 1023
(if you divide voltage you got by 8 it'll be ~~the same~~ approximate to the value you sent).
We also advice you to use moving average when reading data, if you'll send data with small diferences.
Simple moving average looks like this:
```Arduino
float newData=lastData*5/10+sensorValue*5/10;
```
Where lastData is data you have recieved earlier and *sensorValue* is the value you just got.

**Remember that it isn't very accurate.**
