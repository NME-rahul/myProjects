#standard libraries
import time

#for getting thumbnail
import requests

#for downloading YouTube video
from pytube import YouTube

#to save file locally
import shutil

#for creating gui
from tkinter import ttk
from tkinter import *
from PIL import ImageTk, Image
import tkinter.messagebox as tk_msg
from tkinter.ttk import Progressbar


master = Tk()
master.geometry('700x700')
master.title('YouTube Video Downloader')
master.title()
#set master window icon
icon = PhotoImage(file='icon.png')
master.iconphoto(True, icon)
#setting background image
'''background = ImageTk.PhotoImage(Image.open('blue-and-brown-abstract-painting--wallpaper.jpg'))
label = Label(master, image=background)
label.place(x=0, y=0)'''


link = StringVar()
extension = StringVar()
fps = StringVar()
resolution = StringVar()
cnt = 0


def Downloader():
    msg_err_downloader = ''
    num = 0
    try:
        url = YouTube(str(link.get()))
        msg_err_downloader = 'Success'
    except:
        try:
            url = Playlist(str(link.get()))
            num = len(url.video_urls)
            msg_err_downloader = 'Success'
        except:
            tk_msg.showinfo('Error', msg_err_downloader)
            msg_err_downloader = 'Connection Error to YouTube\n\t   or\nCheck the url and try again'
            tk_msg.showinfo('Error', msg_err_downloader)

    def buttons(cnt):
        if cnt == 0:
            #select file extension
            Label(text='Select video Extension', bg='white').pack(padx=0, pady=5)
            avail_extension = ['mp4', 'mp3'] #avaiable extensions
            ttk.Combobox(master, values = avail_extension, textvariable = extension, state = 'readonly', width = 50).pack(padx=5, pady=5)
            #select Resolution
            Label(text='Select video Resolution', bg='white').pack(padx=0, pady=5)
            #avail_resolution = ['144p', '240p', '360p', '480p', '720p', '1080p', '1440p', '2160p']
            ttk.Combobox(master, values = [stream.resolution for stream in url.streams.filter(progressive=True).all()],  textvariable = resolution, state = 'readonly', width = 50).pack(padx=5)
            #select FPS
            Label(text='Select file FPS', bg='white').pack(padx=0, pady=5)
            button_1 = ttk.Combobox(master, values = [stream.fps for stream in url.streams.filter(progressive=True).all()], textvariable = fps, state = 'readonly', width = 50).pack(padx=5)
            #show description of video
            text = Text(master, width=80, height=10, bg='white')
            text.pack(padx=5, pady=10)
        if cnt != 0:
            text.delete(0, END)
        text.insert(END, 'Ratings: ' + str(url.rating))
        text.insert(END, '\nViews: ' + str(url.views))
        text.insert(END, '\n\nDescription: \n' + str(url.description))
        cnt = cnt + 1
    
    def ShowThumbnail(msg):
        if msg == 'Success':
            try:
                thumbnail = Tk()
                thumbnail.title('Thumbnail')
                temp = ImageTk.PhotoImage(Image.open(filename))
                label = Label(thumbnail, image=temp)
                label.place(x=0, y=0)
                thumbnail.mainloop()
            except:
                tk_msg.showinfo('Error', 'Error: Unable to open thumbnail of video')
                        
    def VideoInfo():
        msg_err_VideInfo = ''
        try:
            thumbnail = url.thumbnail_url
            res = requests.get(thumbnail, stream=True)
            msg_err_VideInfo = 'Success'
        except:
            msg_err_VideInfo = 'Error Internet Connection'
            tk_msg.showinfo('Error', msg_err_VideInfo)

        if msg_err_VideInfo == 'Success':
            if res.status_code == 200:
                filename = thumbnail.split('/')[-1]
                res.raw.decode_content = True
                try:
                    with open(filename, 'wb') as f:
                        shutil.copyfileobj(res.raw, f)
                except:
                    tk_msg.showinfo('Error', 'OS Error: Unable to open file')
            return msg_err_VideInfo;
                

    def Download():
        if num == 0:
            try:
                #url.streams.filter( progressive=True, file_extension=extension.get(), res=resolution.get(), fps=fps.get()).first().download()
                url.streams.get_highest_resolution().download()
                tk_msg.showinfo('info', 'Download SuccessFully')
            except:
                tk_msg.showinfo('Error', 'Error while Downloading')
        else:
            try:
                for video in url.videos:
                    video.streams.get_highest_resolution().download()
                    tk_msg.showinfo('info', 'Download SuccessFully')
            except:
                tk_msg.showinfo('Error', 'Error while Downloading')
            
    
    if msg_err_downloader == 'Success':
        buttons(cnt)
        msg = VideoInfo(); ShowThumbnail(msg)
        Button(master, text='Download', padx=2, command=Download).pack(padx=5, pady=10)


def start():
    Label(master, text='Paste your link here', bg='white').pack(padx=230, pady=5)
    link_enter = Entry(master, width=90, textvariable=link, bg='white').pack(padx=5, pady=5)
    Button(master, text='Start', padx=2, command=Downloader).pack(padx=5, pady=10)
    #Button(master, text='Playlist', padx=2, command=Downloader).pack(padx=5, pady=10)
    

start()
  
master.mainloop()
