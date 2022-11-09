timestamps = [1,4,7,9,11,15]
durations = []

def ts_to_dur_events(ts_list,x_bpm, instr_name):
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
    dur_list.append(ts_list.pop()*e_note)
    
    #now reverse the duration list so all the durations are in the right order again. 
    dur_list.reverse()

    #section for making the events
    event_list = []
    for x in range(len(dur_list)):
           event_list.append({'duration': dur_list[x], 'instrument': instr_name})
    
    return event_list
   

durations = ts_to_dur_events(timestamps,120, "kick")

print(durations)