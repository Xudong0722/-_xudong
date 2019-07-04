void forward()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
}
void backward()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
}
void left()
{
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(10,HIGH);
  digitalWrite(9,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);  
}
void right()
{
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(9,HIGH);
  digitalWrite(10,LOW);
  digitalWrite(11,HIGH);
  digitalWrite(12,LOW);
}
void stop()
{
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(9,LOW);
  digitalWrite(10,LOW);
}

void setup()
{
  pinMode(5, OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  Serial.begin(9600);//波特通信率
}
int income;
void loop()
{
  //digitalWrite(13, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(13, LOW);
  //delay(1000); // Wait for 1000 millisecond(s)
  if(Serial.available()>0)
  {
    income = Serial.available();
    switch(income)
    {
      case 'b':
      	backward();break;
      case 'f':
      	forward();break;
      case 'l':
      	left();break;
      case 'r':
      	right();break;
      case 's':
      	stop();break;
      default:break;
    }
  }
}

