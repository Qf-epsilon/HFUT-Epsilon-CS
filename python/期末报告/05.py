miao = int(input("输入总秒数："))
h = miao // 3600
m = (miao % 3600) // 60
s = miao % 60
print(f"{h}:{m}:{s}")