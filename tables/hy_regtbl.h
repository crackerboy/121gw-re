#ifndef HY_REGTBL_H
#define HY_REGTBL_H

#include <inttypes.h>

// register tables for the HY3131
// each entry has the 20 registers starting at R20

/*
    DC Modes
*/

// DCV, LowZ, DCVA, DCmVA, DCuVA
const uint8_t hy_regtbl_dcv[4][20] = {
    // DCV 5.0000V, DC power 5.0000V, Burden Voltage
    {   0,   0,0x13,0x8A,   5,0x40,   0,0x4D,0x31,   1,
     0x22,   0,   0,0x90,0x28,0xA0,0x80,0xC7,   0,0x20},
    // DCV 50.000V, DC power 50.000V
    {   0,   0,0x13,0x8A,   5,0x40,   0,0x4D,0x31,   1,
     0x22,   0,   0,   9,0x28,0xA0,0x80,0xC7,   8,0x2C},
    // DCV 500.00V
    {   0,   0,0x13,0x8A,   5,0x40,   0,0x4D,0x31,   1,
     0x22,   0,0x90,   0,0x28,0xA0,0x80,0xC7,   8,0x2C},
    // DCV 1000.0V (600.0V), LowZ in DC
    {   0,   0,0x13,0x8A,   5,0x40,   0,0x4D,0x31,   1,
     0x22,   0,   9,   0,0x28,0xA0,0x80,0xC7,   8,0x2C}
    // unused register set
    //{   0,   0,0x16,0x8A,0x31,   1,   0,   0,0x31,   1,
    // 0x22,   0,   0,0x90,0x28,0xA0,0x80,0xC7,   8,0x20}
};

// DCmV, Temperature
const uint8_t hy_regtbl_dcmv[2][20] = {
    // DCmV 50.000mV, Temperature
    {0x60,   0,0x1C,0x8B,0x3B,0x51,   0,0x6D,0x31,   1,
        0,   0,   0,   0,   8,0x81,0x80,0xC0, 0xC,0x60},
    // DCmV 500.00mV
    {0x60,   0,0x10,0x8A,0x35,0x40,   0,0x6D,0x31,   1,
        0,   0,   0,   0,   8,0x81,0x80,0xC0, 0xC,0x2C}
};

// DCA, DCmA, DCuA
// DCVA, DCmVA, DCuVA
const uint8_t hy_regtbl_dc_amps[3][20] = {
    // DCA 500.00mA, DCmA 5.0000mA, DCuA 50.000uA
    // DCVA 500.00mA, DCmVA 5.0000mA, DCuVA 50.000uA
    {   0,   0,0x12,0x9B,0x93,0x31,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x33,0x2C},
    // DCA 5.0000A, DCmA 50.000mA, DCuA 500.00uA
    // DCmVA 50.000mA, DCuVA 500.00uA
    {   0,   0,0x12,0x8B,0x93,0x11,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x33,0x2C},
    // DCA 10.000A, DCVA 10.000A
    {   0,   0,0x12,0x8B,0x93,0x11,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x33,0x2C}
};

/*
    AC Modes
*/

// ACV, LowZ, ACVA, ACmVA, ACuVA
const uint8_t hy_regtbl_acv[4][20] = {
    // ACV 5.0000V, AC power 5.0000V, Burden Voltage
    {0xF6,0xDD,   2,0x83,0xF5,0x41,   2,0x4D,0x31,   1,
        0,   0,   0,   9,0x88,0xB0,0x80,0xC0,   8,0x2C},
    // ACV 50.000V, AC power 50.000V
    {0xF6,0xDD,   2,0x83,0xF5,0x41,   2,0x4D,0x31,   1,
        0,   0,0x90,   0,0x88,0xB0,0x80,0xC0,0x38,0x2C},
    // ACV 500.00V
    {0xF6,0xDD,   2,0x83,0xF5,0x41,   2,0x4D,0x31,   1,
        0,   0,   9,   0,0x88,0xB0,0x80,0xC0,0x38,0x2C},
    // ACV 1000.0V (600.0V), LowZ in AC
    {0xF6,0xDD,   0,0x83,0xF5,0x41,   2,0x4D,0x31,   1,
         0,   0,   9,   0,0x88,0xB0,0x80,0xC0,0x38,0x2C}
};

// ACV (when 1ms peak is enabled)
const uint8_t hy_regtbl_acv_1ms_peak[4][20] = {
    // ACV 5.0000V (1ms peak)
    {0xF6,0xDD,   4,   3,0x52,0x10,0x87,0x25,0x31,0xC4,
        0,   0,   0,0x90,0x88,0xA0,0x99,0xC7,0x38,0x20},
    // ACV 500.00V (1ms peak)
    {0xF6,0xDD,   4,   3,0x52,0x10,0x87,0x25,0x31,0xEC,
        0,   0,   0,   9,0x88,0xA0,0xB0,0xC7,0x38,0x20},
    // ACV 500.00V (1ms peak)
    {0xF6,0xDD,   4,   3,0x52,0x10,0x87,0x25,0x31,0xEC,
        0,   0,0x90,   0,0x88,0xA0,0x80,0xC7,0x38,0x20},
    // ACV 1000.0V (600.0V) (1ms peak)
    {0xF6,0xDD,   4,   3,0x52,0x10,0x87,0x25,0x31,0xEC,
        0,   0,   9,   0,0x88,0xA0,0x80,0xC7,0x38,0x20},
    // unused register set
    //{0x60,   0,   0,   0,   0,0x40,0x81,0x2D,   0,0xF8,
    //    0,   0,   0,   0,   8,0x81,0x80,0xC0, 0xA,0x2C}
};

// ACmV
const uint8_t hy_regtbl_acmv[2][20] = {
    // ACmV 50.000mV
    {0xF6,0xDD,0x13,0x8A,0xF5,0x43,   6,0x6D,0x31,   1,
        0,   0,   0,   0,   8,0x91,0x80,0xC0,0x3A,0x2C},
    // ACmV 500.00mV
    {0xF6,0xDD,0x13,0x8A,0xF5,0x40,   0,0x6D,0x31,   1,
        0,   0,   0,   0,   8,0x91,0x80,0xC0,0x3A,0x2C}
};

// ACmV (when 1ms peak is enabled)
const uint8_t hy_regtbl_acmv_1ms_peak[2][20] = {
    // ACmV 50.000mV (1ms peak)
    {0xF6,0xDD,   7,   3,   0,0x13,0x81,0x25,0x11,0xEC,
        0,   0,   0,   0,   0,0x90,0x80,0xC7,0x3A,0x28},
    // ACmV 500.00mV (1ms peak)
    {0xF6,0xDD,   7,   3,0x52,0x10,0x81,0x25,0x11,0xEC,
        0,   0,   0,   0,   0,0x90,0x80,0xC7,0x3A,0x28}
};

// ACA, ACmA, ACuA
// ACVA, ACmVA, ACuVA
const uint8_t hy_regtbl_ac_amps[3][20] = {
    // ACA 500.00mA, ACmA 5.0000mA, ACuA 50.000uA
    // ACVA 500.00mA, ACmVA 5.0000mA, ACuVA 50.000uA
    {0xF6,0xDD,0x12,0x8B,0xF3,0x11,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x3D,0x2C},
    // ACA 5.0000A, ACmA 50.000mA, ACuA 500.00uA
    // ACmVA 50.000mA, ACuVA 500.00uA
    {0xF6,0xDD,0x12,0x8B,0xF3,0x11,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x3D,0x2C},
    // ACA 10.000A, ACVA 10.000A
    {0xF6,0xDD,0x12,0x8B,0xF3,0x10,   0,0x55,0x31,   0,
        0,   0,   0,   0,   0,0x80,0x80,0xC7,0x3D,0x2C}
};

/*
    Other Modes
*/

// Hz/ms/%
const uint8_t hy_regtbl_freq[20] = {
    0xFE,0xDD,   0,   0,   0,   1,   0,   0,   0,   0,
    0x22,   0,   0,0x90,0x28,0xA0,   0,0xC0,   8,0x2C
};

// Ohms
const uint8_t hy_regtbl_ohms[7][20] = {
    // 50.000Ω
    {0x74,0xCF,0x15,0x8F,0x85,   0,   0,   0,   0,   0,
        0,0x40,   6,   0,   4,0x94,0x80,0xD2, 0xC,0x2C},
    // 500.00Ω
    {0x74,0xCF,0x15,0x8F,0x85,   0,   0,   0,   0,   0,
        0,0x40,   6,   0,   4,0x94,0x80,0xD2, 0xC,0x2C},
    // 5.0000kΩ
    {   0,   0,0x13,0x83,0x85,   0,   0,   0,   0,   0,
        0,0x40,0x60,   0,   0,0x94,0x80,0xD3, 0xC,0x2C},
    // 50.000kΩ
    {   0,   0,0x14,0x83,0x85,   0,   0,   0,   0,   0,
        0,0x40,   0,   6,   0,0x94,0x80,0xD3, 0xC,0x2C},
    // 500.00kΩ
    {   0,   0,0x14,0x83,0x85,   0,   0,   0,   0,   0,
        0,0x40,   0,0x60,   0,0x94,0x80,0xD2, 0xC,0x20},
    // 5.0000MΩ
    {   0,   0,0x14,0x93,0x85,   0,   0,   0,0x55,   0,
        0,   8,   0,0x80,0x80,0x86,0x80,0xD1,   0,0xAC},
    // 50.000MΩ
    {   0,   0,0x15,0x93,0x85,   0,   0,   0,0x55,   0,
        8,   8,   0,   0,   0,0x86,0x80,0xD1,   0,0xAC}
};

// Continuity
const uint8_t hy_regtbl_continuity[20] = {
    0x74,0xCF,0x10,0x8F,0x85,   0,   0,   0,   0,   0,
       0,0x40,   6,   0,   4,0x94,0x80,0xD2, 0xC,0x2C
};

// Diode
const uint8_t hy_regtbl_diode[20] = {
    0,   0,0x12,0x83,0x8D,   0,   0,   0,0x11,   0,
    0,   0,   8,   0,0x40,0x92,0x80,0xE1,   3,0xAC
};

// Capacitance
const uint8_t hy_regtbl_cap[6][20] = {
    // 10.00nF
    {0x76,0x21,   7,   0,   0,   0,   0,   0,   0,   0,
        0,   8,   0,0x80,   0,0x8E,   0,0xC2, 0xE,0x20},
    // 100.0nF
    {0x76,0x21,   7,   0,   0,   0,   0,   0,   0,   0,
        0,   8,   0,0x80,   0,0x8E,   0,0xC2, 0xE,0x20},
    // 1.000uF
    {0x76,0x21,   7,   0,   0,   0,   0,   0,   0,   0,
        0,   8,0x80,   0,   0,0x8E,   0,0xC2, 0xE,0x20},
    // 10.00uF
    {0x76,0x21,   4,0x8A,0xA5,   0,   0,   0,0x55,   0,
        0,   8,   8,   0,   0,0x8E,   0,0xC2, 0xE,0x20},
    // 100.0uF
    {0x76,0x21,   4,0x8A,0xA5,   0,   0,   0,0x55,   0,
        0,   8,   8,   0,   0,0x8E,   0,0xC2, 0xE,0x20},
    // 10.00mF
    {0x52,0x21,   0,   0,   0,0x11,   0,0x50,0x11,   0,
        0,   0,   8,   0,   0,0x9A,   0,0xC2,0x3C,0x20}
};

// interrupt register settings
// RMSIE and CTIE when in 1ms peak mode
// AD1IE and CTIE when in an AC mode
// CTIE when in capacitance, Hz, ms, or duty
// just AD1IE otherwise

#endif