 /*
  *Stepper sketch for linear actuator
  *Arduino UNO R3
  *TB6600 Stepper Driver set to 1/8 micro-step
  *NEMA17 motor 2amp, 86oz/cm
  */
 
int dirpin = 12; // lines 8-10 establish arduino pins that control stepper driver
int steppin = 13;
int enable = 11; 

int del = 300;   //Delay integer to set motor speed, lower is faster (400 default)
int len = 16000; //Length of actuator travel 
 
void setup()  
{ 
  pinMode(dirpin, OUTPUT); 
  pinMode(steppin, OUTPUT);
  digitalWrite(enable, HIGH);
}

void loop() 
{
int i;
digitalWrite(dirpin, HIGH);           // Set direction
delay(100);   
  for (i = 0; i<len; i++)             // Iterate for (len) microsteps   
      {     
        digitalWrite(steppin, LOW);   // This LOW to HIGH change is what creates the motor step 
        delayMicroseconds(del);       // Motor speed
        digitalWrite(steppin, HIGH);      
        delayMicroseconds(del);       // Motor speed
      }                              
   
digitalWrite(dirpin, LOW);            // Change direction.   
delay(100);   
  for (i = 0; i<len; i++)             // Iterate for (len) microsteps   
      {     
        digitalWrite(steppin, LOW);      
        delayMicroseconds(del);       // Motor speed
        digitalWrite(steppin, HIGH);      
        delayMicroseconds(del);       // Motor speed   
      } 
 
} 
