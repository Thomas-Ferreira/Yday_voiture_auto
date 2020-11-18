#include "motor.h"
#include <HCSR04.h>

#define enb 5
#define in4 6
#define in3 7
#define in2 8
#define in1 9
#define ena 10

motor m(in1, in2, in3, in4, enb, ena);

HCSR04 hc(A0,A1);

void setup() 
{
Serial.begin(9600);
}

void loop() {
  double distance=hc.dist();
  Serial.print(distance);
  Serial.print(" ");
  if( distance < 50.0)
  {
    Serial.println("d");
    m.reculer();
    delay(100);
    m.droite();
    delay(100);
  }
  else
  {
    Serial.println("a");
    m.avancer();
  }
}
