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
        if time_signature is 1 or time_signature is 2:
            retrieve_time_signature = False
        else: 
         print("\nSorry, can u please give the number 1 or 2")



########## section for generating rhythms   

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
def euclidean_gen(num_pulses, num_notes):
    # calculate duration of a note, expressed in 16th
    note_dur = int(num_pulses / num_notes)
    # fill list num_notes times with the duration value
    sequence = [note_dur] * num_notes
    
    rest_value = num_pulses - (num_notes * note_dur)
    for i in range(rest_value):
        sequence[i] += 1    

    #summing up all the notes and converting them to timestamps
    timestamp_sequence = []
    sum = 0
    timestamp_sequence.append(0)
    for x in range(len(sequence)-1):
        sum = int(sum) + int(sequence[x])
        timestamp_sequence.append(sum)
    return timestamp_sequence

kick_pattern = euclidean_gen(amount_of_notes,random.randint(1,4))
clap_pattern = euclidean_gen(amount_of_notes,random.randint(1,4))
tambourine_pattern = euclidean_gen(amount_of_notes,random.randint(1,amount_of_notes - 3))

print("this is the kick pattern:",kick_pattern)
print("this is the clap pattern:",clap_pattern)
print("this is the tambourine pattern:",tambourine_pattern)








