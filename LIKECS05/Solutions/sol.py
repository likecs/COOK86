# O(n + m + n logn)

from random import *
import sys
import time

def ilog2(n):
	return 0 if n <= 0 else n.bit_length() - 1

def pack(pack, shamt):
	size = len(pack)
	while size > 1:
		npack = []
		for i in range(0, size - 1, 2):
			npack += [pack[i] | (pack[i+1] << shamt)]
		if size & 1:
			npack += [pack[-1]]
		pack, size, shamt = npack, (size + 1) >> 1, shamt << 1
	return pack[0]

def unpack(M, size, shamt):
	s, sizes = size, []
	while s > 1:
		sizes += [s]
		s = (s + 1) >> 1
	ret = [M]
	for size in sizes[::-1]:
		mask, nret = (1 << shamt) - 1, []
		for c in ret:
			nret += [c & mask, c >> shamt]
		ret, shamt = nret[:size], shamt >> 1
	return ret

def poly_mul(f, g, mod = 1000000007):
	size = min(len(f), len(g))
	shift = ((mod - 1) ** 2 * size).bit_length()
	rsize = len(f) + len(g) - 1
	h = unpack(pack(f, shift) * pack(g, shift), rsize, shift * (1 << ilog2(rsize - 1)))
	return [int(x % mod) for x in h]

inpos = sys.stdin
[N, M] = list(map(int, inpos.readline().split()))
row_mask = [0 for i in range(N)]
col_mask = [0 for i in range(N)]
diag_mask = [0 for i in range(2*N)]
for i in range(M):
	[t, idx, color] = list(map(int, inpos.readline().split()))
	idx -= 1
	if (t == 1):
		row_mask[idx] |= 1 << color
	elif (t == 2):
		col_mask[idx] |= 1 << color
	else:
		idx -= 1
		diag_mask[idx] |= 1 << color

def solve(row, col, diag):
	R = len(row)
	C = len(col)
	ans = (R + C) * N - R * C
	markr = [0 for i in range(N)]
	markc = [0 for i in range(N)]
	for x in row:
		markr[x] = 1
	for x in col:
		markc[x] = 1
	unmark_row = []
	unmark_col = []
	for i in range(N):
		unmark_row.append(1 ^ markr[i])
		unmark_col.append(1 ^ markc[i])
	get = poly_mul(unmark_row, unmark_col)
	for x in diag:
		ans += get[x]
	return ans

def solve_color(c1, c2 = 0):
	row = []
	col = []
	diag = []
	for i in range(N):
		if ((row_mask[i] & c1) > 0):
			row.append(i)
		elif ((row_mask[i] & c2) > 0):
			row.append(i)
		if ((col_mask[i] & c1) > 0):
			col.append(i)
		elif ((col_mask[i] & c2) > 0):
			col.append(i)
	for i in range(2*N):
		if ((diag_mask[i] & c1) > 0):
			diag.append(i)
		elif ((diag_mask[i] & c2) > 0):
			diag.append(i)
	return solve(row, col, diag)

green = solve_color(1)
red = solve_color(2)
any_color = solve_color(1, 2)
yellow = red + green - any_color
red -= yellow
green -= yellow
no_color = N * N - red - green - yellow
print(no_color, red, green, yellow)