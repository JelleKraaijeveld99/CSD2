from hashlib import new

bars_real = 8
list = [0,4]
notes = 8

#function for making variations (after a customizable amount of bars) for the original generated rhythm
def rhythm_bars(eucl_list, bars, note_amount):
    buffer_list = eucl_list # a list i use to store a rhythm + the amount of bars we are in right now
    refrence_list = eucl_list # a list i use to store the imput rhythm, after 4 bars i change this to the imput rhythm + offset
    complete_eucl = [] # a list for returning a list with the complete rhythm
    offset = 3
    for i in range(bars):
        if (i % 4 == 0) and (i != 0): #after every 4 bars make a variation
            buffer_list = [x + offset for x in eucl_list] #the original values of eucl_list with an offset
            print("this is the bufferlist with offset:", buffer_list)
            for x in range(len(buffer_list)): #for loop with modulo for making offset
                buffer_list[x] = buffer_list[x] % note_amount 
            buffer_list.sort() #
            refrence_list = buffer_list #store the rhythm + offset (new rhythm) in a variable
            print("this is the bufferlist with offset + modulo:", buffer_list)
            #add the rhythm + the bar we in to the complete_eucl list
            buffer_list = [x + i*note_amount for x in buffer_list]
            print("this is the bufferlist + the bar we are in:", buffer_list)
            complete_eucl.extend(buffer_list)
    
        else:
            buffer_list = [x + i*note_amount for x in refrence_list]
            complete_eucl.extend(buffer_list)

    return complete_eucl

print("this is the original list:", list)

total_list = rhythm_bars(list, bars_real, notes)

print("this is the total list:", total_list)

        