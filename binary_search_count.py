def check(arr, X):
    n = len(arr)
    l1 = 0
    l2 = 0
    h1 = n - 1
    h2 = n - 1
    while (l1 < h1) or (l2 < h2):
        if l1 != h1:
            m1 = (l1 + h1) // 2
            if arr[m1] >= X:
                h1 = m1 - 1
            else:
                l1 = m1 + 1
        if l2 != h2:
            m2 = (l2 + h2) // 2
            if arr[m2] > X:
                h2 = m2 - 1
            else:
                l2 = m2 + 1
    if m1 == m2:
        if arr[m1] == X:
            k = 1
        else:
            k = 0
    else:
        k = m2 - m1 + 1
        if arr[m2] != X:
            k -= 1
    return k


if __name__ == "__main__":
    arr = [3, 5, 7, 8, 8, 8, 8, 9, 11, 13, 15]
    print(check(arr, 8))
