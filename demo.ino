// Lib
#include <Servo.h>

Servo Base;
Servo Tour;
const byte Base_pin = 6;
const byte Tour_pin = 9;
int Base_pos = 90;
int Tour_pos = 35;



void setup() {
    Base.attach(Base_pin);
    Tour.attach(Tour_pin);

    Base.write(Base_pos);
    Tour.write(Tour_pos);
    
    delay(1000);
}



void loop() {
    // base turn full left
    for (Base_pos = 90; Base_pos <= 140; Base_pos += 1) { 
        Base.write(Base_pos);
        delay(200);
    }

    // tourelle  up
    for (Tour_pos = 35; Tour_pos <= 40; Tour_pos += 1) { 
        Tour.write(Tour_pos);
        delay(200);
    }

    // base turn full right
    for (Base_pos = 140; Base_pos >= 40; Base_pos -= 1) { 
        Base.write(Base_pos);
        delay(200);
    }

    // tourelle down
    for (Tour_pos = 40; Tour_pos >= 30; Tour_pos -= 1) { 
        Tour.write(Tour_pos);
        delay(200);
    }

    // reset to default 
    //  base 
    for (Base_pos = 40; Base_pos <= 90; Base_pos += 1) { 
        Base.write(Base_pos);
        delay(150);
    }
    //  tour
    for (Tour_pos = 30; Tour_pos <= 50; Tour_pos += 1) { 
        Tour.write(Tour_pos);
        delay(150);
    }
    
    delay(2000);
}
