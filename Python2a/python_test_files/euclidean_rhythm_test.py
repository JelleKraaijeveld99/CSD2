#function for generating euclidean rhythms 
def euclidean_gen(num_pulses, num_notes):
    # calculate duration of a note, expressed in 16th
    note_dur = int(num_pulses / num_notes)
    # fill list num_notes times with the duration value
    sequence = [note_dur] * num_notes
    
    rest_value = num_pulses - (num_notes * note_dur)
    for i in range(rest_value):
        sequence[i] += 1
    print(sequence)    

    #summing up all the notes and converting them to timestamps
    timestamp_sequence = []
    sum = 0
    timestamp_sequence.append(0)
    for x in range(len(sequence)-1):
        sum = int(sum) + int(sequence[x])
        timestamp_sequence.append(sum)
    return timestamp_sequence
    
kick_pattern = euclidean_gen(11,4)
clap_pattern = euclidean_gen(11,3)
tambourine_pattern = euclidean_gen(11,6)

print("this is the kick pattern:",kick_pattern)
print("this is the clap pattern:",clap_pattern)
print("this is the tambourine pattern:",tambourine_pattern)



