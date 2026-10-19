#输入正整数 N，计算各位数字的平方和，直接输出结果。
num=input()
sum=0
for char in num:#原理就是把这个数字转化为字符，然后依次遍历
    sum += int(char) ** 2
print(sum)