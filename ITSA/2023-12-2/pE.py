n = int(input())
v = []
a = {}
b = {}
c = {}
mp = {}
for i in range(n):
    w,x,y,z = input().split(" ")
    a[w] = b[w] = c[w] = 0
    a[w] = int(x)
    b[w] = int(y)
    c[w] = int(z)
q = int(input())
for i in range(q):
    s, h = input().split(" ")
    h = int(h)
    if s not in mp:
        mp[s] = 0
    mp[s] += h
ans = []
for s in a:
    total = a[s] * 0.3 + b[s] * 0.3 + c[s] * 0.4
    if s in mp and mp[s] > 6:
        total -= (mp[s] - 6)
    ans.append((s, total))
ans.sort(key=lambda x: int(x[0]))
for i in ans:
    print(i[0], end=" ")
    g = int(i[1])
    t = int(i[1] * 10)
    if round(i[1]) < 0:
        print(0)
        continue
    print(round(i[1]))

