# Joshua Liu
# 2023-07-01
# This is a test for serial communication between Python and Arduino"
# Keyboard input can stay the same or be changed to the controllerg

import serial
from pynput import keyboard
from pynput.keyboard import Key, Listener

# Baud rate must be the same as the arduino code
# COM9 is the port that the arduino is connected to. Different OS have different naming conventions to define the port
arduino = serial.Serial('COM9', 9600, timeout=.1) 

def on_press(key):
	try: 
		message = ""
		if key.char == 'l': # Activation key, will be removed during parsing
			message = input("Enter a number: ")
			arduino.write(bytes(message[1:], "utf-8"))
	except AttributeError: 
		print("Special key {0} pressed".format(key))

def on_release(key): 
	try: 
		pass
	except AttributeError: 
		print("Special key {0} released".format(key)) 

def printDataFromArduino():
	data = ""
	if arduino.in_waiting:
		data = arduino.readline()
		if data:
			print (data[:-2])
	return data

if __name__ == "__main__":
	listener = keyboard.Listener(on_press=on_press, on_release=on_release) 
	listener.start()

	while 1:
		data = printDataFromArduino()
