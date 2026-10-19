def matrix_statistics(matrix):
    total_sum = 0
    all_num = []
    pos_count = 0
    neg_count = 0
    zero_count = 0

    for row in matrix:
        for val in row:
            total_sum = total_sum + val
            all_num.append(val)

            if val > 0:
                pos_count += 1
            elif val < 0:
                neg_count += 1
            else:
                zero_count += 1

    max_val = max(all_num)
    min_val = min(all_num)
    avg_val = total_sum / len(all_num)

    print("元素之和:", total_sum)
    print("最大值:", max_val)
    print("最小值:", min_val)
    print("平均值:", avg_val)
    print("正数个数:", pos_count)
    print("负数个数:", neg_count)
    print("零的个数:", zero_count)