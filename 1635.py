import sys

for line in sys.stdin:
	n,m = map(int, line.split())
	comb = [1];
	ans = [];
	if m == 1:
		ans.append(m)
	print(n)
	print(m)
	for x in range(1,n):
		tmp = comb[x-1]*(n-x)/x
		comb.append(tmp)
		if tmp%m == 0:
			ans.append(x+1)
	print(comb[n-1])
	print(len(ans))
	l = len(ans)
	for x in range(0, l):
		print(ans[x], end = ' ')
	print()
		
	
	
