#===============================IMPORTS==========================
import PySimpleGUI as sg
import serial.tools.list_ports

#===============================PORT STUFF=======================
ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()
portsList = []

for one in ports:
    portsList.append(str(one))
    print(str(one))

com = input("Selected Com Port for Arduino #: ")

for i in range(len(portsList)):
    if(portsList[i].startswith("COM" + str(com))):
        use = "COM" + str(com)
        print(use)

serialInst.baudrate = 9600
serialInst.port = use
serialInst.open()

#===============================WINDOW LAYOUT======================
layout = [
    [sg.Text('Enter item to display on LCD:')],
    [sg.InputText(key='-INPUT-')],
    [sg.Button('Submit', key='-SUBMIT-')]
    ]

window = sg.Window('Project Menu',
                   layout,
                   size = (300,300),
                   )

#===============================MAIN WINDOW LOOP====================
while True:
    event, values = window.read()

    if event == sg.WIN_CLOSED:
        break

    if event == '-SUBMIT-':
        command = values['-INPUT-']
        serialInst.write(command.encode('utf-8'))

window.close() 