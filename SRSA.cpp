// Lib
#include <Servo.h>

/*
┌─────────────┐
│ LDR1 │ LDR2 │
│ ─────┼───── │
│ LDR3 │ LDR4 │
└─────────────┘
*/

// pins
const byte LDR1_pin = 0;
const byte LDR2_pin = 0;
const byte LDR3_pin = 0;
const byte LDR4_pin = 0;
// valeurs
int LDR1_val;
int LDR2_val;
int LDR3_val;
int LDR4_val;
// stockage de la dernière valeur
int LDR1_lastval;
int LDR2_lastval;
int LDR3_lastval;
int LDR4_lastval;

// servos n shit
Servo Base;
Servo Tour;
const byte Base_pin = 0;
const byte Tour_pin = 0;
int Base_pos = 90;
int Tour_pos = 45;

byte Tol = 50; // Tolérance


// setup crazy
void setup() {
    Serial.begin(9600);

    Base.attach(Base_pin);
    Tour.attach(Tour_pin);

    Base.write(Base_pos);
    Tour.write(Tour_pos);
}




// la boucle
void loop() {

}