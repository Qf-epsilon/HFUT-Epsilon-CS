import pandas as pd

stu_dict = {
    "姓名":["学生A","学生B","学生C","学生D","学生E","学生F","学生G","学生H","学生I","学生J"],
    "年龄":[19,18,20,19,18,21,19,20,18,19],
    "性别":["男","女","男","女","男","女","男","男","女","女"],
    "专业":["计科","软工","计科","大数据","软工","计科","大数据","软工","计科","大数据"],
    "Python成绩":[88,76,92,66,85,95,72,83,59,81],
    "数学成绩":[77,82,89,91,68,79,84,73,86,90]
}

df = pd.DataFrame(stu_dict)

print("====(1)前5行====")
print(df.head(5))
print("\n====(1)后3行====")
print(df.tail(3))

print("\n====(2)行列shape(行,列):", df.shape)
print("\n====每列数据类型dtypes====")
print(df.dtypes)
print("\n====每列缺失值数量isnull.sum()====")
print(df.isnull().sum())

df_py80 = df[df["Python成绩"]>80]
print("\n====(3)Python>80学生====")
print(df_py80)

df_py_sort = df.sort_values("Python成绩", ascending=False).head(3)
print("\n====(4)Python成绩前3名====")
print(df_py_sort)

df.to_csv("students.csv", encoding="utf‑8‑sig", index=False)
print("\n已保存 students.csv")
