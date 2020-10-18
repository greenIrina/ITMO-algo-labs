a = [int(x) for x in input().split()]


def remove_equals(arr):
    while arr:
        equals = [0]
        last = arr[0]
        for i in range(1, len(arr)):
            if last != arr[i]:
                if len(equals) < 3:
                    equals.clear()
                else:
                    break
            equals.append(i)
            last = arr[i]
        if len(equals) < 3:
            break
        for i in reversed(equals):
            arr.pop(i)
        equals.clear()
    return arr


print(len(a) - len(remove_equals(a)))
