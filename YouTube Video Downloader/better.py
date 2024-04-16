import sys
import os

import pytube as yt

'''
file url
file url path

file url -a/audio
file url -a/audio path
'''

args = '''
* for video only

        better.py url
    
* for video only with specific path

        better.py url path
        
* for audio only

        better.py url -a/audio
        
        
* for audio only with specific path

        better.py url -a/audio path
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

  def Download(url, path, audio):

    error0 = 'error: wrong url or unstable internet connection.\n'

    if os.path.exists(path + '/highest_resolution/')==False:
      os.mkdir(path + '/highest_resolution/')
    
    def is_playlist(url):
        if url[20] == 'p':
            return True
        else:
            return False

    print('downloading...')
    if is_playlist(url) == False:
      try:
        vid = yt.YouTube(url)
        descrip(vid)
        if audio==True:
          out = vid.streams.filter(only_audio=True).desc().first().download()
          ConvInAudio(out)
        else:
          vid.streams.filter(file_extension='mp4').order_by('resolution').desc().first().download(output_path=path + '/highest_resolution/' )
          vid.streams.get_highest_resolution().download(output_path=path)
      except:
        sys.exit(error0)

    else:
      vid = yt.Playlist(url)
      descrip(vid)
      if audio==True:
        for better in vid.videos:
          print(better.title, 'at', path, 'in', 'audio', 'format')
          out = better.streams.filter(only_audio=True).desc().first().download()
          ConvInAudio(out)
      else:
        for better in vid.videos:
          print(vid.title, 'at', path, 'in', 'video', 'format')
          #better.streams.filter(file_extension='mp4').order_by('resolution').desc().first().download(output_path=path + '/highest_resolution/' )
          better.streams.get_highest_resolution().download(output_path=path)
        
    print('\Download Completed.')
  
  length = len(sys.argv)
  if length > 4:
    sys.exit(f'error: excepts only 4 arguments {length} given')

  elif length > 1:
    url = sys.argv[1]
    path = os.getcwd()
    audio = False

    if length==3:
        if sys.argv[2]=='-a' or sys.argv[2]=='audio':
            audio = True
        else:
            path = sys.argv[2]

    elif length==4:
      if sys.argv[2]=='-a' or sys.argv[2]=='audio':
        audio = True
        path = sys.argv[3]

  else:
    sys.exit(f'Error: No argumnets were arguments given.\n{args}\n')
  
  Download(url, path, audio)

start()
