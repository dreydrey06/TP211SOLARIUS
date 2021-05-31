#!/usr/bin/python3
#  -*- coding: utf-8 -*-
# Author: Audrey SAINTFELIX
# Creation date : 03/05/2021

# Description : TP211 senario 2
# The panel change its position depending on data
# from light sensors

import time
import board
import analogio
import simpleio
import pwmio
from adafruit_motor import servo

# create a PWMOut object on Pin A1 (Rotation of panel)
pwm1 = pwmio.PWMOut(board.A1, duty_cycle=2 ** 15, frequency=50)
# create a PWMOut object on Pin A4 (Tilt of panel)
pwm2 = pwmio.PWMOut(board.A3, duty_cycle=2 ** 15, frequency=50)

# Create a servo object, my_servo.
my_servo1 = servo.Servo(pwm1)
my_servo2 = servo.Servo(pwm2)

light1 = analogio.AnalogIn(board.LIGHT)


def move_up(servo):
    """
    move_up() is a fonction that adds 5 deg
    to the angle of a servo.

    Parameters (Input Variables):
        ----------
        servo :
            servo object that you want to move up.
    Output:
        ----------
        moves the chosen servo.

    Dependencies:
        -----------
        adafruit_motor
        servo

    Typical usage example:
        ----------
        move_up(my_servo1)
    """
    my_servo = servo
    my_servo.angle += 5


def move_down(servo):
    """
    move_down() is a fonction that substract 5 deg to the angle of a servo.

    Parameters (Input Variables):
        ----------
        servo :
            servo object that you want to move down.
    Output:
        ----------
        moves the chosen servo.

    Dependencies:
        -----------
        adafruit_motor
        servo

    Typical usage example:
        ----------
        move_down(my_servo1)
    """
    my_servo = servo
    my_servo.angle -= 5


while True:
    # light value remapped to pixel position
    peak = simpleio.map_range(light1.value, 0, 320, 0, 10)
    print(int(peak))

    for i in range(0, 10, 1):
        if i <= peak:
            move_up(my_servo1)
            move_down(my_servo2)

    time.sleep(0.01)
