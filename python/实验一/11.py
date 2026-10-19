#输入整数 n，计算 n 的阶乘。
n=int(input("输入一个非负整数 n："))
result=1
for i in range(1,n+1):
    result*=i
print(f"{n} 的阶乘是：",result)