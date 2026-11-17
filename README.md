# MCA Microcontrollers Lab - source codes from the supplied manual

**Source of truth:** *MCA Upto Expt 8 (1)(1).pdf*, NMIET E&TC Microcontrollers Lab manual, AY 2026-27. The files below follow the program/code sections printed after the relevant experiments. Only small compile-safety additions are noted explicitly.

## 8051 / AT89S52 / AT89C51 (Keil C51)

| Practical / manual section | Source file |
|---|---|
| Experiment 1A - LED flashing (additional program in the manual) | [practical1_led_flashing.c](8051/practical1_led_flashing.c) |
| Practical 1 - Binary counter / 8-bit Port 2 counter (Experiment 1D) | [practical1_binary_led.c](8051/practical1_binary_led.c) |
| Practical 1 - BCD counter 00-99 (Experiment 1B) | [practical1_bcd_led.c](8051/practical1_bcd_led.c) |
| Practical 2 - Hexadecimal counter 00H-FFH (Experiment 1C) | [practical2_hex_led.c](8051/practical2_hex_led.c) |
| Practical 3 - Common-cathode 7-segment digits 0-9 (Experiment 2E) | [practical3_seven_segment.c](8051/practical3_seven_segment.c) |
| Practical 3 - 7-segment characters A-F (Experiment 2F; includes extra F) | [practical3_seven_segment_characters.c](8051/practical3_seven_segment_characters.c) |
| Practical 4 - DAC square wave (Experiment 3A) | [practical4a_dac_square_wave.c](8051/practical4a_dac_square_wave.c) |
| Practical 4 - DAC triangular wave (Experiment 3B) | [practical4b_dac_triangle_wave.c](8051/practical4b_dac_triangle_wave.c) |
| Experiment 3C - DAC sine wave (additional waveform in the manual) | [practical4c_dac_sine_wave.c](8051/practical4c_dac_sine_wave.c) |
| Practical 5 - Stepper motor using Timer 0 (Experiment 4A) | [practical5_stepper_motor.c](8051/practical5_stepper_motor.c) |

## LPC2148 (Triton IDE)

| Practical / manual section | Source file |
|---|---|
| Practical 6 - P0.8-P0.15 LED blinking (Experiment 5) | [practical6_led_patterns.c](LPC2148/practical6_led_patterns.c) |
| Practical 7 - 16x2 LCD, message "NMIET PUNE" (Experiment 6) | [practical7_lcd_student_name.c](LPC2148/practical7_lcd_student_name.c) |
| Practical 8 - UART0 receive and echo (Experiment 7) | [practical8_uart0_echo.c](LPC2148/practical8_uart0_echo.c) |

## Important: differences between practical titles and the manual's printed programs

These points are intentionally not silently rewritten; the source code follows the manual:

1. **7-segment:** the printed code is a single-digit sequence, not a multiplexed two-digit 00-99 display. The manual's digits program declares `digit[9]` but initializes ten values and indexes through 9; the repository uses `digit[10]` so the intended 0-9 program has a valid array.
2. **DAC:** the manual's square, triangular and sine programs use software-delay loops. They do not use Timer 0 and do not establish a calibrated 1 kHz output. The square-wave file includes `reg51.h` so the 8051 port register is declared.
3. **Stepper motor:** the printed program applies `01H, 02H, 04H, 08H` repeatedly in one direction. Although the experiment algorithm mentions reversing the sequence, the printed program does not implement anticlockwise rotation.
4. **LPC2148 LEDs:** the printed program blinks P0.8-P0.15 together (all ON, then all OFF). It does not generate alternate or running patterns.
5. **LCD:** the manual's message is `NMIET PUNE`; it is not a student-name string. The pin assignments and LCD command sequence follow the manual. Function prototypes are added before `main` to avoid implicit function-declaration issues.
6. **UART0:** this is Experiment 7 in the supplied PDF. A prototype for `PLL0_Init` is added before `main`. Its PLL setup assumes a 12 MHz crystal and 60 MHz CCLK/PCLK as stated in the manual.

The supplied PDF's **Experiment 8** is an ADC0.1 voltage-reading program that displays ADC count and voltage through UART0. It is not the UART0 echo practical listed above, so it has not been substituted for Practical 8.

## How to use

- Add only the one practical source file you are building to its Keil/Triton project. Do not add several files containing their own `main()` into one target.
- 8051 source files use `reg51.h`. The LCD file uses `LPC214x.h`; the UART and LED files access registers directly.
- Confirm the trainer-board pin wiring and polarity before programming.
- The stepper motor must use a suitable driver such as ULN2003; do not drive motor windings directly from MCU pins.
- LPC2148 GPIO is 3.3 V logic. Check the connected LCD/serial adapter's voltage compatibility.

**Verification status:** source files were compared against the uploaded manual and committed to GitHub. They have not been built in Keil/Triton or tested on the physical kits in this session.
