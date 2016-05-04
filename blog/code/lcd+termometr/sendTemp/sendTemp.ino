#include <DallasTemperature.h>
#include <OneWire.h>

#define ONE_WIRE_BUS 2
#define writePin 11 //pin on with we set voltage
int value=0;
// Setup a oneWire instance to communicate with any OneWire devices 
// (not just Maxim/Dallas temperature ICs)
OneWire oneWire(ONE_WIRE_BUS);
 
// Pass our oneWire reference to Dallas Temperature.
DallasTemperature sensors(&oneWire);
 
void setup(void)
{
  // start serial port
  Serial.begin(9600);
  pinMode(1,OUTPUT);//setup for ds18
  pinMode(3,OUTPUT);
  digitalWrite(1,LOW);
    digitalWrite(3,LOW);
  //Serial.println("Dallas Temperature IC Control Library Demo");

  // Start up the library
  sensors.begin(); //OneWire setup
 // Serial.println( sensors.getResolution());

}
 
 
void loop(void){

  sensors.requestTemperatures(); // Send the command to get temperatures
float x=sensors.getTempCByIndex(0); // read temp 

 crateDataToSend(x);//change temp into value
 writeData();
}
void writeData(){
  analogWrite(writePin,value); //set voltage
   delay(500);
}
void crateDataToSend(float recivedData){
   int valueToSend=(recivedData-18)*2*5;//change temp into value do send
   Serial.println(recivedData);
  Serial.println(valueToSend);
   value=valueToSend;//save to global
 
  
}
