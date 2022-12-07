import sys
import os

import pytube as yt

'''
playlist
file video/playlist url -p/path path

file url
file -v/video url
file url path path
file -v url path path

file -p/playlist url
file -p/playslist url path path
'''

def start():
  
  error0 = 'error: wrong url or unstable internet connection.\n'
  
  def Download(vidORlist, url, path):
    print(vidORlist ,url ,path)
    print('downloading...')
    if vidORlist == 0:
      try:
        vid = yt.YouTube(url)
        vid.streams.get_highest_resolution().download(output_path=path)
      except:
        sys.exit(error0)
    elif vidORlist == 1:
      try:
        vid = yt.Playlist(url)
        for better in vid.videos:
          batter.streams.get_highest_resolution().download(output_path=path)
      except:
        sys.exit(error0)
    print('done.')
  
  length = len(sys.argv)
  if length > 4:
    sys.exit(f'error: excepts only 3 arguments {length} given')
    
  elif ('video' in sys.argv) or ('-v' in sys.argv) or length == 2:
    vidORlist = 0
    url = sys.argv[1]
    path = os.getcwd()
    if sys.argv[1] == 'video' or sys.argv[1] == '-v':
      url = sys.argv[2]
    if 'path' in sys.argv:
      if length == 4:
        path = sys.argv[3]
      elif length == 5:
        path = sys.argv[4]

  elif ('playlist' in sys.argv) or ('-p' in sys.argv):
    vidORlist = 1
    url = sys.argv[2]
    if 'path' in sys.argv:
      path = sys.argv[4]
    else:
      path = os.getcwd()
      
  Download(vidORlist, url, path)

start()
