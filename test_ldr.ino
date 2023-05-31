/*
┌─────────────┐
│ LDR1 │ LDR2 │
│ ─────┼───── │
│ LDR3 │ LDR4 │
└─────────────┘
*/

// pins
const byte LDR1_pin = 0;
const byte LDR2_pin = 1;
const byte LDR3_pin = 2;
const byte LDR4_pin = 3;
// valeurs
int LDR1_val;
int LDR2_val;
int LDR3_val;
int LDR4_val;
// stockage de la dernière valeur
//int lastval1;
//int lastval2;
//int lastval3;
//int lastval4;
//int LDR1_lastval;
//int LDR2_lastval;
//int LDR3_lastval;
//int LDR4_lastval;


// setup crazy
void setup() {
    Serial.begin(9600);
}


// la boucle
void loop() {
    LDR1_val = analogRead(LDR1_pin);
    LDR2_val = analogRead(LDR2_pin);

    LDR3_val = analogRead(LDR3_pin);
    LDR4_val = analogRead(LDR4_pin);

    Serial.print(LDR1_val);
    Serial.print("  ");
    Serial.print(LDR2_val);
    Serial.print("  ");
    Serial.print(LDR3_val);
    Serial.print("  ");
    Serial.print(LDR4_val);
    Serial.println("\n=======\n");

    delay(500);
}