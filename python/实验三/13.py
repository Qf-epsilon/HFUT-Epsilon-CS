import matplotlib.pyplot as plt

departments = ["研发部", "市场部", "销售部", "人事部", "财务部"]
sizes = [45, 20, 25, 6, 4]
explode = (0.1, 0, 0, 0, 0)  # 突出显示研发部

plt.pie(
    sizes,
    explode=explode,
    labels=departments,
    autopct="%1.1f%%",
    shadow=True,
    startangle=140,
)
plt.title("Department Headcount Distribution")
plt.show()