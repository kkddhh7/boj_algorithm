import queue
import copy

n, m = map(int, input().split())
Map = list(list(map(int, input().split())) for _ in range(n))

safe = 0
virus_row = []
virus_col = []
for i in range(n) :
    for j in range(m) :
        if Map[i][j] == 0 :
            safe += 1
        elif Map[i][j] == 2 :
            virus_row.append(i)
            virus_col.append(j)
            
dr = [1, -1, 0, 0]
dc = [0, 0, -1, 1]         
def spread(tmap, tsafe) :
    q = queue.Queue()
    for i in range(len(virus_col)) :
        q.put((virus_row[i], virus_col[i]))
        while not q.empty() :
            r, c = q.get()
            for j in range(4) :
                nr = r + dr[j]
                nc = c + dc[j] 
                if 0 <= nr < n and 0 <= nc < m and tmap[nr][nc] == 0 :
                    tsafe -= 1
                    tmap[nr][nc] = 2
                    q.put((nr, nc))
    return tsafe

wall_row = [0] * 3
wall_col = [0] * 3
ans = 0
def wall(count, num):
    if count == 3:
        tmap = copy.deepcopy(Map)
        for i in range(3):
            tmap[wall_row[i]][wall_col[i]] = 1
        tsafe = safe - 3
        tsafe = spread(tmap, tsafe)
        global ans
        if ans < tsafe:
            ans = tsafe
        return
    
    for i in range(num, n*m):
        r = i // m
        c = i % m
        if Map[r][c] == 0:
            wall_row[count] = r
            wall_col[count] = c
            wall(count + 1, i + 1)


wall(0, 0)
print(ans)