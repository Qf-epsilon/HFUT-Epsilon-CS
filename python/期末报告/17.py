import numpy as np
import matplotlib.pyplot as plt

plt.rcParams['font.sans-serif'] = ['Microsoft YaHei']
plt.rcParams['axes.unicode_minus'] = False

if __name__ == '__main__':
    data = [
        np.random.randint(60, 95, 20),
        np.random.randint(50, 88, 20),
        np.random.randint(70, 98, 20)
    ]
    bp = plt.boxplot(data, patch_artist=True)
    plt.xticks([1, 2, 3], ["A","B","C"])
    colors = ["#ffaaaa","#aaffaa","#aaaaff"]
    for box,color in zip(bp['boxes'], colors):
        box.set(facecolor=color)

    plt.title("三组数据箱线图")
    plt.ylabel("数值")
    plt.show()