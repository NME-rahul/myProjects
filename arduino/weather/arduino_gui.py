#standard libraries
import time
import os

#for webscarping
import requests

#for Serial Communication
import serial
import serial.tools.list_ports as avail_ports

#for GUI
from tkinter import *
import tkinter.messagebox as tk_msg
from tkinter import ttk


class GUI:

    dflt_port = StringVar()
    dflt_baudrate = StringVar()
    dflt_bytesize = StringVar()
    bd_rates = (110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 128000, 256000)
        
    def __init__(self):
        pass
    
    def collectData(self):
        apiID = ''
        path = ''
        city = ''
        
        button_1 = Entry(master, width = 50)
        button_1.insert(0, 'Enter apiID')
        button_1.pack(padx=5, pady=60, expand = True)

        button_2 = Entry(master, width = 30)
        button_2.insert(0, 'Enter City')
        button_2.pack(padx=5, pady=0)

        button_3 = Button(master, text='Start')
        button_3.pack(padx=5, pady=50)


    def SerialCommunication(self):
        #print(port, baudrate, bytesize)
        try:
            if serial.Serial(port=port, baudrate=baudrate, bytesize=bytesize, timeout=2, stopbits=serial.STOPBITS_ONE) == True:
                print('success')
            else:
                raise SerialException
        except:
            print('Error port configuration')

    def portConfiguration(self):

        label = ttk.Label(text='Select Baudrates')
        label.pack(padx=5, pady=5)
        button_1 = ttk.Combobox(master, values=bd_rates, textvariable = dflt_baudrate, state = 'readonly', width = 50)
        button_1.pack()

        label = ttk.Label(text='Select COM port')
        label.pack(padx=5, pady=5)
        button_2 = ttk.Combobox(master, values=[port for port in avail_ports.comports()], textvariable = dflt_port, state = 'readonly', width = 50)
        button_2.pack()

        label = ttk.Label(text='Select Byte size')
        label.pack(padx=5, pady=5)
        button_3 = ttk.Combobox(master, values=(2, 4, 8), textvariable = dflt_bytesize, state = 'readonly', width = 50)
        button_3.pack()
        #error in submitting


#add establish connection to arduino only
class Logic1(GUI):
    
    minute = 60
    defaultPath1 = 'C:/project/webjson.txt'
    defaultPath2 = 'C:/project/WeatherReport.txt'
    path = 'C:\project'
    
    def __init__(self):
        pass
    
    
    def readError(self):
        file = open(defaultPath1,'r')
        ch = file.read(24)
        ch = file.read(14)
        file.close()
        if ch=='city not found':
            return -1
        else:
            return 0

    def readFile(self): #read file and puts fomatted data on report file
        i = 0
        data = ['n']
        file = open(defaultPath1,'r');
        report = open(defaultPath2,'w+')
        while True:
            ch = file.read(1)
            if ch=='"':
                while True:
                    i = 1
                    ch1 = file.read(1)
                    if ch1=='"':
                        break
                    data.append(ch1)
            length = len(data)
            if length != 0:
                if data[i]=='t' or data[i]=='p' or data[i]=='h' or data[i]=='v' or data[i]=='s':
                    if data[i+1]=='e' or data[i+1]=='r' or data[i+1]=='p' or data[i+1]=='u' or data[i+1]=='i':
                        report.write('\n')
                        for j in data:
                            report.write(j)
                        file.read(1)
                        report.write(' ')
                        while True:
                            ch1 = file.read(1)
                            if ch1==',':
                                break
                            if ch1!='}':
                                report.write(ch1)
                                data.append(ch1)
            data.clear()
            data.append('n')
            i = 0
            if ch=='':
                break;
                
        file.close()
        report.seek(0)
        print(report.read())
        report.close()
        
    def StartCollectingData(self):
        os.system('mkdir '+path)
        while True:
            defaultAPIid = 'ee60421e0b2cc1c9782166ca2f79691e'
            res = requests.get(f'https://api.openweathermap.org/data/2.5/weather?q={city}&appid={apiID}')
            file = open(defaultPath1,'w');
            file.write(res.text) #print data on file
            file.close()
            if readError()==0: #identify error in reading while getting info if error is present then function readFile() will not initialize
                readFile()
                print('Data will refresh in an hour...')
                time.sleep(minute*60)
            else:
                print('Error invalid City name or apiID')


             
master = Tk()
master.title('weather-arduino')
master.geometry("750x450")
obj1 = GUI()
obj1.portConfiguration()
obj1.collectData()
obj1.SerialCommunication()


obj2 = Logic1()

obj2.startCollectingData()

master.mainloop()


