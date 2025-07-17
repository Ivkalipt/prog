import math

def finder(n, m, k):
    if k == 1:
        return "D" * n + "R" * m

    tpd = 1

    if n > 0:
        tpd = math.comb(n + m - 1, m)  

    if k <= tpd:
        return ("D" + str(finder(n - 1, m, k)))
    else:
        return ("R" + str(finder(n, m - 1, k - tpd)))

n, m, k = map(int, input().split())
path = finder(n, m, k)
print(path) 

