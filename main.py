import serial
import time

# Initialize serial communication
arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)

def send_command(command):
    arduino.write(f"{command}\n".encode())
    time.sleep(0.1)
    while arduino.in_waiting:
        response = arduino.readline().decode().strip()
        print(response)

while True:
    user_input = input("Enter a digit (0-9): ").strip()
    if user_input.isdigit() and 0 <= int(user_input) <= 9:
        send_command(user_input)
    else:
        print("Invalid command. Please enter a single digit (0-9).")
