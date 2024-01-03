n = int(input())

num = 1
for i in range(n):
    u = int(input())
    num *= u

ans = 0
while( num != 0 ):
    if( num % 10 == 0 and num >= 10 ):
        ans += 1
    num //= 10

print(ans)