import sys
import os
import pytube as yt
import telebot as tb

import thread

Error0 = 'An Error Ocuured while Downloading video :('
Error1 = 'An unknown Error has benn occured :('

BOT_TOKEN = 'paste your bot token here.'

bot = tb.TeleBot(BOT_TOKEN)

def descrip(vid):
    try:
      text = vid.title +'\nViews: ' + vid.views + '\nDescription:\n' + vid.description
    except:
      pass
     
    return text      
     
def sendVideos(message, vid):
    try:
        document = open(os.getcwd() + vid.title + '.mp4', 'rb')
        bot.send_video(message.chat.id, document, supports_streaming=True)
    except:
        bot.send_message(message.chat.id, Error1)

def youTube(message):
    bot.send_message(message.chat.id, 'Hang On while video is downloading.')
    if (message.text[20] + message.text[21] + message.text[22] +  message.text[23]) != 'play':
        try:ss
            print('downloading...')
            bot.send_message(message.chat.id, descrip(vid), parse_mode='Markdown')
            vid = yt.YouTube(url)
            vid.streams.get_highest_resolution().download()
            sendVideos(message, vid)
        except:
            bot.send_message(message.chat.id, Error0)
            
    else:
        try:
            print('downloading...')
            vid = yt.Playlist(url)
            bot.send_message(message.chat.id, descrip(vid), parse_mode='Markdown')
            for better in vid.videos:
                better.streams.get_highest_resolution().download()
                sendVideos(message, better)
        except:
            bot.send_message(message.chat.id, Error0)

def checkLink(message):
    msg = message.text.lower()
    if (msg[0]+ msg[1] + msg[2]+ msg[3] + msg[4] == 'https') and (msg[8]+ msg[9]+ msg[10] + msg[11]+ msg[12] + msg[13] + msg[14] == 'youtube') == True:
        youTube(message)
    else:
        bot.send_message(message.chat.id, 'Provided link is not a YouTube link.')        

@bot.message_handler(commands=['download', 'Download'])
def download(message):
    msg = bot.send_message(message.chat.id, "Paste YouTube link")
    bot.register_next_step_handler(msg, checkLink)
    
@bot.message_handler(commands=['start', 'hello'])
def send_welcome(message):
    bot.reply_to(message, '''Finaly, revived again!\nExcited to help You. Want YouTube videos?\nTape on /download.''')

@bot.message_handler(commands=['info'])
def echo_all(message):
    bot.reply_to(message, 'This Bot is Developed by the [NME-rahul](https://github.com/NME-rahul)', parse_mode='Markdown')
    
bot.infinity_polling()
