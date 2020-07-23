to_check = [(2018, 0), (1118, 1680), (0, 2018), (1680, 1118), (-2018, 0), (-1118, -1680), (0, -2018), (-1680, -1118), (-1118, 1680), (1680, -1118), (-1680, 1118), (1118, -1680)]

N = int(input())
d = {}
for i in range(N):
    point = tuple(map(int, input().split()))
    d[point] = 1

sol = 0
for point in list(d.keys()):
    for delta in to_check:
        if (point[0] + delta[0], point[1] + delta[1]) in d:
            sol += 1
            
print(int(sol / 2))