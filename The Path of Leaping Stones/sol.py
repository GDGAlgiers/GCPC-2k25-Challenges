def ThePathofLeapingStones(stones: List[int]) -> bool:
	goal = len(stones)-1
	for i in reversed(range(len(stones)-1)):
	    if stones[i]+i>=goal:
		goal=i 
	if goal==0:
	    return True 
	return False
