import simpleaudio as sa 
import random

samples = [sa.WaveObject.from_wave_file("../testsamples/testkick.wav"), 
           sa.WaveObject.from_wave_file("../testsamples/testclap.wav"),
           sa.WaveObject.from_wave_file("../testsamples/testtamb.wav") ] 

kick = sa.WaveObject.from_wave_file("../testsamples/testkick.wav")
clap = sa.WaveObject.from_wave_file("../testsamples/testclap.wav")
tambourine = sa.WaveObject.from_wave_file("../testsamples/testtamb.wav")

# playkick = kick.play().wait_done()
# playclap = clap.play().wait_done()
# playtambourine = tambourine.play().wait_done()

#list with timstamps
timestamps = [1,5,7,9,14,15]

#list with instruments; k, s, hh
instruments = ["k", "s", "hh"]

def eventmaker(ts, instr):
   #dictionary for making events 
   event_dict = {}
   #for loop for filling the dict
   for s in ts:
      event_dict[s] = instr
   return event_dict 


kickevents = eventmaker(timestamps, "k")
snareevents = eventmaker(timestamps, "s")
tambourineevents = eventmaker(timestamps, "t")

print(kickevents)
print(snareevents)
print(tambourineevents)





    




