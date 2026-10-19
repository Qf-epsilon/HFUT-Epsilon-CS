import numpy as np

arr = np.random.rand(4, 5)

mean_val = np.mean(arr)
std_val = np.std(arr)
print(f"均值: {mean_val:.4f}, 标准差: {std_val:.4f}")

max_cols = np.max(arr, axis=0)
print("每列最大值:", max_cols)

sum_rows = np.sum(arr, axis=1)
print("每行和:", sum_rows)

max_idx = np.unravel_index(np.argmax(arr), arr.shape)
print("全局最大值位置 (行, 列):", max_idx)