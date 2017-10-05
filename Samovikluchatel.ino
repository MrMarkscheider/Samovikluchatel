#include <Stepper.h>

  Stepper motor(400, 10, 12, 11, 13);  // объект motor, 400 шагов на оборот 

void setup() {
  motor.setSpeed(60);  // скорость 60 об. в мин.
}

void loop() {  
  motor.step(240);  // 5 оборотов (240 шагов) по часовой стрелке
  delay(1000);
  motor.step(-240);  // 5 оборотов (240 шагов) против часовой стрелке
  delay(1000);  
}
