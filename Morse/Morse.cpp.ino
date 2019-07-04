#include <Morse.h>
Morse morse(13);
 
void setup()
{
  Serial.begin(9600);   //波特率
}

//*-** *---****
void loop()
{
  char str[] = "";
  char* tmp;
  while(Serial.available()>0)  //判断串口是否有数据读入
  {
    strcpy(str,(Serial.read()));
  }
  if(strlen(str)!=0)
  {
    for(int i = 0;i<strlen(str);i++)
    {
      if(str[i]==" ")
        continue;
      
      switch(str[i]-96)
      {
        case 1:tmp = ".-  ";break;
        case 2:tmp = "-...";break;
        case 3:tmp = "-.-.";break;
        case 4:tmp = "-.. ";break;
        case 5:tmp = ".   ";break;
        case 6:tmp = "..-.";break;
        case 7:tmp = "--. ";break;
        case 8:tmp = "....";break;
        case 9:tmp = "..  ";break;
        case 10:tmp = ".---";break;
        case 11:tmp = "-.- ";break;
        case 12:tmp = ".-..";break;
        case 13:tmp = "--  ";break;
        case 14:tmp = "-.  ";break;
        case 15:tmp = "--- ";break;
        case 16:tmp = ".--.";break;
        case 17:tmp = "--.-";break;
        case 18:tmp = ".-. ";break;
        case 19:tmp = "... ";break;
        case 20:tmp = "-   ";break;
        case 21:tmp = "..- ";break;
        case 22:tmp = "...-";break;
        case 23:tmp = ".-- ";break;
        case 24:tmp = "-..-";break;
        case 25:tmp = "-.--";break;
        case 26:tmp = "--..";break;
  }
  for(int i = 0;i<4;i++)
  {
    if(tmp[i] == '.')
      morse.dot();
    if(tmp[i] == '-')
      morse.dash();
  }
  morse.c_space();
}
  }
}
