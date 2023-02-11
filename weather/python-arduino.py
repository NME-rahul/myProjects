#standard libraries
import time
import os

#for webscarping
import json
import requests

#for Serial Communication
import serial
import serial.tools.list_ports as avail_ports

#for GUI
from tkinter import *
import tkinter.messagebox as tk_msg
from tkinter import ttk

#create main window
master = Tk()
master.title('weather-arduino')
master.geometry("600x550")

v = Scrollbar(master)
h = Scrollbar(master, orient='horizontal')
v.pack(side=RIGHT, fill=Y); h.pack(side=BOTTOM, fill=X)
text = Text(master, height = 10, width = 50, bg='light cyan', xscrollcommand=h.set, yscrollcommand=v.set)
v.config(command=text.yview)
v.config(command=text.xview)
text.pack(pady = 20)


dflt_port = StringVar()
dflt_baudrate = StringVar()
dflt_bytesize = StringVar()

apiID = StringVar()
city = StringVar()

minute = 60

#establish connection to arduino only
class SerialCommunication:
    
    msg_configuration = 'Error port configuration' 

    def __init__(self):
        pass

    def portConfiguration(self, dflt_port):
        temp = str(dflt_port.get())
        temp = temp.split(' ')
        temp = temp[0]
        
        try:
            self.arduino = serial.Serial(port=temp, baudrate=int(dflt_baudrate.get()), bytesize=int(dflt_bytesize.get()), timeout=2, stopbits=serial.STOPBITS_ONE)
            msg_configuration = 'Success port configuration'
        except:
           self.msg_configuration = 'Error port configuration'
        finally:
            text.insert(END, self.msg_configuration + '\n')
           

class ReadJSON(SerialCommunication):

    defaultPath = os.getcwd() + '/weatherReport.txt'

    msg = ''

    coord={}; weather={}; main={}; wind={}; clouds={}; sys={}; timezone={}
    
    def __init__(self, msg, city, apiID):
        temp1 = str(city.get()); temp2 = (apiID.get())
        if temp1 == 'Enter City' or temp2 == 'Enter apiID':
            temp1 = 'jaipur'; 
            temp2 = '2dca9d02f559a8be28aefe42ef5ce3a8';
            
        self.msg = msg
        
        try:
            self.res = requests.get(f'https://api.openweathermap.org/data/2.5/weather?q={temp1}&appid={temp2}').text
        except:
            self.msg = 'Error Internet Connection'
        finally:
            text.insert(END, self.msg + '\n\n')
            
        if self.msg == 'ok':
            self.data = json.loads(self.res)

            self.fp = open(self.defaultPath,'w+')
            #os.system('date > '+self.defaultPath); os.system('time  > '+self.defaultPath);
            self.fp.write(self.res)
            self.fp.write('\n\n')
            self.fp.close()

    def extract_values(self):
        self.coorf=self.data['coord']; self.weather=self.data['weather']; self.main=self.data['main']; self.wind=self.data['wind']; self.sys=self.data['sys'];

        text.insert(END,'Timezone: ' +str(self.data['timezone']) + '\n')
        text.insert(END,'ID: ' +str(self.data['id']) + '\n')
        text.insert(END,'name: ' +str(self.data['name']) + '\n')
        
        for i,j in self.coord.items():
            text.insert(END, '\n' + i + ': ');text.insert(END,j)
            
        self.weather = self.weather[0]
        for i,j in self.weather.items():
            text.insert(END, '\n' + i + ': ');text.insert(END,j)
            
        for i,j in self.main.items():
            text.insert(END, '\n' + i + ': ');text.insert(END,j)
            
        text.insert(END, '\nvisibility: '+str(self.data['visibility'])+'\n\nWind- ')
        
        for i,j in self.wind.items():
            text.insert(END, '\n' + i + ': ');text.insert(END,j)
            
        text.insert(END, '\nClouds- '+str(self.data['clouds'])+'\n')
        
        for i,j in self.sys.items():
            text.insert(END, '\n' + i + ': ');text.insert(END,j)
        

    def read(self):
        if self.msg == 'ok':
            for i in self.data:
                if i == 'message':
                    self.msg = 'error'

            if self.msg == 'error':
                if self.data['message'] == 'Invalid API key. Please see http://openweathermap.org/faq#error401 for more info.':
                    text.insert(END, self.data['message'] + '\n')
                    
                elif self.data['message'] == 'city not found':
                    text.insert(END, self.data['message'] + '\n')
            else:
                self.extract_values();

    def read_writeArduino(self):
        if self.msg_configuration == 'Success port configuration':
            if self.msg == 'ok':
                x = self.data['main']
                self.arduino.write(bytes(x['temp'], 'utf-8'))
                          

def initiate():
      initiate_msg = 'Start'
      text.delete("1.0","end")
      text.insert(END, 'Port: ' + dflt_port.get() + '\n' )
      text.insert(END, 'Baudrate: ' + dflt_baudrate.get() + '\n' )
      text.insert(END, 'Bytesize: ' + dflt_bytesize.get())

      obj2 = SerialCommunication()
      obj2.portConfiguration(dflt_port)

      #while(True):
      obj3 = ReadJSON('ok', city, apiID)
      obj3.read()
      obj3.read_writeArduino()
      #time.sleep(1*minute)

def create_Buttons():
   bd_rates = (110, 300, 600, 1200, 2400, 4800, 9600, 14400, 19200, 38400, 57600, 115200, 128000, 256000)
        
   label = ttk.Label(text='Select Baudrates')
   label.pack(padx=5, pady=5)
   button_1 = ttk.Combobox(master, values = bd_rates, textvariable = dflt_baudrate, state = 'readonly', width = 50)
   button_1.pack()

   label = ttk.Label(text='Select COM port')
   label.pack(padx=5, pady=5)
   button_2 = ttk.Combobox(master, values = [port for port in avail_ports.comports()], textvariable = dflt_port, state = 'readonly', width = 50)
   button_2.pack()

   label = ttk.Label(text='Select Byte size')
   label.pack(padx=5, pady=5)
   button_3 = ttk.Combobox(master, values=(2, 4, 8), textvariable = dflt_bytesize, state = 'readonly', width = 50)
   button_3.pack()

   button_4 = Entry(master, width = 50, textvariable = apiID)
   button_4.insert(0, 'Enter apiID')
   button_4.pack(padx=5, pady=20)
   button_5 = Entry(master, width = 30, textvariable = city)
   button_5.insert(0, 'Enter City')
   button_5.pack(padx=5, pady=0)

   button_6 = Button(master, text='Start', command = initiate)
   button_6.pack(padx=5, pady=20)


create_Buttons()

#last
master.mainloop()
