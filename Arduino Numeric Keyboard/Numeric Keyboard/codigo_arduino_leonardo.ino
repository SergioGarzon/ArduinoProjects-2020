#include "Keyboard.h"

const int pinesCajas[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

const char teclas[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

void setup() {
    for (int i = 0; i < 10; i++) {
        pinMode(pinesCajas[i], INPUT_PULLUP);
    }

    Serial.begin(9600);
    Keyboard.begin();
}

void loop() {
    for (int i = 0; i < 10; i++) {
        if (digitalRead(pinesCajas[i]) == LOW) {
            Keyboard.write(teclas[i]); 
            delay(200);                
        }
    }
}
