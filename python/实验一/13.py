num=int(input("输入一个非负整数："))
if num==0:
    print(0)
else:
    count=[]
    while num>0:
        rem=num%2
        count.append(str(rem))
        num=num//2
    count.reverse()
    num_two="".join(count)
    print("对应的二进制数：",num_two)