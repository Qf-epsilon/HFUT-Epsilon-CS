def is_monotonic(lst):
    inc = True
    dec = True

    for i in range(len(lst) - 1):
        if lst[i] >= lst[i + 1]:
            inc = False
        if lst[i] <= lst[i + 1]:
            dec = False

    return inc or dec

print(is_monotonic([1, 2, 3, 5, 8]))