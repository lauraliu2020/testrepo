
const int TrigPin = 2;
const int EchoPin = 3;


float cm;
void setup()
{
Serial.begin(9600);
pinMode(TrigPin, OUTPUT);
pinMode(EchoPin, INPUT);
}
void loop()
{
digitalWrite(TrigPin, LOW);       
delayMicroseconds(4);

//delay and hold pin high for 10 microseconds
digitalWrite(TrigPin, HIGH);
delayMicroseconds(10);
digitalWrite(TrigPin, LOW);

//The echo time is converted into cm
cm = pulseIn(EchoPin, HIGH) / 58.0; 

//Keep two decimal places for the showing distance
cm = (int(cm * 100.0)) / 100.0;  
  
//send results to serial monitor
Serial.print("Distance\t=\t"); 
Serial.print(cm);
Serial.print("cm");
Serial.println();
delay(1500);
}
