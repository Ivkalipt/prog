def conv(x, b):
    res = ""
    while (x > 0):
        if (x % b < 10):
            res += str(x % b)
        else:
            res += chr(ord('A') + x % b - 10)
        x //= b
    
    return res[::-1];

def main():
    I, J = map(int, input().split())
    N = input()
    neo = conv(int(N, base = I), J);
    if (len(neo) == 0): print(0)
    else: print(conv(int(N, base = I), J))

if __name__ == "__main__":
    main()
