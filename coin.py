M = 11
c = [5, 3, 1]
ar = [1,2,1,2,1, 0,0,0,0,0, 0]


def fill_table(idx) :
    m = min(ar[idx-1], ar[idx-3])
    n = min(m, ar[idx-5])
    return n+1

for i in range(5, 11):
    ar[i] = fill_table(i)

print ar
