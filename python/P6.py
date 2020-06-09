def solve(N):
	elements = [x for x in range(1,N+1)]
	num = len(elements)
	i = 0
	SUM = 0
	while i < num - 1:
		j = i + 1
		while j < num:
			SUM += 2 * elements[i] * elements[j]
			j += 1
		i += 1
	return SUM

if __name__ == "__main__":
    print(solve(100))
