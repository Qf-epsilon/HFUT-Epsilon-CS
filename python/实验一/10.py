'''编写一个 Python 程序，接收用户输入的多个整数（以逗号分隔），将这些
整数存入列表后，对列表进行排序并输出。同时，计算并输出排序后列表中所有
偶数的平均值（如果没有偶数则输出提示信息）'''
input_num=input("请输入多个整数（用逗号分隔）：")
num_strings=input_num.split(",")
numbers=[]
for s in num_strings:
    numbers.append(int(s.strip()))
numbers.sort()
print("排序后的列表：",numbers)
even_num=[]
for num in numbers:
    if num%2==0:
        even_num.append(num)
if len(even_num) > 0:
    avg=sum(even_num)/len(even_num)
    print("所有偶数的平均值为：",avg)
else:
    print("列表中没有偶数")