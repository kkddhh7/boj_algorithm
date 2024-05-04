import sys
input = sys.stdin.readline

n = int(input())
cranes = list(map(int, input().split()))
cranes.sort(reverse=True)

m = int(input())
boxes = list(map(int, input().split()))
boxes.sort(reverse=True)

cnt = 0

if boxes[0] > cranes[0] :
    cnt = -1
else:
    while boxes:
        for i in cranes:
            if boxes and i < boxes[-1]:
                continue
            for j in boxes:
                if i >= j:
                    boxes.remove(j)
                    break
        cnt += 1

print(cnt)