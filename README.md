A Simple port of Snake game on CH32V203 and GC9106 display with 160*80 RGB resolution
Includes a portable driver

see gc9106.c


 Pin Connections

|  CH32v203 |        | Joystick | GC9106    |
|-----------|--------|----------|-----------|
| 3v3       |  -     |  VCC     |  VCC      |
| GND       | -      |  GNC     |  GND      |
| PA5       | AFIO   |  -       |  SCL/SCK  |
| PA7       | AFIO   |  -       |  MOSI/SDA |
| PA2       |  OUT   |  -       |  RES      |
| PA1       |  OUT   |  -       |  DC       |
| PA4       |  OUT   |  -       |  CS       |
| -         |  -     |  -       |  BLK      |
| PB0       |  AFIO  |  X       |  -        |
| PB1       |  AFIO  |  Y       |  -        |
| PA0       |  EXTI  |  switch  |  -        |
*/

MIT License

Copyright (c) [year] [fullname]

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
