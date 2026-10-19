a=int(input("请输入第一个整数："))
b=int(input("请输入第二个整数："))
print("和：",a+b)
print("差：",a-b)
print("积：",a*b)
if b != 0:
    print("商：",a/b)
    print("余数：",a%b)
else:
    print("除数不能为0")
