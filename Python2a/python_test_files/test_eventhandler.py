from optparse import AmbiguousOptionError
from re import T
import simpleaudio as sa 
import random
import operator

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
timestamps_kick = [0,4,8,12]
timestamps_snare = [3,7,11,15]
timestamps_tambourine = [1,5,9,13]

#list with instruments; k, s, hh
instruments = ["k", "s", "hh"]

#function for making events with any instrument you would like, the key var makes sure
#that the dicts you create dont have the same key values.
def eventmaker(ts, instr, key):
   #dictionary for making events 
   event_dict = {}
   #for loop for filling the dict
   for s in range(len(ts)):
      # variable for not having the same keys, input is list length 
      x = s + key 
      event_dict[x] = ts[s], instr
   return event_dict 

#using the new function "eventmaker"
kickevents = eventmaker(timestamps_kick, "k", 0)
snareevents = eventmaker(timestamps_snare, "s", len(timestamps_kick))
tambourineevents = eventmaker(timestamps_tambourine, "t", (len(timestamps_kick)+len(timestamps_snare)))

#print the kick events 
print("kickevents:",kickevents)
print('snareevents:',snareevents)
print('tambourineevents:', tambourineevents)

#merge the 3 lists together 
kickevents.update(snareevents)
kickevents.update(tambourineevents)
all_events_dict = kickevents 

x = all_events_dict

#sort them in the right order (ascending) based on the first value (timestamp) of a key 

# time_step = all_events.pop(0)
# print(time_step)

print('this is the merged dict:', x)






    




