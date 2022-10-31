#bpm 
bpm = 90 

#quarter note
q_note = 60/bpm
#eigtht note
e_note = 30/bpm

#how many eighth notes per bar with a certain time signature 
time_signature54 = 10
time_signature78 = 7

#duration of an eighth note
eighth_note_dur = 30/bpm 

#how many bars do you want to generate?
how_many_bars = 4 

#function for making timestamps for the kick in 5/4 
def ts_maker_kick54(time_sign, bars):
    #a list for timestamps inside the function 
    tskick54_func_list = []
    counter = 0
    #a for loop for making timestamps yes or no 
    for x in range(time_sign*bars):
        #if statement for placing kick on the start of each bar 
        if x%10 == 0:
          counter = x
          tskick54_func_list.append(counter)
        if x%2 == 0:
           counter = x 
           tskick54_func_list.append(counter) 
        
    return tskick54_func_list    

kicks54 = ts_maker_kick54(time_signature54,how_many_bars)
print(kicks54)