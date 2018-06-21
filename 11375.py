number = [2,5,5,4,5,6,3,7,6];
ans = [0]*2005
for i in range(2,2001):
	for a in number:
		if(a>i):
			continue;
		else:
			ans[i] += ans[i-a] + 1;
	if(i>=6): ans[i] += ans[i-6];
while True:
		n = int(input());
		if(n>=6): print(ans[n]+1);
		else: print(ans[n])
