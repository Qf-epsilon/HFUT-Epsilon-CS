import matplotlib.pyplot as plt
import numpy as np

fig, axs = plt.subplots(2, 2, figsize=(10, 8))

axs[0, 0].plot([1, 2, 3, 4], [1, 4, 9, 16], marker="o")
axs[0, 0].set_title("Line Chart")

axs[0, 1].scatter(np.random.rand(20), np.random.rand(20), color="r")
axs[0, 1].set_title("Scatter Plot")

axs[1, 0].bar(["A", "B", "C"], [3, 7, 5], color="g")
axs[1, 0].set_title("Bar Chart")

axs[1, 1].pie([30, 20, 50], labels=["X", "Y", "Z"], autopct="%1.1f%%")
axs[1, 1].set_title("Pie Chart")

plt.tight_layout()
plt.show()