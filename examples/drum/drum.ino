/**
 * @file drum.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief Unit Synth Drum Example
 * @version 0.1
 * @date 2024-01-24
 *
 *
 * @Hardwares: M5Core + Unit Synth
 * @Platform Version: Arduino M5Stack Board Manager v2.1.0
 * @Dependent Library:
 * M5Unified: https://github.com/m5stack/M5Unified
 * M5GFX: https://github.com/m5stack/M5GFX
 * M5UnitSynth: https://github.com/m5stack/M5Unit-Synth
 */

#include <M5Unified.h>
#include <M5GFX.h>
#include "M5UnitSynth.h"

M5UnitSynth synth;

void setup() {
    M5.begin();
    M5.Display.setTextColor(GREEN);
    M5.Display.setTextDatum(middle_center);
    M5.Display.setTextSize(2);
    M5.Display.drawString("Unit Synth Drum", M5.Display.width() / 2,
                          M5.Display.height() / 2);

    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 16, 17);
    synth.setInstrument(0, 9, 119);  // synth drum
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
