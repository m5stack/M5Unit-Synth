#include <M5Unified.h>
#include <M5GFX.h>
#include "M5UnitSynth.h"

M5UnitSynth synth;

void setup() {
    M5.begin();
    synth.begin(&Serial2, UNIT_SYNTH_BAUD, 13, 14);
    synth.setInstrument(0, 9, 117);  // synth drum
}

void loop() {
    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 38, 127);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 42, 127);
    delay(500);

    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 36, 127);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 38, 127);
    synth.setNoteOn(9, 42, 127);
    delay(500);
    synth.setNoteOn(9, 42, 127);
    delay(500);
}
