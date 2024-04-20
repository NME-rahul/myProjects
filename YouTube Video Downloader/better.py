import sys
import os

import pytube as p
from pytube.cli import on_progress
from pytube.innertube import _default_clients

_default_clients["ANDROID_MUSIC"] = _default_clients["ANDROID_CREATOR"]

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

age_restric = '''is age restricted, and can't be accessed without logging in.'''


def getVideo(url, path, audio):
  try:
    vid = p.YouTube(url,
                  use_oauth = False,
                  allow_oauth_cache=True,
                  on_progress_callback=on_progress)
    print(vid.title, 'at', path, '\nViews:',vid.views)    
    if audio==True:
      out = vid.streams.filter(progressive=True, only_audio=True).desc().first().download()
      ConvInAudio(out)
    else:
      vid.streams.get_highest_resolution().download(output_path=path)
  except Exception as AgeRestrictedError:
    print(AgeRestrictedError)
  except Exception as RegexMatchError:
    print(RegexMatchError)
  except Exception as VideoUnavailableError:
    print(VideoUnavailableError)
    
def ConvInAudio(out):
  base, ext = os.path.splitext(out)
  audio = base + '.mp3'
  os.rename(out, audio)
    
def is_playlist(url):
  if url[20] == 'p':
    return True
  else:
    return False
    
def start(url, path, audio):
  if is_playlist(url) == False:
    getVideo(url, path, audio)
  else:
    playlist = p.Playlist(url)
    for url in playlist:
      print("\n")
      getVideo(url, path, audio)

if __name__ == '__main__':
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
  
  start(url, path, audio)
