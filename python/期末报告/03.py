student = {}

n = int(input("输入学生人数："))
for i in range(n):
    name = input("姓名：")
    score = float(input("成绩："))
    student[name] = score

scores = list(student.values())
maxscore = max(scores)
minscore = min(scores)
ascore = sum(scores)/len(scores)
print(f"最高分：{maxscore}")
print(f"最低分：{minscore}")
print(f"平均分：{ascore:.2f}")