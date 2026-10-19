studentid = int(input("输入学生学号："))
if studentid % 2 == 1:
    group = "A组"
else:
    group = "B组"
print(f"分到{group}")