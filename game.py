m = [['L']*11 for i in range(11)]
for i in range(5):
    m[2*i+1][0] = 'W'
    m[0][2*i+1]='W'
for x in range(1,11):
    for y in range(1,11):
        if m[x][y-1] is 'L' or m[x-1][y] is 'L' or m[x-1][y-1] is 'L':
            m[x][y] = 'W'

for a in m:
    print a;


