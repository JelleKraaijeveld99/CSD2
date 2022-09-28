import random

#a list with instruments
instrument_list = ["snare:","kick:","hi-hat:"]
#a list with events
event_list = [0.5, 0.7, 1, 1.6, 1.7]
#a dictionary that needs to be filled 
this_dict = {}

for ts in event_list:
    this_dict[ts] = instrument_list[random.randint(0, 2)]

print(this_dict)
