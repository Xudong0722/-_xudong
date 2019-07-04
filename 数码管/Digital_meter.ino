void setup()
{
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  Serial.begin(9600);
  
}
int income;
void loop()
{
  //digitalWrite(13, HIGH);
 // delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(13, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  if(Serial.available()>0)
  {
    income = Serial.read()-'0';
    if(income&1==1)
      digitalWrite(2,HIGH);
    if(income>>1&1==1)
      digitalWrite(3, HIGH);
    if(income>>2&1==1)
      digitalWrite(4, HIGH);
    if(income>>3&1==1)
      digitalWrite(5,HIGH);
    
    digitalWrite(6, HIGH);
    delay(1000);
  }
}
