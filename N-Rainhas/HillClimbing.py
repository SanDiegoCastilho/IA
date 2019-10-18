def HillClimbing():
    sampleSpace = [12,52,546,567,9,64,56,678,67,45,6567,6789,78,346,345,45,7679,70,345,234,346,568,7807,32,342,3,467,678,79,345,2342,34,546,5678,789]
    kick = 19 
    current = sampleSpace[kick]

    while(True):
    	neighbor = getsBigger(kick-1, kick+1, sampleSpace)

    	if (sampleSpace[neighbor] <= current):
    	    return current

    	current = sampleSpace[neighbor]
    	kick = neighbor
   	    
        

def getsBigger(N1, N2, sampleSpace):
	if (N1 >= 0 and N2 <= len(sampleSpace)-1):
		if (sampleSpace[N1] > sampleSpace[N2]):
		    return N1

		else:
		  	return N2


print(HillClimbing())