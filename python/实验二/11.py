s = input()

try:
    num = float(s)
    print(num ** 3)
except:
    print("输入错误，请输入数字")