n = int(input())
a = [int(x) for x in input().split()]


def merge(left, right):
    arr = []
    while len(left) != 0 and len(right) != 0:
        if left[0] < right[0]:
            arr.append(left[0])
            left.remove(left[0])
        else:
            arr.append(right[0])
            right.remove(right[0])
    if len(left) == 0:
        arr += right
    else:
        arr += left
    return arr


def mergesort(lst):
    if len(lst) == 0 or len(lst) == 1:
        return lst
    else:
        middle = len(lst) // 2
        left = mergesort(lst[:middle])
        right = mergesort(lst[middle:])
        return merge(left, right)


array = mergesort(a)
for i in range(n):
    print(array[i], end=' ')
