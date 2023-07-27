# ArduinoElectricalSerial

To test the program:
- Arduino
  - A0: photoresitor
  - A1: thermistor
  - Digital PWM 3: lights
  - Digital PWN 4: fans
- Upload the .ino file to your arduino and wire up the circuit accordingly
- To control the lights
  - Run the ElectricalArduinoControl.py in python
  - Click the "l" key on the keyboard, and enter a number between 0 and 900, then click enter.
    The brightness of the lights should change according to the brightness calculated.
