from os import times
import simpleaudio as sa 
import time as time 
import random 

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
while True:
    try:
        default_bpm = int(input("\nAt what BPM do you want the sequence to be played?\n"))
    except ValueError:
        print("\nSorry, can u please give a number")
    else: 
    #break stops the loop   
        break

#input the amount of bars
while True:
    try:
        bars_amount = int(input("\nHow many bars do you want to be generated?\n"))
    except ValueError:
        print("\nSorry, can u please give a number")
    else: 
    #break stops the loop   
        break

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
    # calculate duration of a note, expressed in 16th
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
    print("hoi dit is de sequence voor de offset:", timestamp_sequence)
    
    #section for offset 
    timestamp_sequence = [x+offset for x in timestamp_sequence] #add the offset value to every dur in the list   
    
    #modulo all the new values in the list based on the maximum amount of possible notes
    for i in range(len(timestamp_sequence)):
        timestamp_sequence[i] = timestamp_sequence[i] % num_pulses
    
    #sort all the values in the right order from low to high
    timestamp_sequence.sort()
    return timestamp_sequence

kick_pattern = euclidean_gen(amount_of_notes,random.randint(1,4), 0)
clap_pattern = euclidean_gen(amount_of_notes,random.randint(1,4), 0)
tambourine_pattern = euclidean_gen(amount_of_notes,random.randint(3,amount_of_notes - 3), 0)

#function for making variations in the existing eucl rhythm
def rhythm_bars(eucl_list, bars, note_amount):
    buffer_list = eucl_list # changing this list every step in the for loop, adding the amount of notes * the amount of bars to every item in the list
    complete_eucl = []
    for i in range(bars):
        buffer_list = [x + i*note_amount for x in eucl_list]
        print(i, "=", buffer_list)
        complete_eucl.extend(buffer_list)
    return complete_eucl
  
print("this is the kick pattern:",kick_pattern)
print("this is the clap pattern:",clap_pattern)
print("this is the tambourine pattern:",tambourine_pattern)

total_rhythm = rhythm_bars(tambourine_pattern, bars_amount, amount_of_notes)
print("this is the total rhythm:",total_rhythm) 








