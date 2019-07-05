class Morse
{
public:
Morse(int pin);
void dot();
void dash();
void c_space();
void w_space();
private:
int _pin;
};

#include "Arduino.h"
Morse::Morse(int pin)
{
pinMode(pin, OUTPUT);
_pin = pin;
}
void Morse::dot()
{
digitalWrite(_pin, HIGH);
delay(250);
digitalWrite(_pin, LOW);
delay(250);
}
void Morse::dash()
{
digitalWrite(_pin, HIGH);
delay(1000);
digitalWrite(_pin, LOW);
delay(250);
}
void Morse::c_space()
{
	digitalWrite(_pin,LOW);
	delay(250*3);
}
void Morse::w_space()
{
	digitalWrite(_pin,LOW);
	delay(250*7);
}

void setup(){
  Serial.begin(9600);  //设置通信波特率
}
Morse morse(5);
void loop(){
  String str = "";
  String tmp = "";
  bool flag = false;  //标记串口是否有数据输入
  int count = 0;
  while(Serial.available()>0)
  {
    flag = true;
    str += char (Serial.read());
    delay(100);
    count++;
  }
  
  if(flag)
  {
     for(int i = 0;i<count;i++)
     {
       switch(str[i]-97)
       {
        case 1:tmp += ".-";break;
        case 2:tmp += "-...";break;
        case 3:tmp += "-.-.";break;
        case 4:tmp += "-..";break;
        case 5:tmp += ".";break;
        case 6:tmp += "..-.";break;
        case 7:tmp += "--.";break;
        case 8:tmp += "....";break;
        case 9:tmp += "..";break;
        case 10:tmp += ".---";break;
        case 11:tmp += "-.-";break;
        case 12:tmp += ".-..";break;
        case 13:tmp += "--";break;
        case 14:tmp += "-.";break;
        case 15:tmp += "---";break;
        case 16:tmp += ".--.";break;
        case 17:tmp += "--.-";break;
        case 18:tmp += ".-.";break;
        case 19:tmp += "...";break;
        case 20:tmp += "-";break;
        case 21:tmp += "..-";break;
        case 22:tmp += "...-";break;
        case 23:tmp += ".-- ";break;
        case 24:tmp += "-..-";break;
        case 25:tmp += "-.--";break;
		case 26:tmp += "--..";break;
       }
     }
    Serial.print(tmp);
       for(int i = 0;i<tmp.length()-1;i++)
       {
			if(tmp[i]=='.')
              morse.dot();
         	if(tmp[i]=='-')
              morse.dash();
       }
    morse.c_space();
    delay(100);
  }
}
  
