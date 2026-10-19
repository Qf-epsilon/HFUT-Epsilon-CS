import pandas as pd
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

file_path = r"C:\Users\25575\Desktop\新建文件夹 (2)\drug_order_detail_1.xlsx"
df = pd.read_excel(file_path, engine="openpyxl")
df["销售额"] = df["价格"] * df["销量"]
total_all = df["销售额"].sum()
print(f"所有分店总销售额是:{total_all}")

group_res = df.groupby("分店")["销售额"].agg(["min","max","mean"])
print(group_res)

df.boxplot(column="销售额",by="分店")
plt.title("各分店销售额分布")
plt.tight_layout()
plt.show()