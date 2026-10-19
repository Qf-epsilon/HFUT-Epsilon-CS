import pandas as pd

df = pd.DataFrame({
    "姓名":["张三","李四","王五","赵六"],
    "语文":[85,92,78,90],
    "数学":[90,85,88,95],
    "英语":[78,90,92,88]
})

df["总分"] = df["语文"] + df["数学"] + df["英语"]
df["平均分"] = df["总分"] / 3

df_sort = df.sort_values(by="总分", ascending=False)
print("排序后完整表格：\n", df_sort)

top_name = df_sort.iloc[0]["姓名"]
print(f"\n(3)总分最高同学姓名：{top_name}")