#define USE_ARDUINO_INTERRUPTS true    
#include <PulseSensorPlayground.h>     

//  Variables
const int PulseWire = 0;       
const int LED13 = 15;          
int Threshold = 480;           
                           
                                                             
PulseSensorPlayground pulseSensor;  
int nImpulse = 0;
float bike_monitor = 4.5;
int heart_monitor;
float km_monitor;
int nSeconds;
float speed_monitor;
float nCalorie;
int co2;
float battery=100;
void setup() {   
Serial.begin(9600);         

  
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       
  pulseSensor.setThreshold(Threshold);   

}
void loop() {

  int myBPM = pulseSensor.getBeatsPerMinute();  

                                              
  co2 = analogRead(A0);
  
  Serial.println(co2);
 
  
  if (pulseSensor.sawStartOfBeat()) {          
   Serial.println(myBPM);  
   
  } else {                       
    Serial.println(random(90,110));
  }
  

  heart_monitor = nImpulse * bike_monitor;
  km_monitor = heart_monitor/1000.0;
 
  speed_monitor = km_monitor * 3600 / nSeconds;
  nCalorie = nImpulse/12.0;
  
  nSeconds = millis() / 1000;
  nImpulse++;
  int sensorvalue=analogRead(A0);
  float voltage=sensorvalue*(5.0/1023);
  battery = battery -(nSeconds*0.01);
  Serial.println(speed_monitor);
  Serial.println(nCalorie);
  Serial.println(voltage);
  Serial.println(battery);
  delay(600);

}
