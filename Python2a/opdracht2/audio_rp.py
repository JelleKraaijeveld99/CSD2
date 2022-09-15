import simpleaudio as sa
import time as time

def rhytmicplayback(converted_list):
   # where is the sample?
   wave_obj = sa.WaveObject.from_wave_file("/Users/jellekraaijeveld/Documents/Samples/Grain.wav")
   
   #loop to play sample the asked amount of time 
   for seconds in converted_list:
      play_obj = wave_obj.play()
      time.sleep(seconds)
      stop_obj = play_obj.stop()
      stop_obj



