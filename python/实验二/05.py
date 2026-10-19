def common_courses(a, b):
    set_a = set(a)
    set_b = set(b)
    common = set_a & set_b
    return list(common)

a_class = ["Python", "人工智能", "数据库", "计算机网络"]
b_class = ["Java", "数据库", "Python", "操作系统"]

result = common_courses(a_class, b_class)
print("共同课程:")
print(" ".join(result))