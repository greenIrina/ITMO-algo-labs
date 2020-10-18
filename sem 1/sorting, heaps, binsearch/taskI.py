n = float(input())
eps = 1e-7
right = 1e5
left = 0
for i in range(201):
    mid = float(right + left) / 2
    val = mid ** 2 + mid ** 0.5
    if abs(val - n) <= eps:
        print(round(mid, 7))
        break
    if val < n:
        left = mid
    else:
        right = mid
