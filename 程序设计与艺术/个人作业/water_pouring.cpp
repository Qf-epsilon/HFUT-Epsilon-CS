#include <iostream>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;

struct State
{
    int a, b;       // 两个容器的水量
    int op;         // 到达此状态的操作编号
    int prev;       // 父状态在下标数组中的位置
};

string opNames[7] = {"", "倒满A", "倒满B", "清空A", "清空B", "A倒向B", "B倒向A"};

void printPath(vector<State>& states, int idx)
{
    if (idx == -1) return;
    printPath(states, states[idx].prev);
    if (states[idx].op != 0)
        cout << opNames[states[idx].op] << " → (" << states[idx].a << "," << states[idx].b << ")" << endl;
    else
        cout << "初始状态 (" << states[idx].a << "," << states[idx].b << ")" << endl;
}

void bfs(int capA, int capB, int target)
{
    bool visited[100][100];
    memset(visited, false, sizeof(visited));

    queue<int> q;
    vector<State> states;

    states.push_back({0, 0, 0, -1});
    q.push(0);
    visited[0][0] = true;

    while (!q.empty())
    {
        int curIdx = q.front(); q.pop();
        State cur = states[curIdx];

        if (cur.a == target || cur.b == target)
        {
            cout << "找到解！步骤：" << endl;
            printPath(states, curIdx);
            return;
        }

        // 6种操作
        int na, nb;
        int ops[6][2] = {{capA, cur.b}, {cur.a, capB}, {0, cur.b}, {cur.a, 0},
            {max(0, cur.a - (capB - cur.b)), min(capB, cur.b + cur.a)},
            {min(capA, cur.a + cur.b), max(0, cur.b - (capA - cur.a))}};

        for (int i = 0; i < 6; i++)
        {
            na = ops[i][0]; nb = ops[i][1];
            if (!visited[na][nb])
            {
                visited[na][nb] = true;
                states.push_back({na, nb, i + 1, curIdx});
                q.push(states.size() - 1);
            }
        }
    }
    cout << "No Solution" << endl;
}

int main()
{
    int capA = 3, capB = 5, target = 4;
    cout << "========== 倒水问题 ==========" << endl;
    cout << "容器A: " << capA << "升" << endl;
    cout << "容器B: " << capB << "升" << endl;
    cout << "目标水量: " << target << "升" << endl << endl;
    bfs(capA, capB, target);
    return 0;
}
