#include <M5Unified.h>
#include <M5GFX.h>
#include "M5UnitSynth.h"

M5UnitSynth synth;

void setup() {
    M5.begin();
    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 13, 14);
    synth.setInstrument(0, 9, 1);  // synth piano 1
}

void loop() {
    synth.setNoteOn(9, 60, 127);
    delay(1000);
    synth.setNoteOn(9, 62, 127);
    delay(1000);
    synth.setNoteOn(9, 64, 127);
    delay(1000);
    synth.setNoteOn(9, 65, 127);
    delay(1000);
    synth.setNoteOn(9, 67, 127);
    delay(1000);
    synth.setNoteOn(9, 69, 127);
    delay(1000);
    synth.setNoteOn(9, 71, 127);
    delay(1000);
    synth.setNoteOn(9, 72, 127);
    delay(1000);
}
