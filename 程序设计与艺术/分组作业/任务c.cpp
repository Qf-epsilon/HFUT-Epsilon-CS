// 任务三：平滑信号
// 题目：给一个长度为n的序列和整数k
// "平滑序列"的定义：对于所有窗口大小 w (1<=w<=k)，
//   滑动均值滤波后的序列 B(w) 必须是常数序列（所有值相等）
//
// 关键推导：
//   当 w=1 时，B(1) 就是原序列 A 本身
//   所以 B(1) 是常数序列 => A 中所有元素必须相等
//   只要所有元素相等，任何窗口的均值也都相等
//   因此问题转化为：把所有元素改成同一个值，最少改几个
//   答案 = n - 出现次数最多的值的出现次数
//
// 样例输入：
// 5 3
// 1 2 2 2 3
// 样例输出：
// 2
// 解释：2出现了3次最多，把1和3改成2，共改2个

#include <iostream>
#include <map>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    map<int, int> cnt;  // 统计每个值出现几次
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        cnt[x]++;
    }

    // 找出出现次数最多的值
    int maxCnt = 0;
    for (auto& p : cnt) {
        if (p.second > maxCnt) {
            maxCnt = p.second;
        }
    }

    // 最少修改次数 = 总数 - 最多出现次数
    cout << n - maxCnt << endl;

    return 0;
}
