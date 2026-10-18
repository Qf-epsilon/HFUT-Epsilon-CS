#include <iostream>
using namespace std;

const int N = 8;
int queen[N];
int count = 0;

// 判断第row行第col列是否安全
bool isSafe(int row, int col)
{
    for (int i = 0; i < row; i++)
    {
        if (queen[i] == col || queen[i] - i == col - row || queen[i] + i == col + row)
            return false;
    }
    return true;
}

// 打印棋盘
void printBoard()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << (queen[i] == j ? "Q " : ". ");
        cout << endl;
    }
    cout << endl;
}

// DFS回溯求解
void solve(int row)
{
    if (row == N)
    {
        count++;
        cout << "解法 " << count << ":" << endl;
        printBoard();
        return;
    }
    for (int col = 0; col < N; col++)
    {
        if (isSafe(row, col))
        {
            queen[row] = col;
            solve(row + 1);
        }
    }
}

int main()
{
    cout << "========== 八皇后问题 ==========" << endl;
    cout << "共92种解法，棋盘用Q表示皇后，.表示空格" << endl << endl;
    solve(0);
    cout << "共有 " << count << " 种解法。" << endl;
    return 0;
}
