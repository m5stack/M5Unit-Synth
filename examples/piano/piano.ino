/**
 * @file piano.ino
 * @author SeanKwok (shaoxiang@m5stack.com)
 * @brief Unit Synth Piano Example
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
    M5.Display.drawString("Unit Synth Piano", M5.Display.width() / 2,
                          M5.Display.height() / 2);

    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 16, 17);
    synth.setInstrument(0, 0, 1);  // synth piano 1
}

void loop() {
    synth.setNoteOn(0, 60, 127);
    delay(1000);
    synth.setNoteOn(0, 62, 127);
    delay(1000);
    synth.setNoteOn(0, 64, 127);
    delay(1000);
    synth.setNoteOn(0, 65, 127);
    delay(1000);
    synth.setNoteOn(0, 67, 127);
    delay(1000);
    synth.setNoteOn(0, 69, 127);
    delay(1000);
    synth.setNoteOn(0, 71, 127);
    delay(1000);
    synth.setNoteOn(0, 72, 127);
    delay(1000);
}
