import math

def sqrt_binary(n):
    low = 0.0
    high = float(n)
    mid = (low + high) / 2.0

    while abs(mid * mid - n) > 1e-6:
        if mid * mid > n:
            high = mid
        else:
            low = mid
        mid = (low + high) / 2.0
    return mid

n = float(input())
print(sqrt_binary(n))
print(math.sqrt(n))