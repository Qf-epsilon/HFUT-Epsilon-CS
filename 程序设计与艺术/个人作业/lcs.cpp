#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

const int MAX = 100;
int dp[MAX][MAX];

string getLCS(string a, string b, int m, int n)
{
    if (m == 0 || n == 0) return "";
    if (a[m-1] == b[n-1])
        return getLCS(a, b, m-1, n-1) + a[m-1];
    if (dp[m-1][n] > dp[m][n-1])
        return getLCS(a, b, m-1, n);
    return getLCS(a, b, m, n-1);
}

int main()
{
    string a, b;
    cout << "========== 最长公共子序列(LCS) ==========" << endl;
    cout << "输入第一个字符串: ";
    cin >> a;
    cout << "输入第二个字符串: ";
    cin >> b;

    int m = a.length(), n = b.length();

    // 填充DP表
    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
            else if (a[i-1] == b[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    // 输出DP表
    cout << "\nDP表:" << endl;
    cout << "    ";
    for (int j = 0; j < n; j++) cout << b[j] << " ";
    cout << endl;
    for (int i = 0; i <= m; i++)
    {
        if (i == 0) cout << "  ";
        else cout << a[i-1] << " ";
        for (int j = 0; j <= n; j++)
            cout << dp[i][j] << " ";
        cout << endl;
    }

    cout << "\nLCS长度: " << dp[m][n] << endl;
    cout << "LCS序列: " << getLCS(a, b, m, n) << endl;
    return 0;
}
