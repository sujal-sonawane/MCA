# MCA Practical Exam Codes - E&TC

This repository contains the eight practical programs expected for the MCA practical examination, organized for **Keil C51 (8051)** and **Triton IDE (LPC2148)**.

The supplied NMIET MCA lab manual is used for the experiment approach, register names, I/O port mapping and coding style. Where the exam practical title asks for behavior missing from the printed manual program, the exam-specific source adds that behavior.

## Exam practical list

### 8051 / AT89C51 / AT89S52 - Keil C51

| No. | Practical | Source file(s) |
|---|---|---|
| 1 | LED interfacing - Binary and BCD number display | [Binary](8051/practical1_binary_led.c) · [BCD](8051/practical1_bcd_led.c) |
| 2 | LED interfacing - Hexadecimal display and counter operation | [Hexadecimal](8051/practical2_hex_led.c) · [8-bit counter](8051/practical2_counter_operation.c) |
| 3 | Common-cathode 7-segment display - 0-9 and A-E | [Combined 0-9 and A-E](8051/practical3_seven_segment.c) · [Letters only](8051/practical3_seven_segment_characters.c) |
| 4 | DAC waveform generation - any two waveforms, Timer 0, nominal 1 kHz | [Square wave](8051/practical4a_dac_square_wave.c) · [Triangular wave](8051/practical4b_dac_triangle_wave.c) |
| 5 | Stepper motor - clockwise and anticlockwise using Timer 0 | [CW and ACW](8051/practical5_stepper_motor.c) |

**Additional reference programs from the lab manual:** [LED flashing](8051/practical1_led_flashing.c) · [DAC sine wave](8051/practical4c_dac_sine_wave.c)

### LPC2148 - Triton IDE

| No. | Practical | Source file |
|---|---|---|
| 6 | LEDs on P0.8-P0.15 - different patterns | [LED patterns](LPC2148/practical6_led_patterns.c) |
| 7 | 16x2 LCD - display student name | [LCD student name](LPC2148/practical7_lcd_student_name.c) |
| 8 | UART0 - receive and echo a character | [UART0 echo](LPC2148/practical8_uart0_echo.c) |

## Important differences from the printed manual

These exam-specific programs intentionally satisfy the practical titles you supplied:

1. **Practical 3:** The manual's Experiment 2 prints separate single-digit programs and includes F in the character list. The exam source combines 0-9 and A-E in one sequence.
2. **Practical 4:** The manual's Experiment 3 source programs use software-delay loops. The exam source uses Timer 0 sample delays as requested. The 8051 timer reloads are nominal starting values; actual waveform frequency depends on oscillator frequency, instruction overhead and DAC circuit. Verify the output with a CRO/oscilloscope and adjust timer values for a measured 1 kHz.
3. **Practical 5:** The manual's Experiment 4 source only rotates in one direction. The exam source runs the sequence forward and then in reverse. The phase sequence is taken from the manual's printed source code (01H, 02H, 04H, 08H).
4. **Practical 6:** The manual's Experiment 5 source blinks all eight LEDs together. The exam source includes all-ON/all-OFF, alternating 55H/AAH and running LED patterns.
5. **Practical 7:** The manual's Experiment 6 displays "NMIET PUNE". The exam title asks for student name, so this source displays "SUJAL SONAWANE".
6. **Practical 8:** UART0 echo follows Experiment 7 in the manual. PLL settings assume a 12 MHz crystal and 60 MHz CCLK/PCLK.

## Hardware and build notes

- Add **one practical source file at a time** to a Keil/Triton project. Each file has its own main function.
- 8051 timer examples assume an AT89C51/AT89S52-compatible 12-clock core and an 11.0592 MHz crystal.
- 8051 LED programs use Port 2. Check the actual trainer-board LED wiring and polarity.
- The 7-segment lookup table assumes common-cathode wiring with P2.0=a through P2.6=g. Confirm your board's segment connections and use suitable current-limiting resistors.
- DAC practical requires an external 8-bit DAC connected to P1.0-P1.7 and the required output amplifier/circuit. Do not connect the analog output directly to a microcontroller pin.
- Stepper motor P2.0-P2.3 must connect through a suitable driver such as ULN2003. Never connect motor windings directly to 8051 GPIO pins. Actual clockwise/anticlockwise direction depends on the coil wiring.
- LPC2148 GPIO uses 3.3 V logic. Check the LCD and serial adapter voltage compatibility. Use a 3.3 V-compatible USB-TTL adapter for UART0.
- The LPC2148 UART program assumes the board's 12 MHz crystal and the manual's 60 MHz PLL/peripheral-clock setup.

## Verification status

The files have been pushed to the GitHub main branch and checked for presence. They have **not** been compiled in Keil/Triton or tested on your physical development kits in this session. The timer-based DAC frequency must be measured and calibrated on the actual board.
