# O(|S|)

t = int(input())
for _ in range(t):
	s = input()
	freq = [0 for i in range(26)]
	for x in s:
		freq[ord(x)-ord('a')] += 1
	ans = 0
	for i in range(26):
		ans = ans or (freq[i] > 1)
	if (ans):
		print("yes")
	else:
		print("no")
