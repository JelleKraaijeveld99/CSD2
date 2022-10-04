import simpleaudio as sa 
import time as time 
import random 

#samples:
kick = sa.WaveObject.from_wave_file("../testsamples/testkick.wav")
clap = sa.WaveObject.from_wave_file("../testsamples/testclap.wav")
tambourine = sa.WaveObject.from_wave_file("../testsamples/testtamb.wav")

instrument_list = kick, clap, tambourine

#list for notedurations as input, will be converted to 16th timestamps 
note_durations = []

# var for how many times a sample has to be played
how_many_times = 0

#user input: bpm. First default bpm then the user can change the bpm
default_bpm = 60.

print("Hi, welcome to the single sample sequencer. This sequencer will start with a default bpm of",default_bpm,"\nYou can change the bpm later if you want")

# input the bpm 
while True:
    try:
        default_bpm = int(input("\nAt what BPM do you want the sequence to be played?\n"))
    except ValueError:
        print("\nSorry, can u please give a number")
    else: 
    #break stops the loop   
        break

# variable for how many times the sample will be played. Also some explaination about the note values, input can only be an int
while True:
    try:
        how_many_times = int(input("\nHow many times do you want to play a sample?\n"))
    except ValueError:
        print("Sorry, can u please give a number")
    else: 
    #break stops the loop   
        break 


print("\nOkay, I'll play the sample ", how_many_times, " times! But how long do you want each sample to be played? Let me explain the note durations; \n \nEigth note = 0.5 \nQuarter note = 1 \nHalf note = 1.5 \nEtc. \n " )

# loop to ask the duration of the notes
for indx in range(how_many_times):
    while True:
        try:
            value = float(input("Add note value: "))
            note_durations.append(value)
        except ValueError:
            print("Sorry, can u please give a number")
        else: 
            #break stops the loop   
            break 

#function for converting durations to timestamps, also convert noteDurations where 1 is a quarter note to stamps where 1 is a sixteenth note
def durationsToTimestamps16th(x_noteDur):
    # sum for adding up all the noteDuration values
    sum = 0
    timeStamps16th.append(0)
    for x in range(len(x_noteDur)-1):
        sum = int(sum) + int(x_noteDur[x] * 4)
        timeStamps16th.append(sum)

#list for timestamps in 16th notes
timeStamps16th = []
#function for converting noteDurations to timeStamps16th
durationsToTimestamps16th(note_durations)  

#list for timestamps with actual time
timestamps_time = []

#function for convertion timestamps in 16th notes to timestamps in actual time
def stamps16th_to_stampstime(x_bpm, y_ts16th):
    #calculating the value of a sixteenth note
    s_note = 15/x_bpm
    #for loop for adding the time values to a list
    for ts in y_ts16th:
        timestamps_time.append(s_note*ts)

stamps16th_to_stampstime(default_bpm, timeStamps16th)

#list for the events
event_list = []

#function for making events according to the timestamps and instruments
def event_maker(t_stamp, instrument):
    for x in range(len(t_stamp)):
           event_list.append({'timestamp': t_stamp[x], 'instrument': instrument[random.randint(0,2)]})

event_maker(timestamps_time, instrument_list)

#section of the code for the audio playback
start_time = time.time()

#var for popping an event from the event_list
event = event_list.pop(0)

#while loop for playing the sequence 
while True:
    #var for storing current time 
    current_time = time.time()
    #check if the event has to be played
    if(current_time - start_time >= event['timestamp']):
        event['instrument'].play()
        #replace the event var with the next event in the list and check if there are events left in the event_list
        if(event_list):
            event = event_list.pop(0)
        #if there are no events left in the list break the loop
        else:
          break

    else:
      time.sleep(0.001)    

time.sleep(1)