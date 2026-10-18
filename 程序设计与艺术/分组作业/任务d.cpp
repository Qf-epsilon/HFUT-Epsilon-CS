// 任务四：能源划分
// 题目：把n个数的数组分成不超过m段
// 每段的风险值 = 段长度 × (段内最大值 - 段内最小值)
// 求：怎么分能让最大的那段风险值尽可能小？
//
// 思路：二分答案 + 贪心验证
// 二分"最大风险值"的上限limit，然后贪心地尽量往右扩展每一段
// 如果段数不超过m，说明limit可行，试试更小的；否则要更大的
//
// 样例输入：
// 5 2
// 1 3 5 2 4
// 样例输出：
// 9
// 解释：分成[1,3]和[5,2,4]，风险值分别是2×(3-1)=4和3×(5-2)=9，最大是9

#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int a[100005];

// 检查：如果每段风险值不超过limit，能不能用不超过m段分完？
bool check(long long limit) {
    int segCount = 1;  // 至少1段
    int left = 0;      // 当前段从left开始

    while (left < n) {
        int right = left;
        int minVal = a[left];
        int maxVal = a[left];

        // 尽量往右扩展当前段
        while (right < n) {
            minVal = min(minVal, a[right]);
            maxVal = max(maxVal, a[right]);
            long long risk = (long long)(right - left + 1) * (maxVal - minVal);
            if (risk > limit) {
                break;  // 再加一个就超了，不能再扩展
            }
            right++;
        }

        // 如果连一个元素都放不下，说明limit太小了
        if (right == left) {
            return false;
        }

        left = right;  // 下一段从right开始
        if (left < n) {
            segCount++;
        }
    }

    return segCount <= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // 二分查找最小的可行limit
    long long low = 0;
    long long high = (long long)n * 1000000000LL;  // 最大可能的风险值

    while (low < high) {
        long long mid = (low + high) / 2;
        if (check(mid)) {
            high = mid;       // mid可行，试试更小的
        } else {
            low = mid + 1;    // mid不行，要更大
        }
    }

    cout << low << endl;

    return 0;
}
