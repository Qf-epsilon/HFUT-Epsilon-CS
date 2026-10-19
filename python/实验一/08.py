#统计 1~10000 中各位数字之和为 13 的数
num=0
for i in range(1,10001):
    q=str(i)
    total=0
    for char in q:
        total+=int(char)
    if total==13:
        num+=1
print("1~10000 中各位数字之和为 13 的数的个数为：", num)