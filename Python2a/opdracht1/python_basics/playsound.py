import simpleaudio as sa

#function for playing sample y amount of times
def function_play(y):
    for x in range(y):
      play_obj = wave_obj.play()    
      play_obj.wait_done()

# little interaction
username = input("Enter your username: ")
print("Hello " + username + "!")

# variable for how many times the sample will be played
how_many_times = int(input("How many times do you want to play this sound? "))
print("Okay, I'll play the sound ", how_many_times," times!")

# where is the sample?
wave_obj = sa.WaveObject.from_wave_file("/Users/jellekraaijeveld/Documents/Samples/Grain.wav")

# play the sample 
function_play(how_many_times)





    








