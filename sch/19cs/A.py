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
    for i in range(2, 37):
        for sym in range(i):
            l_num_i = 1, num_10 = 

if __name__ == "__main__":
    main()
