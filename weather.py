import requests
import time
import os

minute = 60

def readError():
    file = open(defaultPath1,'r')
    ch = file.read(24)
    ch = file.read(14)
    file.close()
    if ch=='city not found':
        return -1
    elif ch=='Invalid API ke':
	    return -2
    else:
        return 0

def readFile(): #read file and puts fomatted data on report file
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
    

defaultPath1 = 'C:/project/webjson.txt'
defaultPath2 = 'C:/project/WeatherReport.txt'
path = 'C:\project'
    
print('''You can access your city weather report on path: C:/project/WeatherReport.txt
or in JSON form on path: C:/project/webjson.txt ''')
os.system('mkdir '+path)

while True:
    apiID = '0'
    city = input("\nEnter City Name: ")
    defaultAPIid = 'ee60421e0b2cc1c9782166ca2f79691e'
    api = input("Enter API(if not available enter 0): ")
    if apiID =='0':
        apiID = defaultAPIid

    res = requests.get(f'https://api.openweathermap.org/data/2.5/weather?q={city}&appid={apiID}')
    file = open(defaultPath1,'w');
    file.write(res.text) #print data on file
    file.close()
    error = readError()
    if error==0: #identify error in reading while getting info if error is present then function readFile() will not initialize
        readFile()
        print('Data will refresh in an hour...')
        time.sleep(minute*60)
    elif error==-1:
        print('Error invalid City name')
    elif error==-2:
	    print('Error invalid apiID')
    