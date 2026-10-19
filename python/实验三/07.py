import numpy as np

arr = np.random.randint(0, 101, 100)

count_gt_50 = np.sum(arr > 50)
print("大于 50 的元素个数:", count_gt_50)

arr_replaced = np.where(arr > 50, 0, arr)
print("替换后的数组:", arr_replaced)

values_gt_50 = arr[arr > 50]
print("大于 50 的元素原值:", values_gt_50)