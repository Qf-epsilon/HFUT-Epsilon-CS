#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 构建next数组（部分匹配表）
void getNext(string p, vector<int>& next)
{
    int m = p.length();
    next[0] = -1;
    int i = 0, j = -1;
    while (i < m - 1)
    {
        if (j == -1 || p[i] == p[j])
        {
            i++; j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

// KMP搜索
void kmpSearch(string t, string p)
{
    int n = t.length(), m = p.length();
    vector<int> next(m);
    getNext(p, next);

    // 输出next数组
    cout << "模式串: " << p << endl;
    cout << "next数组: ";
    for (int i = 0; i < m; i++)
        cout << next[i] << " ";
    cout << endl << endl;

    int i = 0, j = 0;
    int count = 0;
    while (i < n)
    {
        if (j == -1 || t[i] == p[j])
        {
            i++; j++;
        }
        else
        {
            j = next[j];
        }
        if (j == m)
        {
            cout << "找到匹配，位置: " << i - m << endl;
            count++;
            j = next[j - 1];  // 继续搜索下一个匹配
        }
    }
    if (count == 0)
        cout << "未找到匹配" << endl;
}

int main()
{
    string text, pattern;

    cout << "========== KMP字符串匹配 ==========" << endl;
    cout << "输入文本串: ";
    getline(cin, text);
    cout << "输入模式串: ";
    getline(cin, pattern);

    cout << "\n文本串: " << text << endl;
    cout << "文本串长度: " << text.length() << endl;
    cout << "模式串长度: " << pattern.length() << endl << endl;

    kmpSearch(text, pattern);
    return 0;
}
