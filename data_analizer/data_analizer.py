#!/usr/bin/python3.7
# UTF8
# Date: 15/06/2021
# Author: Audrey Saintfélix
# Description: Analyzing the data we got form our solar panel
# This creates a JPEG image of the voltage and power depending on the time.

import matplotlib.pyplot as plt
import csv

def open_and_count(filecsv=str):
    """this function takes for variable the name of your csv file (str),
    opens it, and extracts the number of the mesure, the power mesured and
    the voltage mesure.

     """
    num = []
    power = []
    voltage = []
    with open(filecsv, "r") as f:
        data = csv.reader(f, delimiter=',')
        for row in data:
            num.append(row[0])
            power.append(row[1])
            voltage.append(row[2])

    return(num, power, voltage)

def chart_it(filtered_data : tuple):
    """This function takes a tuple for variable and creates a chart
    """
    num = filtered_data[0]
    power = filtered_data[1]
    voltage = filtered_data[2]

    plt.plot(num, power, color='#A5DAED', label='Power (W)')
    plt.plot(num, voltage, color='#922f39', label='Voltage (V)')
    plt.xlabel('Prise de mesure')
    plt.title('La puissance et la tension délivrée par le panneau solaire au cours du temps')
    plt.legend()
    plt.tight_layout()
    plt.savefig('TP_SOLARIUS_dreydrey.png')
    plt.show()


def analyse_data(text=str):
    """This functions takes for variable the name of your text (str),
    Calls the function open_and_count() to count each
    letters of your text and calls the function chart_it()
    to create a chart with the result of open_and_count() """
    filtered_data = open_and_count(text)
    chart_it(filtered_data)


analyse_data("data.csv")
