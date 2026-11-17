# MCA Microcontrollers and Applications Practicals

Corrected, independently compilable C source files for the MCA practical set.

## Source files

### 8051 / AT89C51 (Keil C51)

| Practical | Source |
|---|---|
| 1A – Binary LED counter (00H–FFH) | [practical1_binary_led.c](8051/practical1_binary_led.c) |
| 1B – Packed BCD LED counter (00–99) | [practical1_bcd_led.c](8051/practical1_bcd_led.c) |
| 2 – Hexadecimal LED counter (00H–FFH) | [practical2_hex_led.c](8051/practical2_hex_led.c) |
| 3 – Common-cathode 7-segment display (0–9, A–E) | [practical3_seven_segment.c](8051/practical3_seven_segment.c) |
| 4A – DAC square wave | [practical4a_dac_square_wave.c](8051/practical4a_dac_square_wave.c) |
| 4B – DAC triangular wave | [practical4b_dac_triangle_wave.c](8051/practical4b_dac_triangle_wave.c) |
| 5 – Stepper motor clockwise/anticlockwise | [practical5_stepper_motor.c](8051/practical5_stepper_motor.c) |

### LPC2148 (Triton IDE)

| Practical | Source |
|---|---|
| 6 – LED patterns on P0.8–P0.15 | [practical6_led_patterns.c](LPC2148/practical6_led_patterns.c) |
| 7 – 16x2 LCD student-name display | [practical7_lcd_student_name.c](LPC2148/practical7_lcd_student_name.c) |
| 8 – UART0 receive and echo | [practical8_uart0_echo.c](LPC2148/practical8_uart0_echo.c) |

## How to use

- Open the relevant Keil C51 or Triton IDE project.
- Add **one source file at a time** to the project. Do not add multiple practical files containing separate main functions to the same target.
- Build the selected file for the correct controller/device.
- The 8051 examples use the reg51.h device header. The LPC2148 examples use LPC214x.h or direct memory-mapped register definitions as shown in each file.

## Hardware assumptions and checks

- 8051 timing examples assume an AT89C51-compatible 12-clock core and an 11.0592 MHz crystal.
- 8051 LED examples write to Port 2. Confirm the trainer-board LED wiring and active-high/active-low polarity.
- The 7-segment lookup table assumes a common-cathode display with P2.0=a through P2.6=g. Confirm the actual board wiring and use current-limiting resistors.
- DAC examples require an external DAC connected to P1.0–P1.7. Timer reloads are starting values, not a guarantee of an exact 1 kHz analog output. Measure the output and calibrate for compiler overhead and the actual clock.
- The stepper motor must be connected through a suitable driver (for example, ULN2003); never connect motor windings directly to MCU GPIO pins. The actual direction depends on motor coil order and wiring.
- LPC2148 GPIO is 3.3 V logic. Check LCD input-level compatibility and use a suitable level shifter if required. Check the trainer board's LED polarity.
- UART0 settings assume a 12 MHz crystal, 60 MHz CCLK/PCLK and 9600 baud. If the board crystal or clock configuration differs, recalculate the UART divisor. Use a 3.3 V-compatible USB-TTL adapter, not a direct RS-232 connection.

## Verification status

The source files have been reviewed and corrected statically. They have **not** been built in Keil/Triton or verified on physical hardware in this repository-editing session. Confirm compiler compatibility and measure timer/DAC timing on the actual boards before the practical demonstration.
