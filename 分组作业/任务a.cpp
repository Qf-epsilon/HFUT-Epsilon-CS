// 任务一：间距调整
// 题目：从数字1出发，通过三种操作走到数字n
//   操作A：当前数字 +1
//   操作B：当前数字 ×2
//   操作C：当前数字 -1
// 求：最少需要几步？并输出字典序最小的操作序列
//
// 思路：从n反向BFS到1（反向操作：A变成-1，B变成/2，C变成+1）
// BFS保证第一次到达1时步数最少
// 反向BFS时按A、B、C的顺序扩展，保证字典序最小
//
// 样例输入：
// 10
// 样例输出：
// 4
// ABAB
// 解释：1 -(A:+1)-> 2 -(B:x2)-> 4 -(A:+1)-> 5 -(B:x2)-> 10，共4步

#include <iostream>
#include <queue>
#include <string>
using namespace std;
const int MAXN = 2000005;  // 数组开大一点，防止越界
int dist[MAXN];            // dist[i] 表示从n走到i最少需要几步
int pre[MAXN];             // pre[i] 记录i是从哪个节点走过来的（前驱）
char op[MAXN];             // op[i] 记录从pre[i]走到i用的是什么操作
int main() {
    int n;
    cin >> n;
    // 特判：如果n就是1，不需要任何操作
    if (n == 1) {
        cout << 0 << endl;
        cout << endl;
        return 0;
    }
    // 初始化：所有距离设为-1，表示还没访问过
    for (int i = 0; i < MAXN; i++) {
        dist[i] = -1;
    }
    // 从n开始反向BFS
    queue<int> q;
    q.push(n);
    dist[n] = 0;  // n到自己的距离是0

    while (!q.empty()) {
        int x = q.front();
        q.pop();
        // 已经走到1了，可以停了
        if (x == 1) break;
        // 反向操作A：x -> x-1（正向是+1，反向就是-1）
        // 按A、B、C的顺序扩展，保证字典序最小
        if (x - 1 >= 1 && dist[x - 1] == -1) {
            dist[x - 1] = dist[x] + 1;
            pre[x - 1] = x;
            op[x - 1] = 'A';
            q.push(x - 1);
        }
        // 反向操作B：x -> x/2（只有偶数才能除以2）
        if (x % 2 == 0 && dist[x / 2] == -1) {
            dist[x / 2] = dist[x] + 1;
            pre[x / 2] = x;
            op[x / 2] = 'B';
            q.push(x / 2);
        }
        // 反向操作C：x -> x+1（正向是-1，反向就是+1）
        if (x + 1 < MAXN && dist[x + 1] == -1) {
            dist[x + 1] = dist[x] + 1;
            pre[x + 1] = x;
            op[x + 1] = 'C';
            q.push(x + 1);
        }
    }
    // 从1沿着前驱指针走回n，把操作拼起来
    // 因为反向BFS时op记录的就是正向操作，所以直接顺序拼接
    string path = "";
    int cur = 1;
    while (cur != n) {
        path += op[cur];
        cur = pre[cur];
    }
    // 输出结果
    cout << dist[1] << endl;   // 最少步数
    cout << path << endl;      // 操作序列

    return 0;
}
