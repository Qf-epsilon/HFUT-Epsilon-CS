import matplotlib.pyplot as plt
import numpy as np

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
x = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20]
y = [1, 3, 5, 7, 9, 11, 13, 15, 17, 19]
z = [10, 8, 6, 9, 7, 5, 8, 4, 6, 3]
ax.scatter(x,y,z,c="blue",s=80,marker="D")
ax.set_title("监测点空间分布图")
ax.set_xlabel("经度")
ax.set_ylabel("纬度")
ax.set_zlabel("海拔 (m)")
plt.show()