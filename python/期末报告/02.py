import random

luckynum = random.sample(range(1,31),6)
user = []
for i in range(6):
    num = int(input(f"输入第{i+1}个1~30数字："))
    user.append(num)
count = 0
for n in user:
    if n in luckynum:
        count +=1
print(f"开奖数字：{luckynum}")
print(f"中奖个数：{count}")