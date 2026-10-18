#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 大数乘法
string multiply(string num, int x)
{
    int carry = 0;
    for (int i = num.size() - 1; i >= 0; i--)
    {
        int cur = (num[i] - '0') * x + carry;
        num[i] = cur % 10 + '0';
        carry = cur / 10;
    }
    while (carry)
    {
        num.insert(num.begin(), carry % 10 + '0');
        carry /= 10;
    }
    return num;
}

// 大数除法
string divide(string num, int x)
{
    int rem = 0;
    for (int i = 0; i < num.size(); i++)
    {
        int cur = rem * 10 + (num[i] - '0');
        num[i] = cur / x + '0';
        rem = cur % x;
    }
    int pos = num.find_first_not_of('0');
    return pos == string::npos ? "0" : num.substr(pos);
}

// 计算组合数 C(n,k) 用大数
string combination(int n, int k)
{
    if (k > n - k) k = n - k;
    string res = "1";
    for (int i = 1; i <= k; i++)
    {
        res = multiply(res, n - k + i);
        res = divide(res, i);
    }
    return res;
}

// 计算阶乘
string factorial(int n)
{
    string res = "1";
    for (int i = 2; i <= n; i++)
        res = multiply(res, i);
    return res;
}

// 计算Catalan数 C(n) = C(2n,n) / (n+1)
string catalan(int n)
{
    string c = combination(2 * n, n);
    return divide(c, n + 1);
}

int main()
{
    cout << "========== 买票问题(Catalan数) ==========" << endl;
    cout << "票价: 5元，持5元人数n，持10元人数m" << endl << endl;

    int testCases[][2] = {{3,3}, {5,3}, {10,10}, {15,15}};
    int numTests = sizeof(testCases) / sizeof(testCases[0]);

    for (int t = 0; t < numTests; t++)
    {
        int n = testCases[t][0], m = testCases[t][1];
        cout << "n=" << n << ", m=" << m << endl;

        if (n < m)
        {
            cout << "结果: 0（5元人数少于10元人数，无法找零）" << endl << endl;
            continue;
        }

        // 当n==m时，结果为 Catalan(n) * n! * m!
        // 当n>m时，用DP计算
        if (n == m)
        {
            string cat = catalan(n);
            string fn = factorial(n);
            string fm = factorial(m);
            string result = multiply(multiply(cat, n), m);  // 简化：cat * n! * n!
            cout << "Catalan数 C(" << n << ") = " << cat << endl;
            cout << n << "! = " << fn << endl;

            // 重新精确计算：cat * n! * n!
            result = multiply(cat, n);
            for (int i = n - 1; i >= 2; i--)
                result = multiply(result, i);
            for (int i = n; i >= 2; i--)
                result = multiply(result, i);

            cout << "结果: " << result << endl;
        }
        else
        {
            // DP解法：dp[i][j]表示i个5元和j个10元的有效排列数
            vector<vector<string>> dp(n + 1, vector<string>(m + 1, "0"));
            for (int i = 0; i <= n; i++) dp[i][0] = "1";
            for (int i = 1; i <= n; i++)
            {
                for (int j = 1; j <= min(i, m); j++)
                {
                    // dp[i][j] = dp[i-1][j] + dp[i][j-1]
                    string a = dp[i-1][j];
                    string b = dp[i][j-1];
                    // 大数加法
                    int carry = 0, k = 0;
                    string sum = "";
                    while (k < a.size() || k < b.size() || carry)
                    {
                        int da = (k < a.size()) ? a[a.size()-1-k] - '0' : 0;
                        int db = (k < b.size()) ? b[b.size()-1-k] - '0' : 0;
                        int s = da + db + carry;
                        sum = char(s % 10 + '0') + sum;
                        carry = s / 10;
                        k++;
                    }
                    dp[i][j] = sum;
                }
            }

            // 乘以 n! * m!
            string result = dp[n][m];
            for (int i = 2; i <= n; i++) result = multiply(result, i);
            for (int i = 2; i <= m; i++) result = multiply(result, i);

            cout << "有效序列数(DP): " << dp[n][m] << endl;
            cout << "结果(含排列): " << result << endl;
        }
        cout << endl;
    }

    return 0;
}
