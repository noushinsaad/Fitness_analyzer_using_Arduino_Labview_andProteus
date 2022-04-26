#define USE_ARDUINO_INTERRUPTS true    
#include <TimerOne.h>    



int HBSensor = 4;
int HBCount = 0;
int HBCheck = 0;
int TimeinSec = 0;
int HBperMin = 0;
int HBStart = 2;
int HBStartCheck = 0;


                           
                                                             
 
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

  


  pinMode(HBSensor, INPUT);
  pinMode(HBStart, INPUT_PULLUP);
  Timer1.initialize(800000); 
  Timer1.attachInterrupt( timerIsr );   

}
void loop() {



  co2 = analogRead(A0);
  
  Serial.println(co2);
  if(digitalRead(HBStart) == LOW){
    HBStartCheck = 1;
    } 
  
  if(HBStartCheck == 1)
  {
      if((digitalRead(HBSensor) == HIGH) && (HBCheck == 0))
      {
        HBCount = HBCount + 1;
        HBCheck = 1;

        //Serial.print("BPM");
        //Serial.println(HBCount);
        
      }
      if((digitalRead(HBSensor) == LOW) && (HBCheck == 1))
      {
        HBCheck = 0;   
      }
      if(TimeinSec == 10)
      {
          HBperMin = HBCount * 12;
          HBStartCheck = 0;

          
          Serial.println(HBperMin);
          
          
          
          HBCount = 0;
          TimeinSec = 0;      
      }
      else{
        Serial.println("N/A");
        }
  }



                                              
  
 
  

  

  heart_monitor = nImpulse * bike_monitor;
  km_monitor = heart_monitor/1000.0;
 
  speed_monitor = km_monitor * 3600 / nSeconds;
  nCalorie = nImpulse/12.0;
  
  nSeconds = millis() / 1000;
  nImpulse++;
 
  float voltage=co2*(5.0/1023);
  battery = battery -(nSeconds*0.01);
  Serial.println(speed_monitor);
  Serial.println(nCalorie);
  Serial.println(voltage);
  Serial.println(battery);
  delay(500);

}


void timerIsr()
{
  if(HBStartCheck == 1)
  {
      TimeinSec = TimeinSec + 1;
      
      
  }
}
