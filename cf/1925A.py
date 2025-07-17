t = int(input())
for i in range(t):
    n, k = map(int, input().split())
    s = ""
    for j in range(k):
        s += chr(j+97)
    s*=n
    print(s)