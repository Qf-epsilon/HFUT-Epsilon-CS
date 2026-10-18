// 任务七：服务划分
// 题目：一棵树有n个节点，每个节点有需求量
// 给k个服务中心，每个节点归属距离最近的服务中心
// 输出每个服务中心的服务总量（它管辖的所有节点需求量之和）
// 支持三种操作：修改节点需求、修改边权、查询
//
// 思路：每次查询用多源Dijkstra
// 把所有服务中心同时放进优先队列，距离为0
// 然后跑Dijkstra，每个节点记录它归属哪个服务中心
// 最后统计每个服务中心的总需求量
//
// 样例输入：
// 3
// 1 2 3
// 1 2 1
// 2 3 2
// 1
// 3 2 1 3
// 样例输出：
// 3 3
// 解释：服务中心是1和3。节点1、2归中心1（需求1+2=3），节点3归中心3（需求3）

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

const long long INF = 1e18;

// 边的结构体
struct Edge {
    int to;      // 连向哪个节点
    int weight;  // 边权
};

int n;
vector<long long> demand;           // 每个节点的需求量
vector<vector<Edge>> graph;         // 邻接表

// 处理一次查询
void solveQuery() {
    int k;
    cin >> k;

    vector<int> centers(k);
    for (int i = 0; i < k; i++) {
        cin >> centers[i];
    }

    // 多源Dijkstra
    vector<long long> dist(n + 1, INF);  // 到最近服务中心的距离
    vector<int> belong(n + 1, 0);        // 归属哪个服务中心

    // 优先队列，存<距离, 节点>，距离小的优先
    priority_queue<pair<long long, int>,
                   vector<pair<long long, int>>,
                   greater<pair<long long, int>>> pq;

    // 所有服务中心作为起点，距离为0
    for (int i = 0; i < k; i++) {
        int s = centers[i];
        dist[s] = 0;
        belong[s] = s;
        pq.push(make_pair(0LL, s));
    }

    while (!pq.empty()) {
        long long curDist = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        // 过时的记录，跳过
        if (curDist != dist[u]) continue;

        // 遍历u的所有邻居
        for (int i = 0; i < (int)graph[u].size(); i++) {
            int v = graph[u][i].to;
            int w = graph[u][i].weight;
            long long newDist = curDist + w;

            // 距离更短，或者距离相同但服务中心编号更小（编号小的优先）
            if (newDist < dist[v] || (newDist == dist[v] && belong[u] < belong[v])) {
                dist[v] = newDist;
                belong[v] = belong[u];
                pq.push(make_pair(newDist, v));
            }
        }
    }

    // 统计每个服务中心的服务总量
    vector<long long> ans(k, 0);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < k; j++) {
            if (belong[i] == centers[j]) {
                ans[j] += demand[i];
                break;
            }
        }
    }

    // 输出
    for (int i = 0; i < k; i++) {
        if (i > 0) cout << " ";
        cout << ans[i];
    }
    cout << endl;
}

int main() {
    cin >> n;

    demand.resize(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> demand[i];
    }

    graph.resize(n + 1);
    for (int i = 0; i < n - 1; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        // 无向边，两边都要加
        Edge e1, e2;
        e1.to = v; e1.weight = w;
        e2.to = u; e2.weight = w;
        graph[u].push_back(e1);
        graph[v].push_back(e2);
    }

    int q;
    cin >> q;

    while (q--) {
        int op;
        cin >> op;

        if (op == 1) {
            // 修改节点需求
            int u;
            long long val;
            cin >> u >> val;
            demand[u] = val;
        } else if (op == 2) {
            // 修改边权
            int u, v, w;
            cin >> u >> v >> w;
            for (int i = 0; i < (int)graph[u].size(); i++) {
                if (graph[u][i].to == v) {
                    graph[u][i].weight = w;
                    break;
                }
            }
            for (int i = 0; i < (int)graph[v].size(); i++) {
                if (graph[v][i].to == u) {
                    graph[v][i].weight = w;
                    break;
                }
            }
        } else {
            // 查询
            solveQuery();
        }
    }

    return 0;
}
