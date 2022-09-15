# list for input durations 
input_durations_list = []

# little interaction
username = input("Enter your username: ")
print("Hello " + username + "!")

# variable for how many times the sample will be played. Also some explaination about the note values
how_many_times = int(input("\nHow many times do you want to play the sample?\n"))
print("\nOkay, I'll play the sample ", how_many_times, " times! But how long do you want each sample to be played? Let me explain the note durations; \n \nEigth note = 0.5 \nQuarter note = 1 \nHalf note = 1.5 \nEtc. \n " )

# loop to ask the duration of the notes
for indx in range(how_many_times):
    value = float(input("Add note value: "))
    input_durations_list.append(value)

# input the bpm 
input_bpm = int(input("\nAt what BPM do you want the samples to be played?\n"))

# feedback to the user
print("\nOkay i'll play the sample", how_many_times, "times with your specified rythm. The bpm will be", input_bpm,"!")



