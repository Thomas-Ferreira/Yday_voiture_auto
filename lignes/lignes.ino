#include "motor.h"

//#define DEBUGSERAIl

#define enb 5
#define in4 6
#define in3 7
#define in2 8
#define in1 9
#define ena 10


#define left A2
#define right A3

motor m(in1, in2, in3, in4, enb, ena);

void setup() 
{
Serial.begin(9600);
pinMode(left, INPUT);
pinMode(right, INPUT);
}

void loop() {
  bool c_left = digitalRead(left), c_right =digitalRead(right);
  //#ifdef DEBUGSERAIl
  Serial.print(c_left);
  Serial.print("  ");
  Serial.println(c_right);
  //#endif
  if (!c_left && ! c_right)
  {
    m.avancer();
  }
   else if (c_left && c_right)
  {
    m.arret();
  }
  else
  {
    m.vitesse = 95;
     if ( c_right)
     {
       m.gauche();
     }
     else if ( c_left){
       m.droite();
  }
  m.vitesse = 155;
  }
  
}
