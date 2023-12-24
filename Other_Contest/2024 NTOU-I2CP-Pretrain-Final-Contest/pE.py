from math import gcd

def main():
    n = int(input())
    a = list(map(int, input().split()))

    if n == 1:
        print(2)
        return

    b = [1] * n
    for i in range(100000):
        for j in range(n):
            b[j] *= a[j]

        g = abs(b[1] - b[0])
        for j in range(2, n):
            g = gcd(abs(b[j] - b[j-1]), g)

        if g > 1:
            print(g)
            return

main()