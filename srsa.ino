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
const byte LDR2_pin = 2;
const byte LDR3_pin = 4;
const byte LDR4_pin = 6;
// valeurs
int LDR1_val;
int LDR2_val;
int LDR3_val;
int LDR4_val;
//// stockage de la dernière valeur
int lastval1;
int lastval2;
int lastval3;
int lastval4;


// checks
bool check1; // pour verif les conditions et tout mgl
bool check2;
// si true : aucun changement majeur, permet de pas ré-ajuster rapidement le SRSA chaque loop,
// si false: ça change fort fort tout

// servos n shit
Servo Base;
Servo Tour;
const byte Base_pin = 6;
const byte Tour_pin = 9;
int Base_pos = 90;
int Tour_pos = 35;

const int Tol = 10; // Tolérance


// setup crazy
void setup() {
    Serial.begin(9600);

    Base.attach(Base_pin);
    Tour.attach(Tour_pin);

    Base.write(Base_pos);
    Tour.write(Tour_pos);

    delay(1000);
}


void debug() {
    Serial.print(LDR1_val);
    Serial.print("  ");
    Serial.print(LDR2_val);
    Serial.print("  ");
    Serial.print(LDR3_val);
    Serial.print("  ");
    Serial.print(LDR4_val);
    Serial.println("\n=======\n");

    Serial.print(value1);
    Serial.print("  ");
    Serial.print(value2);
    Serial.print("  ");
    Serial.print(value3);
    Serial.print("  ");
    Serial.print(value4);
    Serial.println("\n=======\n");

    Serial.print(check1);
    Serial.print("  ");
    Serial.print(check2);
    Serial.println("\n=======\n");

    Serial.print(Base_pos);
    Serial.print("  ");
    Serial.print(Tour_pos);
    Serial.println("\n=======\n");
}




// la boucle
void loop() {
    int LDR1_val = analogRead(LDR1_pin);
    int LDR2_val = analogRead(LDR2_pin);


    int value1 = abs(LDR1_val - LDR2_val);
    int value2 = abs(LDR2_val - LDR1_val);

    //stock valeurs
    lastval1 = value1;
    lastval2 = value2;


    if ((value1 <= tol) || (value2 <= tol)) {
        check1 = true;
    }
    else {
        check1 = false;
        // déplacement
        if ((LDR1_val > LDR2_val) && (LDR1_val > lastval1)) {
            Base_pos = --Base_pos;
        }

        if ((LDR2_val > LDR1_val) && (LDR2_val > lastval2)) {
            Base_pos = ++Base_pos;
        }
        
        // limites
        if (Base_pos >= 140) {
            Base_pos = 140;
        }
        if (Base_pos <= 40) {
            Base_pos = 40;
        }
    }

    Base.write(Base_pos);

    /////////////////////////////////////////

    int LDR3_val = analogRead(LDR3_pin);
    int LDR4_val = analogRead(LDR4_pin);


    int value3 = abs(LDR3_val - LDR4_val);
    int value4 = abs(LDR4_val - LDR3_val);


    //stock valeurs
    lastval3 = value3;
    lastval4 = value4;


    if ((value3 <= tol) || (value4 <= tol)) {
        check2 = true;
    }
    else {
        check2 = false;
        if ((LDR3_val) > (LDR4_val) && (LDR3_val > lastval3)) {
            Tour_pos = --Tour_pos;
        }

        if ((LDR4_val) > (LDR3_val) && (LDR4_val > lastval4)) {
            Tour_pos = ++Tour_pos;
        }

        // limites
        if (Tour_pos >= 40) {
            Tour_pos = 40;
        }
        if (Tour_pos <= 30) {
            Tour_pos = 30;
        }
    }

    Tour.write(Tour_pos);
    
    if ((check1 == true) && (check2 == true)) {
        delay(6000);
    }
    else {
        delay(500);
    }
}
