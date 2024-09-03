#ifndef _M5_UNIT_SYNTH_H
#define _M5_UNIT_SYNTH_H

#include "M5UnitSynthDef.h"
#include "Arduino.h"

#define UNIT_SYNTH_BAUD 31250

#define MIDI_CMD_NOTE_OFF 0x80  // Note Off
#define MIDI_CMD_NOTE_ON  0x90  // Note On
#define MIDI_CMD_POLYPHONIC_AFTERTOUCH \
    0xA0  // Polyphonic Aftertouch (or Key Pressure)
#define MIDI_CMD_CONTROL_CHANGE \
    0xB0                              // Control Change (or Channel Mode
                                      // Message)
#define MIDI_CMD_PROGRAM_CHANGE 0xC0  // Program Change
#define MIDI_CMD_CHANNEL_AFTERTOUCH \
    0xD0  // Channel Aftertouch (or Channel Pressure)
#define MIDI_CMD_PITCH_BEND       0xE0  // Pitch Bend
#define MIDI_CMD_SYSTEM_EXCLUSIVE 0xF0  // System Exclusive (SysEx) Start
#define MIDI_CMD_TIME_CODE        0xF1  // MIDI Time Code Quarter Frame
#define MIDI_CMD_SONG_POSITION    0xF2  // Song Position Pointer
#define MIDI_CMD_SONG_SELECT      0xF3  // Song Select
#define MIDI_CMD_TUNE_REQUEST     0xF6  // Tune Request
#define MIDI_CMD_END_OF_SYSEX     0xF7  // End of SysEx
#define MIDI_CMD_TIMING_CLOCK \
    0xF8  // Timing Clock (used in System Real-Time Messages)
#define MIDI_CMD_START    0xFA  // Start (used in System Real-Time Messages)
#define MIDI_CMD_CONTINUE 0xFB  // Continue (used in System Real-Time Messages)
#define MIDI_CMD_STOP     0xFC  // Stop (used in System Real-Time Messages)
#define MIDI_CMD_ACTIVE_SENSING \
    0xFE  // Active Sensing (used in System Real-Time Messages)
#define MIDI_CMD_SYSTEM_RESET 0xFF  // System Reset

class M5UnitSynth {
   private:
    HardwareSerial *_serial;
    void sendCMD(uint8_t *buffer, size_t size);

   public:
    void begin(HardwareSerial *serial = &Serial1, int baud = UNIT_SYNTH_BAUD,
               uint8_t RX = 16, uint8_t TX = 17);

    void setInstrument(uint8_t bank, uint8_t channel, uint8_t value);
    void setNoteOn(uint8_t channel, uint8_t pitch, uint8_t velocity);
    void setNoteOff(uint8_t channel, uint8_t pitch, uint8_t velocity);
    void setAllNotesOff(uint8_t channel);

    void setPitchBend(uint8_t channel, int value);
    void setPitchBendRange(uint8_t channel, uint8_t value);

    void setMasterVolume(uint8_t level);             // 0-127
    void setVolume(uint8_t channel, uint8_t level);  // 0-127
    
    void setExpression(uint8_t channel, uint8_t expression);  // 0-127

    void setReverb(uint8_t channel, uint8_t program, uint8_t level,
                   uint8_t delayfeedback);

    void setChorus(uint8_t channel, uint8_t program, uint8_t level,
                   uint8_t feedback, uint8_t chorusdelay);
    void setPan(uint8_t channel, uint8_t value);
    void setEqualizer(uint8_t channel, uint8_t lowband, uint8_t medlowband,
                      uint8_t medhighband, uint8_t highband, uint8_t lowfreq,
                      uint8_t medlowfreq, uint8_t medhighfreq,
                      uint8_t highfreq);

    void setTuning(uint8_t channel, uint8_t fine,
                   uint8_t coarse);  // 0-127, 64 is default t
    void setVibrate(uint8_t channel, uint8_t rate, uint8_t depth,
                    uint8_t delay);

    void setTvf(uint8_t channel, uint8_t cutoff, uint8_t resonance);

    void setEnvelope(uint8_t channel, uint8_t attack, uint8_t decay,
                     uint8_t release);

    void setModWheel(uint8_t channel, uint8_t pitch, uint8_t tvtcutoff,
                     uint8_t amplitude, uint8_t rate, uint8_t pitchdepth,
                     uint8_t tvfdepth, uint8_t tvadepth);

    void setAllInstrumentDrums();

    void reset();
};

#endif
