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
    a, b = input().split()
    res = int(a, 16) + int(b, 16)
    neo = conv(res, 16);
    if (len(neo) == 0): print(0)
    else: print(neo)


if __name__ == "__main__":
    main()
