import simpleaudio as sa 
import time as time 
import random 
from midiutil import MIDIFile

#samples:
kick = sa.WaveObject.from_wave_file("../testsamples/testkick.wav")
clap = sa.WaveObject.from_wave_file("../testsamples/testclap.wav")
tambourine = sa.WaveObject.from_wave_file("../testsamples/testtamb.wav")

#list for the samples 
instrument_list = kick, clap, tambourine

#user input: bpm, amount of bars and time signature ----> 1 = 5/4 and 2 = 7/8
default_bpm = 60
bars_amount = 4
time_signature = 0

#communication with user
print("\nHi, welcome to the irregular beat generator. This program will generate an irregular beat according to a given BPM, amount of bars and either a 5/4 or a 7/8 time signature. Lets start!\n")

# input the bpm 
retrieve_bpm = True
while retrieve_bpm:
    try:
        default_bpm = int(input("\nAt what BPM do you want the sequence to be played? Please give a number between 50 and 180\n"))
    except:
        print("\nSorry, can u please give a number between 50 and 180")
    else: 
        if default_bpm in range(50,181):
            retrieve_bpm = False
        else:
         print("\nSorry, can u please give a number between 50 and 180")

#input the amount of bars
retrieve_bars = True
while retrieve_bars:
    try:
        bars_amount = int(input("\nHow many bars do you want to be generated? Please give a number between 0 and 16\n"))
    except:
        print("\nSorry, can u please give a number between 0 and 8")
    else:
        if bars_amount in range(0,9):
            retrieve_bars = False
        else:
         print("\nSorry, can u please give a number between 0 and 8")

#input the time signature 
retrieve_time_signature = True
while retrieve_time_signature:
    try:
        time_signature = int(input("\nWhat time signature do you want to use? Press 1 for a 5/4 time signature or press 2 for a 7/8 time signature.\n"))
    except:
        print("\nSorry, can u please give the number 1 or 2")
    else: 
        if time_signature == 1 or time_signature == 2:
            retrieve_time_signature = False
        else: 
         print("\nSorry, can u please give the number 1 or 2")

########## section for generating rhythms ###########  

#function for amount of eigtht notes according to the time signature 
def time_sign_to_notes(signature):
    #check if the time signature is 5/4
    if signature == 1:
        eighth_notes = 10
        return eighth_notes
    #check if the time signature is 7/8
    if signature == 2: 
        eighth_notes = 7 
        return eighth_notes

#variable for storing the amount of eigtht notes per bar
amount_of_notes = time_sign_to_notes(time_signature)

#function for generating euclidean rhythms 
def euclidean_gen(num_pulses, num_notes, offset):
    # calculate duration of a note, expressed in eight notes
    note_dur = int(num_pulses / num_notes)
    # fill list num_notes times with the duration value
    sequence = [note_dur] * num_notes
    
    rest_value = num_pulses - (num_notes * note_dur)
    for i in range(rest_value):
        sequence[i] += 1    

    #summing up all the notes and converting them to durations
    timestamp_sequence = []
    sum = 0
    timestamp_sequence.append(0)
    for x in range(len(sequence)-1):
        sum = int(sum) + int(sequence[x])
        timestamp_sequence.append(sum)
    
    #section for offset 
    timestamp_sequence = [x+offset for x in timestamp_sequence] #add the offset value to every dur in the list   
    
    #modulo all the new values in the list based on the maximum amount of possible notes
    for i in range(len(timestamp_sequence)):
        timestamp_sequence[i] = timestamp_sequence[i] % num_pulses
    
    #sort all the values in the right order from low to high
    timestamp_sequence.sort()
    return timestamp_sequence

kick_pattern = euclidean_gen(amount_of_notes,random.randint(1,5),0) #starting with an offset of 0 so the rhythm always starts with a kick
clap_pattern = euclidean_gen(amount_of_notes,random.randint(1,5), random.randint(2,6)) #starting with an random offset between 2 and 6 so the clap will always be after the kick in the first bars
tambourine_pattern = euclidean_gen(amount_of_notes,random.randint(3,amount_of_notes - 3), random.randint(0,5))

#function for making variations (after a customizable amount of bars) for the original generated rhythm
def rhythm_bars(eucl_list, bars, note_amount):
    buffer_list = eucl_list # a list i use to store a rhythm + the amount of bars we are in right now
    refrence_list = eucl_list # a list i use to store the imput rhythm, after 4 bars i change this to the imput rhythm + offset
    complete_eucl = [] # a list for returning a list with the complete rhythm
    
    for i in range(bars):
        if (i % 2 == 0) and (i != 0): #after every 4 bars make a variation but not the first 4 bars
            offset = random.randint(1,(note_amount*2)-1)#generating an random offset in the range 1 to 2 times the amount of notes 
            buffer_list = [x + offset for x in eucl_list] #the original values of eucl_list with an offset

            for x in range(len(buffer_list)): #for loop with modulo for making offset
                buffer_list[x] = buffer_list[x] % note_amount 
            buffer_list.sort() #
            refrence_list = buffer_list #store the rhythm + offset (new rhythm) in a variable
            #add the rhythm + the bar we in to the complete_eucl list
            buffer_list = [x + i*note_amount for x in buffer_list]
            complete_eucl.extend(buffer_list)
    
        else:
            buffer_list = [x + i*note_amount for x in refrence_list]
            complete_eucl.extend(buffer_list)

    return complete_eucl

total_rhythm_tb = rhythm_bars(tambourine_pattern, bars_amount, amount_of_notes)
total_rhythm_k = rhythm_bars(kick_pattern, bars_amount, amount_of_notes)
total_rhythm_c = rhythm_bars(clap_pattern, bars_amount, amount_of_notes)

#section for converting ts to durations so i can export to midi later on 
def ts_to_dur_list(ts_list,x_bpm):
    #empty list for durations
    dur_list = []

    #duration in of an eigtht note in ms:
    e_note = 30000/x_bpm

    #reverse the ts list to avoid index error in the for loop
    ts_list.reverse()

    # subtract 2 consecutive values in the ts_list to calculate the difference in value between them. This must be the duration
    for i in range(len(ts_list)-1):
        dur_note = ts_list[i] - ts_list[i+1]
        dur_list.append(dur_note * e_note)
    
    #add the last timestamp value (which is the first because i reversed the list) to the duration list. 
    dur_list.insert(0, 1*e_note)
    
    
    #now reverse the duration list so all the durations are in the right order again. 
    dur_list.reverse()

    return dur_list

all_dur_tb = ts_to_dur_list(total_rhythm_tb, default_bpm)
all_dur_k = ts_to_dur_list(total_rhythm_k, default_bpm)
all_dur_c = ts_to_dur_list(total_rhythm_c, default_bpm)
dur_combined = all_dur_tb + all_dur_c + all_dur_c


#function for convertion timestamps in 8th notes to timestamps in actual time
def stamps8th_to_stampstime(x_bpm, y_ts_8th):
    time_stamps_time = []
    #calculating the value of an eigtht note
    e_note = 30/x_bpm
    #for loop for adding the time values to a list
    for ts in y_ts_8th:
        time_stamps_time.append(e_note*ts)
    return time_stamps_time

timestamps_k = stamps8th_to_stampstime(default_bpm, total_rhythm_k)
timestamps_c = stamps8th_to_stampstime(default_bpm, total_rhythm_c)
timestamps_tb = stamps8th_to_stampstime(default_bpm, total_rhythm_tb)
 
#function for making events according to the timestamps and a random instrument from the instrument list, also give to instruments a midinote value for exporting midi
def event_maker(t_stamp, sample, durations, instrument, midinote):
    event_list = []
    for x in range(len(t_stamp)):
           event_list.append({'timestamp': t_stamp[x], 'sample': sample, 'duration': durations[x], 'instrument': instrument, 'midinote': midinote })
    return event_list

#making a list with events with the funtion event_maker
kick_events = event_maker(timestamps_k, kick, all_dur_k, 'kick', 36)
clap_events = event_maker(timestamps_c, clap, all_dur_c, 'clap', 39)
tambourine_events = event_maker(timestamps_tb, tambourine, all_dur_tb, 'tambourine', 44)


#section for adding all the events together and sorting them in the right order according to the timestamp value
all_events = kick_events + clap_events + tambourine_events

all_events = sorted(all_events, key=lambda x: x['timestamp'])

#copy the eventlist so i can still use the events if the user wants to output MIDI
all_events_buffer = list(all_events)

# print("after the sort:", all_events)
print("all events here:", all_events)
#section of the code for the audio playback
start_time = time.time()

#var for popping an event from the event_list
event = all_events.pop(0)

#while loop for playing the sequence 
while True:
    #var for storing current time 
    current_time = time.time()
    #check if the event has to be played
    if(current_time - start_time >= event['timestamp']):
        event['sample'].play()
        #replace the event var with the next event in the list and check if there are events left in the event_list
        if(all_events):
            event = all_events.pop(0)
        #if there are no events left in the list break the loop
        else:
          break

    else:
      time.sleep(0.001)    

time.sleep(1)


#section in the code for MIDI
midi_output = 'no'
retrieve_midi = True

while retrieve_midi:
    matches = ['yes', 'Yes', 'y', 'Y', 'YES', 'no', 'No', 'n', 'N', 'NO']

    try:
        midi_output = str(input("\nDo you want to export the rhythm you just heard to MIDI? Type yes or no.\n"))
    except:
        print("\nSorry, can u please type yes or no")
    else: 
        if midi_output in matches:
            retrieve_midi = False
        else: 
         print("\nSorry, can u please type yes or no")

matches_true = ['yes', 'Yes', 'y', 'Y', 'YES']

if midi_output in matches_true:
    # set the necessary values for MIDI util
    velocity=80
    track = 0
    channel = 9 # corresponds to channel 10 drums
    bpm = default_bpm

    #make midiFile
    mf = MIDIFile(1)

    #ask the user the name of the midiFile 
    retrieve_midiname = True
    while retrieve_midiname:
        try:
            midi_name = input("\nHow do you want to name your midi file? Please give a name between 1 and 15 characters.\n")
        except:
            print("\nSorry can u pls give a name between 1 and 15 characters")
        else:
            if len(midi_name) >= 1 and len(midi_name) <= 15:
                print("\nOkay, the name of your midiFile will be:", midi_name)
                retrieve_midiname = False
            else:
                print("\nSorry can u pls give a name between 1 and 15 characters")

    #set name and tempo
    time_beginning = 0
    mf.addTrackName(track, time_beginning, midi_name)
    mf.addTempo(track, time_beginning, bpm)
    midi_time = 0
    e_note = 30000/default_bpm

    #for loop for adding all the events to a midi file
    for event in all_events_buffer:
        mf.addNote(track, channel, event['midinote'], midi_time, 1.5, velocity)
        midi_time = midi_time + (event['duration']/e_note)
    
    with open(midi_name+".midi",'wb') as outf:
        mf.writeFile(outf)
