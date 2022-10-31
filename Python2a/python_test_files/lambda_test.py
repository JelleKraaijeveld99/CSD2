l = [{'Name': 'Alice', 'Age': 40, 'Point': 80},
     {'Name': 'Bob', 'Age': 20},
     {'Name': 'Charlie', 'Age': 30, 'Point': 70}]

print("before the sort:", l)

l = sorted(l, key=lambda x: x['Age'])

print ("after the sort:", l)
