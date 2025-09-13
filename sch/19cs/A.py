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
    x = int(input())
    while (True):
        for i in range(2, 37):
            a = conv(x, i)
            # print(a, i)
            if len(set(a)) == 1:
                print(i, a)
                exit()
        x += 1
    # print(conv(x, ))

if __name__ == "__main__":
    main()
