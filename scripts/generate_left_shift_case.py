n = int(input("input bit size: ")) 
count = 0 

for i in range (0, n): 
    print("23'b", end="") 
    while(count <= i): 
        print("0", end="")
        count += 1
    count = n + 2 - i
    print("1", end="")
    while((count - 3) > 0): 
        print("?", end="")
        count -= 1
    
    print(": begin")
    print("    result = {fraction[MANT_B-%0d:0], %0d'd0};" % (i, i+1))
    print("    shifted_amount = 'd%0d;" %(i+1))
    print("end")
    