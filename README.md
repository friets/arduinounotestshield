# arduinounotestshield
functional test of arduino uno pins

you can build this solderless,
via soldering or by using the standard shields

or order your pcb,and assemble the smt/headers
1206 10K resistors you can order at A.E. for a few euro's, male 2.54 headers too

the hardware design is very simple, cheap and very convenient if you need to test your arduino uno

i think my commodore64 assemblycode history is a bit eminent in the arduino sketch

unotestshieldprego script by Friets Koudijs/KumBaTechnologies
to test the analogue and digital pins of the Arduino Uno
and confirm they are working properly with LOW and HIGH
pinD0 and pinD1 are for serial monitoring
if the serial works than they are working correctly
pinD2 and forward sends to the next pinD3
which should return the HIGH or LOW
analogPins are to be sending and receiving digital signals
the pins are connected via a 10Kohm resistor to limit current for the MCU

be sure to replace this test-sketch with another one afterwards (or blinksketch in examples) otherwise this software without the testshield will possibly wreck your arduino uno or attached hardware/sensors!!
