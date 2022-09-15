import simpleaudio as sa

# little interaction
username = input("Enter your username: ")
print("Hello " + username + "!")

# variable for how many times the sample will be played
how_many_times = input("How many times do you want to play this sound? ")
print("Okay, I'll play the sound " + how_many_times + " times!")

# where is the sample?
wave_obj = sa.WaveObject.from_wave_file("/Users/jellekraaijeveld/Documents/Samples/Grain.wav")

# safe the sample, ready to be played 
play_obj = wave_obj.play()


# play the sample 
function_play_sample_x_times(how_many_times)

# function for amount of times the sample has to be played
def function_play_sample_x_times(x):
    for x in range(x):
      print(x)
   



    








