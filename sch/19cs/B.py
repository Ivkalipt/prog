def conv(x, b):
    res = ""
    while (x > 0):
        if (x % b < 10):
            res += str(x % b)
        else:
            res += chr(ord('A') + x % b - 10)
        x //= b
    return res;

def main():
    n = int(input())
    for i in range(2, 37):
        a = conv(n, i)
        if (len(set(a)) == len(a)):
            print(i, end = ' ')

if __name__ == "__main__":
    main()
