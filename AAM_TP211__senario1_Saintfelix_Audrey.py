#!/usr/bin/python3
#  -*- coding: utf-8 -*-
# Author: Audrey SAINTFELIX
# Creation date : 03/05/2021

# Description : TP211 senario 1
# The panel follows the course of the sun

import time
import board
import pwmio
from adafruit_motor import servo

# create a PWMOut object on Pin A1 (Rotation of panel)
pwm1 = pwmio.PWMOut(board.A1, duty_cycle=2 ** 15, frequency=50)
# create a PWMOut object on Pin A4 (Tilt of panel)
pwm2 = pwmio.PWMOut(board.A3, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo1 = servo.Servo(pwm1)
my_servo2 = servo.Servo(pwm2)


while True:
    for angle in range(0, 180, 1):  # 0 - 180 degrees, 1 degree at a time.
        my_servo1.angle = angle
        my_servo2.angle = angle
        time.sleep(0.05)
    for angle in range(180, 0, -1):  # 180 - 0 degrees, 1 degree at a time.
        my_servo1.angle = angle
        my_servo2.angle = angle
        time.sleep(0.05)
