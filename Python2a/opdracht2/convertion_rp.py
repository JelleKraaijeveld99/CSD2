#list for converted durations: input to ms
converted_durations_list = []

#function for converting durations: imput to ms to seconds
def duration(dur_input, bpm_input, amount_input):
    for x in range(amount_input):
        value = 60000 * (float(dur_input[x])/int(bpm_input))
        value = value / 1000
        converted_durations_list.append(value)

    print(converted_durations_list)