timestamps = [1,4,7,9,11,15]
durations = []

def ts_to_dur(ts_list):
    #empty list for durations
    dur_list = []
    #reverse the ts list to avoid index error in the for loop
    ts_list.reverse()

    # subtract 2 consecutive values in the ts_list to calculate the difference in value between them. This must be the duration
    for i in range(len(ts_list)-1):
        dur_list.append(ts_list[i] - ts_list[i+1])
    
    #add the last timestamp value (which is the first because i reversed the list) to the duration list. 
    dur_list.append(ts_list.pop())
    
    #now reverse the duration list so all the durations are in the right order again. 
    dur_list.reverse()
    return dur_list
    
durations = ts_to_dur(timestamps)

print(durations)