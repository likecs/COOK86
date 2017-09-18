# O(n logn)

t = int(input())
for _ in range(t):
	[n, k] = list(map(int, input().split()))
	arr = list(map(int, input().split()))
	mark = dict()
	for x in arr:
		if (x > 0 and (x & (x-1)) == 0):
			mark[x] = 1
	ans = k - len(mark)
	print(ans)