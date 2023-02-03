import sys
import os

import pytube as yt

'''
file url
file url -d path

file -a/audio url
file -a/audio url -d path

file -v/video -a/audio url
file -v/video -a/audio url -d path

file -p/playlist url
file -p/playslist url -d path

file -p/playslist -a/audio url
file -p/playslist -a/audio url -d path

file video(-v)/playlist[-p] audio(-a) url -d path
'''

def start():
  def descrip(vid):
    try:
      print(vid.title, 'at', path, 'in', extension, 'format', '\nViews: ',vid.views, '\n\nDescription:\n',vid.description)
      caption = vid.caption
      if bool(caption) != False:
        fp = open(f'Captions {vid.title}.srt', 'w')
        fp.write(caption.get_by_language_code('en').generate_srt_captions())
    except:
      pass

  def ConvInAudio(out):
    base, ext = os.path.splitext(out)
    audio = base + '.mp3'
    os.rename(out, audio)

  def Download(vidORlist, url, path, extension):

    error0 = 'error: wrong url or unstable internet connection.\n'

    if os.path.exists(path + '/highest_resolution/')==False:
      os.mkdir(path + '/highest_resolution/')

    print('downloading...')
    if vidORlist == 0:
      try:
        vid = yt.YouTube(url)
        descrip(vid)
        if extension=='mp3':
          out = vid.streams.filter(only_audio=True).desc().first().download()
          ConvInAudio(out)
        else:
          vid.streams.filter(file_extension='mp4').order_by('resolution').desc().first().download(output_path=path + '/highest_resolution/' )
          vid.streams.get_highest_resolution().download(output_path=path)
      except:
        sys.exit(error0)

    elif vidORlist == 1:
      vid = yt.Playlist(url)
      descrip(vid)
      if extension=='mp3':
        for better in vid.videos:
          print(better.title, 'at', path, 'in', extension, 'format')
          out = better.streams.filter(only_audio=True).desc().first().download()
          ConvInAudio(out)
      else:
        for better in vid.videos:
          print(vid.title, 'at', path, 'in', extension, 'format')
          #better.streams.filter(file_extension='mp4').order_by('resolution').desc().first().download(output_path=path + '/highest_resolution/' )
          better.streams.get_highest_resolution().download(output_path=path)
        
    print('\Download Completed.')
  
  length = len(sys.argv)
  if length > 6:
    sys.exit(f'error: excepts only 4 arguments {length} given')

  elif length > 1:
    url = sys.argv[1]
    path = os.getcwd()
    vidORlist = 0
    extension = 'nonAudio'

    if length==6:
      path = sys.argv[5]
      url = sys.argv[3]
      extension = 'mp3'

    elif length==5:
      path = sys.argv[4]
      url = sys.argv[2]
      if sys.argv[1]=='-a' or sys.argv[1]=='audio':
        extension = 'mp3'
      elif sys.argv[1]=='-p' or sys.argv[1]=='playlist':
        vidORlist = 1

    elif length==4:
      url = sys.argv[3]
      if sys.argv[2]=='-a' or sys.argv[2]=='audio':
        extension = 'mp3'
      elif sys.argv[2] == '-d':
        path = sys.argv[2]
      if sys.argv[1]=='-p' or sys.argv[1]=='playlist':
        vidORlist = 1

    elif length==3:
      url = sys.argv[2]
      if sys.argv[1]=='-a' or sys.argv[1]=='audio':
        extension = 'mp3'
      elif sys.argv[1]=='-p' or sys.argv[1]=='playlist':
        vidORlist = 1
        url = sys.argv[2]
  else:
    sys.exit('Error: No argumnets were arguments given.')
  
  Download(vidORlist, url, path, extension)

start()
