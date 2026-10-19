import numpy as np

np.random.seed(1)
score_mat = np.random.randint(60,101,size=(30,4))
print("成绩矩阵：")
print(score_mat)

course_mean = score_mat.mean(axis=0)
course_max = score_mat.max(axis=0)
course_min = score_mat.min(axis=0)
course_std = score_mat.std(axis=0)
print("每门课平均分",course_mean)
print("每门课最高分",course_max)
print("每门课最低分",course_min)
print("每门课标准差",course_std)

stu_total = score_mat.sum(axis=1)
stu_avg = score_mat.mean(axis=1)

idx_sort = np.argsort(-stu_avg)
top5_idx = idx_sort[:5]
print("平均分前5学生序号以及各科成绩：")
for i in top5_idx:
    print(f"学生{i}:{score_mat[i]}")