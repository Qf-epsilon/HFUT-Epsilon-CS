#统计字符串中字母 a 出现的次数。
chars=input("请输入一个字符串：")
num=0
for char in chars:
    if char=='a':
        num+=1
print("字母 a 出现的次数为：",num)