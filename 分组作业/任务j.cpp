// 任务十：生产优化
// 题目：DAG（有向无环图），从节点1到节点n
// 每条边有原始耗时w和优化后耗时c（c <= w）
// 最多可以优化K条边（用优化后的耗时），求最短路径
//
// 思路：DAG上的动态规划
// dp[u][j] = 到达节点u，已经用了j次优化的最短路径
// 因为DAG的节点编号就是拓扑序，直接按编号从小到大遍历即可
// 对每条边有两种选择：不优化（用w）或优化（用c，j+1）
//
// 样例输入：
// 3 2 2
// 1 2 10 5
// 2 3 10 5
// 样例输出：
// 10
// 解释：路径1->2->3，两条边都优化，5+5=10

#include <iostream>
#include <vector>
using namespace std;

const long long INF = 1e18;

// 边的结构体
struct Edge {
    int to;         // 目标节点
    int origTime;   // 原始耗时
    int optTime;    // 优化后耗时
};

int main() {
    int n, m, K;
    cin >> n >> m >> K;

    // 邻接表存图
    vector<vector<Edge>> graph(n);

    for (int i = 0; i < m; i++) {
        int u, v, w, c;
        cin >> u >> v >> w >> c;
        u--; v--;  // 转成0-based编号
        Edge e;
        e.to = v;
        e.origTime = w;
        e.optTime = c;
        graph[u].push_back(e);
    }

    // dp[u][j] = 到节点u用了j次优化的最短路径
    vector<vector<long long>> dp(n, vector<long long>(K + 1, INF));
    dp[0][0] = 0;  // 起点，还没用优化

    // 按拓扑序（节点编号顺序）遍历
    for (int u = 0; u < n; u++) {
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].origTime;
            int c = graph[u][i].optTime;

            for (int j = 0; j <= K; j++) {
                if (dp[u][j] >= INF) continue;  // 不可达，跳过

                // 选择1：不优化这条边
                if (dp[u][j] + w < dp[v][j]) {
                    dp[v][j] = dp[u][j] + w;
                }

                // 选择2：优化这条边（还有优化次数的话）
                if (j < K) {
                    if (dp[u][j] + c < dp[v][j + 1]) {
                        dp[v][j + 1] = dp[u][j] + c;
                    }
                }
            }
        }
    }

    // 在终点的所有状态中取最小值
    long long ans = INF;
    for (int j = 0; j <= K; j++) {
        ans = min(ans, dp[n - 1][j]);
    }

    cout << ans << endl;

    return 0;
}
