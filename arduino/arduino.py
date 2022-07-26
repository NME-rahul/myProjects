import serial
import serial.tools.list_ports as avail_ports

def port_configuration(port, baudrate, bytesize):
    try:
        if serial.Serial(port=port, baudrate=baudrate, bytesize=bytesize, timeout=2, stopbits=serial.STOPBITS_ONE) == True:
            print('success')
        else:
            raise SerialException
    except:
        print('Error port configuration')

dflt_port = 'COM1'
dflt_baudrate = 9600
dflt_bytesize = 2

while(True):
    port_configuration(dflt_port, dflt_baudrate, dflt_bytesize)



        
