import requests
import pandas as pd
import smtplib

import sys
import os

def read_user_info(path):
    df = pd.read_excel(path)
    numbers = str(df['Numbers']) #makes sure columns name matches with excel file
    emails = str(df['Emails'])  #makes sure columns name matches with excel file
    numberstring = ''
    emailstring = ''
    for i in numbers, :
        numberstring = numberstring + i + ','

    #del df; del numbers; del emails;

    return [numberstring, emailstring]

def send_email(emails, message):
    port = 465

    emailID = 'your gmail ID'
    password = 'Your gmail ID password'

    for email in emails:
        try:
            server = smtplib.SMTP('smtp.gmail.com', 587)
            server.starttls()
            server.login(emailID, password)

            server.sendmail(emailID, email, message)
            server.quit()
        except:
            break

        return False
        
    

def send_SMS(method, query):
    url = 'REST_API url'
    headers = {
        'cache-control': "no-cache"
    }
    try:
        response = request.request("Get", url, headers = headers, params = query)
        return True
    except:
        return False

def prepae_SMS(numbers, sms, language):
    apiKey = ""
    query = {
        "authorization": apiKey,
        "message": sms,
        "language": language,
        "route": 'q',
        "numbers": numbers
        }

    return query

if __name__ == '__main__':
    path = 'paste your default path for excel file'
    args_lenght = len(sys.argv)
    if args_lenght > 2:
        sys.exit('error: excepts only one parameter got ', args_lenght)
    elif args_lenght != 0:
        if os.path.isfile(path) == True:
            path = sys.argv[1]
    elif args_lenght == 0:
        if os.path.exists(path) == False:
            sys.exit('error: you default path for excel file does not exists')
        
    numbers, emails = read_user_info(path)

    msg = input('Write SMS to send: ')
    
    query = prepae_SMS(numbers, msg, language='english')

    error = '''error: something wents wrong.
                    check your internet connection or try again\n'''
    
    if send_SMS(method="Get", query=query, msg) != True:
        sys.exit(error)
    if send_email(emails, msg) != True:
        sys.exit(error)
    
    


