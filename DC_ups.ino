int batteryvoltage = A0;
int solarvoltage = A1;
int wapdavoltage = A2;
float vout = 0.0;
float vin = 0.0;
const int L1 = 13;
const int L2 = 12;
const int L3 = 11;

int value = 0;
int solarV = 0;
float R1 = 100000.0; // resistance of R1 (100K) -see text!
float R2 = 2700.0; // resistance of R2 (10K) - see text!
void setup(){
  pinMode(L1,OUTPUT);

  pinMode(L3,OUTPUT);
//  digitalWrite(L1,HIGH);
  
   Serial.begin(9600);
  
}
void loop(){
   // read the value at analog input

  float readbattery = measurebattery();

  float readsolar = measuresolar();
 
  float readwapda = measurewapda();

if(readbattery <= 6) //volts
{
  if(readsolar >= 13 && readwapda >= 13)
  {
    
     digitalWrite(L1,LOW);
     digitalWrite(L3,LOW);
  }
  if(readsolar <= 13 && readwapda >= 13)
  {
    digitalWrite(L1,HIGH);
   
     digitalWrite(L3,LOW);
  }
  if(readwapda <= 1 )
  {
    
        digitalWrite(L1,LOW);
        digitalWrite(L3,LOW);
  }

}
else
 {
  digitalWrite(L1,LOW);
    
     digitalWrite(L3,HIGH);
     
 }
delay(2000);
}

float measurebattery()
{
   value = analogRead(batteryvoltage);
   vin = (value * 4.965) / 1023.0; // see text
   vout = vin / (R2/(R1+R2)); 
    Serial.print("battery Voltage level=");
Serial.println(vout);
   return vout;

}

float measuresolar()
{
  
 solarV = analogRead(solarvoltage);
    float solarVIN= (solarV * 4.97) / 1023.0; // see text
   float solarVOUT = solarVIN / (R2/(R1+R2));
   Serial.print("solar Voltage level=");
Serial.println(solarVOUT);
   return solarVOUT; 


}

float measurewapda()
{
  
  int wapdaV=analogRead(wapdavoltage);
  float wapdaVIN=(wapdaV * 4.98) / 1023.0;
  float wapdaVOUT=wapdaVIN / (R2/(R1+R2));
  Serial.print("wapda voltage level =");
Serial.println(wapdaVOUT); 
  return wapdaVOUT;

}
