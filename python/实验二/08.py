import random

seed_val = int(input())
random.seed(seed_val)

s = "ABCDEFGHIJ0123456789"
code = ""

for i in range(6):
    code = code + random.choice(s)

print(code)