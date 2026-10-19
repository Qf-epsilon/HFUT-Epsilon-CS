#输入成绩，判断等级：90-100 A，80-89 B，70-79 C，60-69 D，<60 不及格。
score=float(input("请输入你的成绩："))
if score<60:
    print("不合格")
elif score>=60 and score<70:
    print("你的等级为：D")
elif score>=70 and score<80:
    print("你的等级为：C")
elif score>=80 and score<90:
    print("你的等级为：B")
elif score>=90 and score<100:
    print("你的等级为：A")
else:
    print("输入无效")