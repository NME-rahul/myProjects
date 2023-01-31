# YouTube Video Downloader


> Download Videos/Playlists from YouTube in seleted Resolution.


## Python Modules use:
* [pytube](https://pytube.io/en/latest/)
* [tkinter](https://docs.python.org/3/library/tk.html)
* [requests](https://pypi.org/project/requests/)
* [shutil](https://docs.python.org/3/library/shutil.html)


![Screenshot (36)](https://user-images.githubusercontent.com/100432854/182416015-32e9ae47-11a3-417f-bff9-d15479528eed.png)

---

# better.py is a command line tool for youtube video downloads, just type

    better.py [args1] url [args2]
    
   > args1:
     * video or -v
     * playlist or -p
     * audio or -a
    
   > args2:
     * -d with path
  
  <br><br>
    
* for video only

        better.py url
    
* for video only with specific path

        better.py url -d path
        
* for audio only

        better.py -a/audio url
        better.py -v/video -a/audio url
        
* for audio only with specific path

        better.py -a/audio url -d path
        better.py -v/video -a/audio url -d path
        
* for whole playlist

        better.py -p/playlist url
    
* for whole playlist with specific path

        better.py -p/playslist url -d path
        
* for whole playlist in audio only format

        better.py -p/playslist -a/audio url
        
* for whole playlist in audio only format

        better.py -p/playslist -a/audio url -d path
        
**Note:** if you found error(like below) with terminal prompt try by putting url within single quotes('').
> (base) rahulverma@Rahuls-MacBook-Air desktop % python better.py https://www.youtube.com/watch?v=o-7b6ctrQX0
zsh: no matches found: https://www.youtube.com/watch?v=o-7b6ctrQX0
