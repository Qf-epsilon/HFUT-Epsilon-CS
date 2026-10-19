import numpy as np
import matplotlib.pyplot as plt

np.random.seed(3)
n = 100
x = np.random.rand(n)
y = np.random.rand(n)
sizes = np.random.randint(20,200,size=n)
colors = np.random.rand(n)

plt.figure()
sc = plt.scatter(x, y, s=sizes, c=colors, cmap="viridis")
plt.colorbar(sc)
plt.title("随机散点图，大小颜色随机")
plt.show()