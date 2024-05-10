/**
 * @file piano.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief Unit Synth Piano Example
 * @version 0.2
 * @date 2024-04-07
 *
 *
 * @Hardwares: M5Core + Unit Synth
 * @Platform Version: Arduino M5Stack Board Manager v2.1.0
 * @Dependent Library:
 * M5UnitSynth: https://github.com/m5stack/M5Unit-Synth
 */

#include "M5UnitSynth.h"

M5UnitSynth synth;

void setup() {
    Serial.begin(115200);
    Serial.println("Unit Synth Piano");
    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 16, 17);
    synth.setInstrument(0, 0, GrandPiano_1);  // synth piano 1
}

void loop() {
    synth.setNoteOn(0, NOTE_C4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_D4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_E4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_F4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_G4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_A4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_B4, 127);
    delay(1000);
    synth.setNoteOn(0, NOTE_C5, 127);
    delay(1000);
}
