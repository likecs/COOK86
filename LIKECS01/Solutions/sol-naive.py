# O(|S| ^ 2)

t = int(input())
for _ in range(t):
	s = input()
	ans = 0
	for i in range(len(s)):
		for j in range(i+1, len(s)):
			if (s[i] == s[j]):
				ans = 1
	if (ans):
		print("yes")
	else:
		print("no")
