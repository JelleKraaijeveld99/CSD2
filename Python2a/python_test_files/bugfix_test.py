#a while loop, loops a set of statements as long as the condition is true 

for x in range(3):
    while True:
        try:
            getal = int(input("voer een getal in "))
        except ValueError:
            print("Sorry, can u please give a number")
        
        else: 
            #break stops the loop   
            break 

print(getal)


#try a while loop in a for loop the next time i code
