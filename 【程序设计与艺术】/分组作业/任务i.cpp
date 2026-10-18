// 任务九：电池健康
// 题目：电池仓库管理，支持四种操作：
//   1 name：买进新电池（循环次数为0）
//   2：取用电池（优先取循环次数少的，相同取入库早的）
//   3 name：归还电池（循环次数+1，达到K次则报废）
//   4：查询当前库存数量
//
// 思路：用优先队列（小根堆）维护仓库
// 优先队列按(循环次数, 入库时间)排序，循环少的优先，相同则时间早的优先
// 注意：优先队列里的记录可能过时（电池已被取走或归还过），取出时要检查有效性
//
// 样例输入：
// 6 2
// 1 A
// 1 B
// 2
// 3 A
// 2
// 4
// 样例输出：
// A
// B
// 1
// 解释：买进A和B；取用A（循环0最早）；归还A循环变1；取用B（B循环0<A循环1）；库存剩A共1个

#include <iostream>
#include <queue>
#include <string>
#include <map>
using namespace std;

// 电池信息
struct Battery {
    string name;   // 名称
    int cycles;    // 循环次数
    int time;      // 入库时间戳

    // 优先队列是大根堆，所以要反过来定义
    // 循环次数少的优先，相同则入库时间早的优先
    bool operator<(const Battery& other) const {
        if (cycles != other.cycles) {
            return cycles > other.cycles;  // 循环多的"小"，排后面
        }
        return time > other.time;  // 时间晚的"小"，排后面
    }
};

int main() {
    int Q, K;
    cin >> Q >> K;

    priority_queue<Battery> warehouse;  // 仓库（优先队列）
    map<string, int> cycles;             // 每个电池当前的循环次数
    map<string, bool> inStock;           // 是否在仓库中
    map<string, bool> inUse;             // 是否在使用中
    int timer = 0;                       // 全局时间戳

    while (Q--) {
        int op;
        cin >> op;

        if (op == 1) {
            // 买进新电池
            string name;
            cin >> name;
            cycles[name] = 0;
            inStock[name] = true;
            inUse[name] = false;

            Battery b;
            b.name = name;
            b.cycles = 0;
            b.time = timer++;
            warehouse.push(b);

        } else if (op == 2) {
            // 取用电池：从优先队列里找第一个有效的
            while (!warehouse.empty()) {
                Battery b = warehouse.top();
                warehouse.pop();
                // 检查是否还有效（没被取走，且循环次数没变）
                if (inStock[b.name] && cycles[b.name] == b.cycles) {
                    inStock[b.name] = false;
                    inUse[b.name] = true;
                    cout << b.name << endl;
                    break;
                }
            }

        } else if (op == 3) {
            // 归还电池
            string name;
            cin >> name;
            cycles[name]++;   // 充放电一次
            inUse[name] = false;

            if (cycles[name] >= K) {
                // 达到报废次数
                cout << name << endl;
                inStock[name] = false;
            } else {
                // 重新入库
                inStock[name] = true;
                Battery b;
                b.name = name;
                b.cycles = cycles[name];
                b.time = timer++;
                warehouse.push(b);
            }

        } else if (op == 4) {
            // 查询库存数量
            int count = 0;
            for (map<string, bool>::iterator it = inStock.begin(); it != inStock.end(); it++) {
                if (it->second) {
                    count++;
                }
            }
            cout << count << endl;
        }
    }

    return 0;
}
