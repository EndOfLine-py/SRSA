// Lib
#include <Servo.h>


Servo Base;
Servo Tour;
const byte Base_pin = 6;
const byte Tour_pin = 9;
int Base_pos = 90;
int Tour_pos = 35;


// setup crazy
void setup() {
    Base.attach(Base_pin);
    Tour.attach(Tour_pin);
}

void loop() {
    Base.write(Base_pos);
    Tour.write(Tour_pos);

    delay(1000);
}
