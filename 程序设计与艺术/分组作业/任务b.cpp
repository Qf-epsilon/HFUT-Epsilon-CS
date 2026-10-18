// 任务二：缓存技术
// 题目：模拟LRU（最近最少使用）缓存
//   缓存有C个位置，支持两种操作：
//   READ key：读取key对应的值，如果缓存里没有就从主存加载
//   WRITE key value：把key的值改成value
//   缓存满了就淘汰最久没用的，如果是脏数据（被改过）要先写回主存
//
// 思路：用list维护使用顺序（前面是最近用的，后面是最久没用的）
//       用map记录缓存内容和主存内容
//
// 样例输入（第一行是缓存容量，第二行是分号分隔的操作序列）：
// 2
// READ 1;WRITE 1 10;READ 1;READ 2
// 样例输出：
// READ 1:Miss,loaded,value=1
// WRITE 1 10:Hit,updated
// READ 1:Hit,value=10
// READ 2:Miss,loaded,value=2
//
// Cachestate(MRU->LRU):
// 2:2
// 1:10

#include <iostream>
#include <string>
#include <list>
#include <map>
#include <sstream>
#include <vector>
using namespace std;

// 缓存里每个条目的信息
struct CacheEntry {
    int key;
    int value;
    bool dirty;  // true表示被修改过，需要写回主存
};

int main() {
    int C;  // 缓存容量
    cin >> C;
    cin.ignore();  // 吃掉换行符，不然getline会读到空行

    // 读一整行操作序列
    string line;
    getline(cin, line);

    // 按分号把操作拆开
    vector<string> ops;
    string token;
    stringstream ss(line);
    while (getline(ss, token, ';')) {
        // 去掉头尾空格
        int start = 0;
        while (start < (int)token.size() && token[start] == ' ') start++;
        int end = (int)token.size() - 1;
        while (end >= 0 && token[end] == ' ') end--;
        if (start <= end) {
            ops.push_back(token.substr(start, end - start + 1));
        }
    }
    // 缓存：key -> 条目
    map<int, CacheEntry> cache;
    // LRU链表：前面是最近用的，后面是最久没用的
    list<int> lruList;
    // 主存：记录被写回的值
    map<int, int> memory;
    // 逐个处理操作
    for (int i = 0; i < (int)ops.size(); i++) {
        stringstream ts(ops[i]);
        string cmd;
        ts >> cmd;

        if (cmd == "READ") {
            int key;
            ts >> key;

            if (cache.find(key) != cache.end()) {
                // 缓存命中！直接读
                cout << "READ " << key << ":Hit,value=" << cache[key].value << endl;
                // 把这个key移到链表最前面（标记为最近使用）
                lruList.remove(key);
                lruList.push_front(key);
            } else {
                // 缓存没有，要从主存加载
                int val = key;  // 默认值就是key本身
                if (memory.find(key) != memory.end()) {
                    val = memory[key];  // 主存里有记录就用主存的值
                }

                // 缓存满了？淘汰最久没用的
                if (C > 0 && (int)cache.size() >= C) {
                    int lruKey = lruList.back();  // 最后面的是最久没用的
                    lruList.pop_back();
                    if (cache[lruKey].dirty) {
                        // 脏数据要写回主存
                        memory[cache[lruKey].key] = cache[lruKey].value;
                    }
                    cache.erase(lruKey);
                }

                // 把新数据放进缓存
                if (C > 0) {
                    CacheEntry e;
                    e.key = key;
                    e.value = val;
                    e.dirty = false;
                    cache[key] = e;
                    lruList.push_front(key);
                }

                cout << "READ " << key << ":Miss,loaded,value=" << val << endl;
            }
        } else if (cmd == "WRITE") {
            int key, value;
            ts >> key >> value;

            if (cache.find(key) != cache.end()) {
                // 缓存里有，直接改，标记为脏
                cache[key].value = value;
                cache[key].dirty = true;
                cout << "WRITE " << key << " " << value << ":Hit,updated" << endl;
                lruList.remove(key);
                lruList.push_front(key);
            } else {
                // 缓存里没有，写分配
                if (C > 0) {
                    if ((int)cache.size() >= C) {
                        int lruKey = lruList.back();
                        lruList.pop_back();
                        if (cache[lruKey].dirty) {
                            memory[cache[lruKey].key] = cache[lruKey].value;
                        }
                        cache.erase(lruKey);
                    }
                    CacheEntry e;
                    e.key = key;
                    e.value = value;
                    e.dirty = true;
                    cache[key] = e;
                    lruList.push_front(key);
                } else {
                    // 缓存容量为0，直接写主存
                    memory[key] = value;
                }
                cout << "WRITE " << key << " " << value << ":Miss,loaded and updated" << endl;
            }
        }
    }

    // 最后输出缓存状态
    cout << endl;
    if (cache.empty()) {
        cout << "Cache is empty." << endl;
    } else {
        cout << "Cachestate(MRU->LRU):" << endl;
        for (list<int>::iterator it = lruList.begin(); it != lruList.end(); it++) {
            cout << *it << ":" << cache[*it].value << endl;
        }
    }

    return 0;
}
