t = int(input())
for i in range(t):
    n = int(input())
    s = input()
    l = s.find("B")
    r = s.rfind("B")
    print(r-l+1)