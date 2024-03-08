# arduinounotestshield
functional test of arduino uno pins

unotestshieldprego script by Friets Koudijs/KumBaTechnologies
to test the analogue and digital pins of the Arduino Uno
and confirm they are working properly with LOW and HIGH
pinD0 and pinD1 are for serial monitoring
if the serial works than they are working correctly
pinD2 and forward sends to the next pinD3
which should return the HIGH or LOW
analogPins are to be sending and receiving digital signals
the pins are connected via a 10Kohm resistor to limit current
