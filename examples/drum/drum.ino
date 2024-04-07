/**
 * @file drum.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief Unit Synth Drum Example
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
    Serial.println("Unit Synth Drum");
    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 16, 17);
    synth.setInstrument(0, 9, SynthDrum);  // synth drum
}

void loop() {
    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 38, 127);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 42, 127);
    delay(300);

    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 38, 127);
    synth.setNoteOn(9, 42, 127);
    delay(300);
    synth.setNoteOn(9, 42, 127);
    delay(300);
}
