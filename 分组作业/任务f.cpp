// 任务六：出厂校准
// 题目：有m条产线，每条产线提供四种元素(Li,Co,Ni,Mn)的不同数量，花费也不同
// 要选一些产线，让四种元素的总量都达到最低需求，且总花费最小
//
// 思路：四维0-1背包DP
// dp[a][b][c][d] = 四种元素分别累计a,b,c,d时的最小花费
// 超过30的部分截断为30（因为需求最大30）
// 最后在所有满足需求的状态中找最小花费
//
// 样例输入：
// 5 5 5 5
// 3
// 5 5 5 5 100
// 10 0 0 0 50
// 0 10 0 0 50
// 样例输出：
// 100
// 解释：选第一条产线（花费100），四种各5，刚好满足

#include <iostream>
#include <algorithm>
using namespace std;

const int INF = 1000000000;
int dp[31][31][31][31];  // 四维DP表

int main() {
    int needLi, needCo, needNi, needMn;
    cin >> needLi >> needCo >> needNi >> needMn;

    // 初始化：所有状态设为无穷大（不可达）
    for (int a = 0; a <= 30; a++)
        for (int b = 0; b <= 30; b++)
            for (int c = 0; c <= 30; c++)
                for (int d = 0; d <= 30; d++)
                    dp[a][b][c][d] = INF;

    dp[0][0][0][0] = 0;  // 什么都不选，花费为0

    int m;
    cin >> m;

    // 逐个产线做0-1背包（逆序更新，保证每条产线只选一次）
    for (int i = 0; i < m; i++) {
        int li, co, ni, mn, cost;
        cin >> li >> co >> ni >> mn >> cost;

        for (int a = 30; a >= 0; a--)
            for (int b = 30; b >= 0; b--)
                for (int c = 30; c >= 0; c--)
                    for (int d = 30; d >= 0; d--) {
                        if (dp[a][b][c][d] >= INF) continue;  // 不可达状态跳过
                        // 选这条产线，四种元素分别增加
                        int na = min(30, a + li);
                        int nb = min(30, b + co);
                        int nc = min(30, c + ni);
                        int nd = min(30, d + mn);
                        dp[na][nb][nc][nd] = min(dp[na][nb][nc][nd], dp[a][b][c][d] + cost);
                    }
    }

    // 在满足最低需求的所有状态中找最小花费
    int ans = INF;
    for (int a = needLi; a <= 30; a++)
        for (int b = needCo; b <= 30; b++)
            for (int c = needNi; c <= 30; c++)
                for (int d = needMn; d <= 30; d++)
                    ans = min(ans, dp[a][b][c][d]);

    if (ans >= INF) {
        cout << "Impossible" << endl;
    } else {
        cout << ans << endl;
    }

    return 0;
}
