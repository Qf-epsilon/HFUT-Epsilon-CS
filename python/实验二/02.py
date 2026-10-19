count = int(input("输入测验次数:\n"))

if count < 5:
    print("测验次数不得少于5次")
else:
    print("依次输入成绩:")
    scores = list(map(int, input().split()))

    max_score = max(scores)
    min_score = min(scores)

    print("去掉最高分: {}".format(max_score))
    print("去掉最低分: {}".format(min_score))

    scores.remove(max_score)
    scores.remove(min_score)

    avg = sum(scores) / len(scores)
    print("输出:")
    print("综合测评成绩: {:.2f}".format(avg))