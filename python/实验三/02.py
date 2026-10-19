import matplotlib.pyplot as plt
import numpy as np

x = np.linspace(-10,10, 200)
y = 3 * x**2 + 5 * x + 6

plt.plot(x, y)
plt.xlabel("x")
plt.ylabel("y")
plt.grid(True)
plt.show()