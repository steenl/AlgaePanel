byte pump1 = 7;
byte pump2 = 10;
int tempPIN = A0;
boolean InPanel = false; 

void pumpToResevoir() {
  digitalWrite(pump1, HIGH); // turn pump1 on
  digitalWrite(pump2, LOW); // turn off pump2
  delay(5000);
  InPanel = false;
}

void pumpToPanel() {
  digitalWrite(pump1, LOW); // turn pump1 off
  digitalWrite(pump2, HIGH); // turn pump2 on
  delay(5000);
  InPanel = true;
}

void sleep(int seconds) {
  //sleep
}

float temperatureRead() {
  /* 
   * check temperature
   * code is for temperature sensor LM35
   * possibly add an LED screen showing the current temperature
   */
   int val = analogRead(tempPIN); // read from sensor and save to val
                            
   float milliVolt = val*(5000.0/1024.0);         // convert ADC value to millivolt
   float tempC = milliVolt/10;                    // Convert millivolt to Celsius
   float tempF = (tempC * 1.8) + 32.0;            // Convert Celcius to Fahrenheit

   return tempF;
}

void setup() {
   Serial.begin(9600);
   pinMode(pump1, OUTPUT); // set pump1 (pin 7) as output
   pinMode(pump2, OUTPUT); // set pump2 (pin 10) as output
}

void loop() {
   // read the current temp
   float tempF = temperatureRead();
   
   // check if temp in resevoir is too hot or cold -> pump to resevoir
   if ((tempF < 60) or (tempF > 80)) {
     pumpToResevoir();
   }
   
   // if within range leave in panel or pump into panel from resevoir
   else {
     if (InPanel = false) {
       pumpToPanel();
     }
   }
   
   //Arduino sleep for 1 hour = 3600000 milliseconds
   sleep(3600000);
}
