#输入年月日，输出该日期是否是闰年，并且输出该日期是此年份的第几天。
year=int(input("请输入年份："))
month=int(input("请输入月份："))
day=int(input("请输入日期："))
num=(year%4==0 and year%100!=0) or (year%400==0)
if num:
    print(f"{year}年是闰年")
else:
    print(f"{year}年不是闰年")
month_days=[31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
if num:
    month_days[1]=29
days_num=sum(month_days[:month - 1])+day
print(f"该日期是{year}年的第 {days_num} 天")