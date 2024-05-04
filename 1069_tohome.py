import math

x, y, d, t = map(int, input().split())

distance = math.sqrt(x**2 + y**2)

if distance >= d:
    ans = min(t * (distance // d) + distance % d, t * (distance // d + 1), distance)
else :
    ans = min(t + (d - distance), 2 * t, distance)

print(ans)