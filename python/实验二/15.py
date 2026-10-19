n = int(input())

total_sum = 0
current = 0

for i in range(1, n + 1):
    current = current * 10 + i
    total_sum = total_sum + current

print(total_sum)