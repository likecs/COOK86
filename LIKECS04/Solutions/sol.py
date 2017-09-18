# O(n * bmax^2 * sumb)

MAX = 51
MAX2 = 2501
MOD = 1000000007

def gcd(a, b):
	while(b > 0):
		a, b = b, a % b
	return a

n = int(input())
b = list(map(int, raw_input().split()))
pre = [[gcd(x, y) for x in xrange(MAX)] for y in xrange(MAX)]

dp = [[[0 for i in xrange(MAX2)] for j in xrange(MAX)] for k in xrange(n+1)]
for i in xrange(b[0]+1):
	dp[1][i][i] = 1
sum = b[0]+1
for pos in xrange(1, n):
	sum += b[pos]
	for x in xrange(MAX):
		for y in xrange(b[pos]+1):
			for s in xrange(sum):
				if (s+y >= MAX2):
					break
				z = pre[x][y]
				dp[pos+1][z][s+y] += dp[pos][x][s];
				if (dp[pos+1][z][s+y] >= MOD):
					dp[pos+1][z][s+y] -= MOD

ans = 0
for g in xrange(1, MAX):
	s = 1
	while(s*g < MAX2):
		ans += dp[n][g][s*g]
		s *= 2
ans %= MOD
print ans