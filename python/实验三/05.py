import pandas as pd

sales_data = {
    "商品编号": [101, 102, 103, 104, 105],
    "商品类别": ["耳机", "鼠标", "键盘", "显示器", "音箱"],
    "单价": [199, 89, 145, 899, 260],
    "销量": [32, 86, 47, 15, 28]
}
df_make = pd.DataFrame(sales_data)
df_make.to_csv("sales.csv", encoding="utf-8-sig", index=False)

df_csv = pd.read_csv("sales.csv")
print("====读取csv文件sales.csv结果====")
print(df_csv.head())