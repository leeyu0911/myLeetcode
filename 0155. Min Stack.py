s1 = ["MinStack","push","push","getMin","getMin","push","getMin","getMin","top","getMin","pop","push","push","getMin","push","pop","top","getMin","pop"]
s2 = [[],[-10],[14],[],[],[-20],[],[],[],[],[],[10],[-7],[],[-7],[],[],[],[]]

d = {
	'MinStack': 'MinStack* obj = minStackCreate();',
	'push': 'minStackPush(obj, %);',
	'getMin': 'int p$ = minStackGetMin(obj);',
	'top': 'int p$ = minStackTop(obj);',
	'pop': 'minStackPop(obj);'
}

for i in range(len(s1)):
	s = d[s1[i]].replace('%', str(s2[i])[1:-1]).replace('$', str(i))
	print(s)
