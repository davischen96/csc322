# find the skipped numbers in a list sorted in ascending order

def getSkippedNumbers (arr):
	complement = []
	for i in xrange(0, len(l) - 1):
		j = l[i] + 1
		while j < l[i + 1]:
			complement.append(j)
			j += 1
	return complement

l = [1, 3, 5, 7, 10]       # should return [2, 4, 6, 8, 9]
print getSkippedNumbers(l)