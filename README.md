# ArduinoElectricalSerial

Circuit link: https://www.tinkercad.com/things/1O8pPF7bCUi?sharecode=OlKg_nXhsGBSeeuMFCT1trnpryemHl8tqz7R8jmX158

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
    The LED should change accordingly to the brightness calculated.
