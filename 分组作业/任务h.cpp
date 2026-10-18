// 任务八：电池续航
// 题目：给一个有向图，从节点s出发恰好走K步
// 到每个节点的所有路径中，"路径上最大边权"最小是多少？
// 如果走不到就输出-1
//
// 思路：矩阵快速幂的变体——min-max矩阵乘法
// 普通矩阵乘法是 C[i][j] = sum(A[i][k] * B[k][j])
// 这里改成 C[i][j] = min over k of max(A[i][k], B[k][j])
// 含义：走a步再走b步 = 走a+b步，路径最大边权取两段中较大的，再取所有中间点的最小值
// 用倍增预处理走2^p步的矩阵，然后把K拆成二进制逐位合并
//
// 样例输入：
// 3 3
// 1 2 5
// 2 3 3
// 1 3 10
// 1
// 1 2
// 样例输出：
// -1 -1 5
// 解释：从1走2步。到1：走不到(-1)；到2：走不到(-1)；到3：1->2->3，max(5,3)=5

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 2000000000;
int N;  // 节点数（全局变量，矩阵构造函数要用）

// 矩阵结构体
struct Matrix {
    int a[105][105];
    Matrix() {
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                a[i][j] = INF;
    }
};

// min-max矩阵乘法
Matrix multiply(const Matrix& A, const Matrix& B) {
    Matrix C;
    for (int i = 0; i < N; i++) {
        for (int k = 0; k < N; k++) {
            if (A.a[i][k] >= INF) continue;
            for (int j = 0; j < N; j++) {
                if (B.a[k][j] >= INF) continue;
                int val = max(A.a[i][k], B.a[k][j]);
                if (val < C.a[i][j]) {
                    C.a[i][j] = val;
                }
            }
        }
    }
    return C;
}

int main() {
    int M;
    cin >> N >> M;

    // 读入边，构建基础矩阵（走1步的情况）
    Matrix base;
    for (int i = 0; i < M; i++) {
        int u, v, w;
        cin >> u >> v >> w;
        u--; v--;  // 转成0-based编号
        if (w < base.a[u][v]) {
            base.a[u][v] = w;  // 重边取最小的
        }
    }

    // 倍增：pw[p] = 走2^p步的矩阵
    int LOG = 31;
    vector<Matrix> pw(LOG);
    pw[0] = base;
    for (int p = 1; p < LOG; p++) {
        pw[p] = multiply(pw[p - 1], pw[p - 1]);  // 2^p = 2^(p-1) + 2^(p-1)
    }

    int Q;
    cin >> Q;

    while (Q--) {
        int s, K;
        cin >> s >> K;
        s--;  // 转成0-based

        // cur[i] = 从s出发，当前已走步数下，到i的路径中最小的最大边权
        vector<int> cur(N, INF);
        cur[s] = 0;  // 起点到自己，还没走，最大边权为0

        // 把K拆成二进制，逐位合并
        for (int p = 0; p < LOG; p++) {
            if (K & (1 << p)) {  // 第p位是1，要合并走2^p步
                vector<int> nxt(N, INF);
                for (int i = 0; i < N; i++) {
                    if (cur[i] >= INF) continue;
                    for (int j = 0; j < N; j++) {
                        if (pw[p].a[i][j] >= INF) continue;
                        int val = max(cur[i], pw[p].a[i][j]);
                        if (val < nxt[j]) {
                            nxt[j] = val;
                        }
                    }
                }
                cur = nxt;
            }
        }

        // 输出结果
        for (int i = 0; i < N; i++) {
            if (i > 0) cout << " ";
            if (cur[i] >= INF) {
                cout << -1;
            } else {
                cout << cur[i];
            }
        }
        cout << endl;
    }

    return 0;
}
