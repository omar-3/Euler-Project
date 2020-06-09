def solve(N):
	elements = [x for x in range(1,N+1)]
	i = 0
	SUM = 0
	while i < len(elements) - 1:
		j = i + 1
		while j < len(elements):
			SUM += 2 * elements[i] * elements[j]
			j += 1
		i += 1
	return SUM

if __name__ == "__main__":
    print(solve(100))
