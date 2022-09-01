'''
python fileName [-r] [time] [-cnt] url [--part] [--fromat]
python [-a] apiKey url [username] [password]
python [-cnt] urls [-t] [--format]

-r if recursive webscarping is needed
time recursive calling time
-cnt if cnt argumnet is given then it scrap from multiple urls
-part which part html page you need
--format if it is given then file save in given format otherwise in .
'''

#argv[0] is reserved for name of the file

import requests
import json

import sys

def CMD_Arguments():
    argc = len(sys.argv)
    arguments = list([])

    for i in range(1, argc):
        arguments.append(sys.argv[i])

    return [argc,arguments]

def fetch_Arguments(argc, argv):
    arguments = list([])
    for i in range(1, len(argv)):
        
        temp = argv[i]
        
        if temp >= 48 and temp <= 57:
            '''means multiple urls were given'''
            n = int(temp)
            #append number of urls
            arguments.append(n)
            #fetch urls and appned in list 'urls'
            urls = list([])
            for j in range(0, n):
                urls.append(argv[i+n+1])
            #append urls list
            arguments.append(urls)

        #append format of file
        if temp.spilit('-')[1]=='csv' or temp.spilit('-')[1]=='json':
            arguments.append(temp.spilit('-')[1])

    return arguments

    
def get_Data(arguments):
    if aruments[0] > 0:
        for i in range(0, arguments[0]):
            res = requests.get(str(aruments[0][i]))
            fp = open(f'/Users/rahulverma/desktop/data{i}.csv','w')
            fp.write(res.text)
            fp.close()
            if arguments[2] == 'json':
                fpr = open(f'/Users/rahulverma/desktop/data{i}.csv','w+')
                fpr.write(json.load(fpr))
                fpr.close()

argv = CMD_Arguments()
if argv[0] == 0:
    pass
else:
    arguments = fetch_Arguments(argv[0], argv[1])
    if len(arguments) > 0:
        get_Data(arguments)

        
