import sys
import os
import pytube as yt
import telebot as tb

Error0 = 'An Error Ocuured while Downloading video :('
Error1 = 'An unknown Error has benn occured :('

BOT_TOKEN = 'Paste Your Bot Token ID here.'

bot = tb.TeleBot(BOT_TOKEN)

def descrip(vid):
    try:
      text = vid.title +'<br>Views: ' + vid.views + '<br><br>Description:<br>' + vid.description
    except:
      pass
     
    return text      
     

def youTube(message):
    bot.send_message(message.chat.id, 'Hang On while video is downloading.')
    if message.text[20] != 'p':
        try:
            print('downloading...')
            bot.send_message(message.chat.id, descrip(vid), parse_mode='Markdown')
            vid = yt.YouTube(url)
            vid.streams.get_highest_resolution().download()
        except:
            bot.send_message(message.chat.id, Error0)
            
        try:
            document = open(os.getcwd() + vid.title + '.mp4', 'rb')
            bot.send_video(message.chat.id, document, supports_streaming=True)
        except:
            bot.send_message(message.chat.id, Error1)
        
    else:
        try:
            print('downloading...')
            vid = yt.Playlist(url)
            bot.send_message(message.chat.id, descrip(vid), parse_mode='Markdown')
            for better in vid.videos:
                better.streams.get_highest_resolution().download()
                try:
                    document = open(os.getcwd() + vid.title + '.mp4', 'rb')
                    bot.send_video(message.chat.id, document, supports_streaming=True)
                except:
                    bot.send_message(message.chat.id, Error1)
        except:
            bot.send_message(message.chat.id, Error0)
            

@bot.message_handler(commands=['download', 'Download'])
def download(message):
    msg = bot.send_message(message.chat.id, "Paste YouTube link")
    bot.register_next_step_handler(msg, youTube)
    
@bot.message_handler(commands=['start', 'hello'])
def send_welcome(message):
    bot.reply_to(message, "Hello, how are you doing?")

@bot.message_handler(commands=['info'])
def echo_all(message):
    bot.reply_to(message, 'This Bot is Developed by the https://github.com/NME-rahul', parse_mode='Markdown')
    
bot.infinity_polling()
