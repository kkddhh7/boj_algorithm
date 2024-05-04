import math

n = int(input())

ans = []

for _ in range(n) :
    x1, y1, r1, x2, y2, r2 = map(int, input().split())
    distance = math.sqrt((x1 - x2)**2 + (y1 - y2)**2)
    
    if distance == 0 and r1 == r2:
        ans.append(-1)
    elif abs(r1 - r2) == distance or r1 + r2 == distance:
        ans.append(1)
    elif abs(r1 - r2) < distance < (r1 + r2):
        ans.append(2)
    else:
        ans.append(0)

for a in ans :
    print(a)