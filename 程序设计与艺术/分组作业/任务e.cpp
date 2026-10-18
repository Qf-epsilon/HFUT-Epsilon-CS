// 任务五：智能调度
// 题目：有三个电池，电量分别是a, b, c
// 每次操作可以：
//   选两个电池各充1格
//   或者选一个电池充2格
// 求：最少几次操作能让三个电池电量一样？
//
// 思路：不管哪种操作，每次总电量都增加2
// 设目标电量为target，总增加量 = 3*target - sum，操作次数 = 总增加量/2
// 约束：target >= 最大值，总增加量必须是偶数
//       每个电池的增量不能超过总操作次数的2倍
//
// 样例输入：
// 1 2 3
// 样例输出：
// 3
// 解释：目标4，增量3+2+1=6，6/2=3次

#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    long long a[3];
    cin >> a[0] >> a[1] >> a[2];

    // 先排序，方便找最大值
    sort(a, a + 3);

    long long sum = a[0] + a[1] + a[2];
    long long target = a[2];  // 目标至少是最大值

    // 总增加量必须是偶数（每次操作+2）
    while ((3 * target - sum) % 2 != 0) {
        target++;
    }

    // 检查每个电池的增量约束
    for (int i = 0; i < 3; i++) {
        long long need = (sum - a[i] + 1) / 2;  // 这个电池要求target至少这么大
        while (target < need || (3 * target - sum) % 2 != 0) {
            target++;
        }
    }

    long long ans = (3 * target - sum) / 2;
    cout << ans << endl;

    return 0;
}
