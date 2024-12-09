A Simple port of Snake game on CH32V203 and GC9106 display with 160*80 RGB resolution
Includes a portable driver

see gc9106.c

/*

 Pin Connections

|  CH32v203 |        | Joystick | GC9106     |
|-----------|--------|----------|------------|
| 3v3       | ║ -    | ║ VCC    | ║ VCC      |
| GND       | ║ -    | ║ GNC    | ║ GND      |
| PA5       | ║ AFIO | ║ -      | ║ SCL/SCK  |
| PA7       | ║ AFIO | ║ -      | ║ MOSI/SDA |
| PA2       | ║ OUT  | ║ -      | ║ RES      |
| PA1       | ║ OUT  | ║ -      | ║ DC       |
| PA4       | ║ OUT  | ║ -      | ║ CS       |
| -         | ║ -    | ║ -      | ║ BLK      |
| PB0       | ║ AFIO | ║ X      | ║ -        |
| PB1       | ║ AFIO | ║ Y      | ║ -        |
| PA0       | ║ EXTI | ║ switch | ║ -        |
*/
