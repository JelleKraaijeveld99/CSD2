import input_and_text_rp as iandt
import convertion_rp as crp
import audio_rp as arp

#open input and text script 
iandt

#converting durations from the input
crp.duration(iandt.input_durations_list,iandt.input_bpm,iandt.how_many_times)

#play the sample in a rhythm 
arp.rhytmicplayback(crp.converted_durations_list)









