#include <Stepper.h>

Stepper motor(400, 10, 12, 11, 13);  // объект motor, 400 шагов на оборот

#define PIN_IN_SWITCH_LEFT    5
#define PIN_IN_SWITCH_RIGHT   6

uint16_t max_position;
uint16_t cur_position;

void set_position(uint16_t invalue) {
  uint16_t new_position;


  if (invalue > max_position)
    new_position = max_position;
  else
    new_position = invalue;

  if (new_position > cur_position)
  {
    while ((cur_position < new_position) && digitalRead(PIN_IN_SWITCH_RIGHT))  {
      motor.step(1);
      cur_position++;
    }
    if (cur_position != new_position) cur_position = max_position;
  } else {
    while ((cur_position > new_position) && digitalRead(PIN_IN_SWITCH_LEFT))  {
      motor.step(-1);
      cur_position--;
    }
    if (cur_position != new_position) cur_position = 0;
  }
}

void setup() {
  motor.setSpeed(60);  // скорость 60 об. в мин.

  while (digitalRead(PIN_IN_SWITCH_LEFT)) motor.step(-1);
  cur_position = 0;

  while (digitalRead(PIN_IN_SWITCH_RIGHT)) {
    motor.step(1);
    cur_position++;
  }
  max_position = cur_position;
}

void loop() {

}
