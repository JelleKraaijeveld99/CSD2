import simpleaudio as sa
import time as time
import random as rdm

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

noteDurations = [0.25, 0.5, 0.25, 0.5, 0.5, 1, 1]

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
durationsToTimestamps16th(noteDurations)  
print(timeStamps16th)

#list for timestamps with actual time
timeStampsTime = []
#function for convertion timestamps in 16th notes to timestamps in actual time
def stamps16th_to_stampstime(x_bpm, y_ts16th):
    #calculating the value of a sixteenth note
    s_note = 15/x_bpm
    #for loop for adding the time values to a list
    for ts in y_ts16th:
        timeStampsTime.append(s_note*ts)

stamps16th_to_stampstime(default_bpm, timeStamps16th)
print(timeStampsTime)

#section in the code where the samples will be played in a certain sequence
#list for the samples
samples = [sa.WaveObject.from_wave_file("/Users/jellekraaijeveld/Documents/Samples/Major Kick 1-24b.wav")]

#variable for the time where the sequence has to start
start_time = time.time()
#variable that will hold the next timeStamp that has to be played
timestep = timeStampsTime.pop(0)
counter = 0
#while loop for playing the sequence 
while True:
  #var for storing the current time
  current_time = time.time()
  #check if the current time - the start time is bigger or even with the current time stamp from the timeStampsTime list. if so, play the sample
  if(current_time - start_time >= timestep):
    samples[0].play()

    # if there are timestamps left in the timestamps list
    if timeStampsTime:
      #if the list timeStampsTime still isn't empty, fill the timestamp var with the first float from the list
      timestep = timeStampsTime.pop(0)
    else:
      #if the list is empty break the loops 
      break
    
  else:
    # short wait to prevent we'll keep the processor busy when there's
    # nothing to do
    time.sleep(0.001)

time.sleep(1) # let the last 'note' ring out

    




    
    



