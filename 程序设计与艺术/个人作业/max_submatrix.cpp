#include <iostream>
#include <climits>
using namespace std;

const int N = 4;

int matrix[N][N] = {
    {0, -2, -7, 0},
    {9, 2, -6, 2},
    {-4, 1, -4, 1},
    {-1, 8, 0, -2}
};

// Kadane算法：一维最大子段和
int kadane(int arr[], int n)
{
    int maxSum = INT_MIN, curSum = 0;
    int start = 0, end = 0, tempStart = 0;

    for (int i = 0; i < n; i++)
    {
        curSum += arr[i];
        if (curSum > maxSum)
        {
            maxSum = curSum;
            start = tempStart;
            end = i;
        }
        if (curSum < 0)
        {
            curSum = 0;
            tempStart = i + 1;
        }
    }
    return maxSum;
}

// 最大子矩阵和
int maxSubMatrix()
{
    int maxSum = INT_MIN;
    int bestTop = 0, bestBottom = 0, bestLeft = 0, bestRight = 0;

    for (int top = 0; top < N; top++)
    {
        int temp[N] = {0};
        for (int bottom = top; bottom < N; bottom++)
        {
            // 将第bottom行累加到temp中
            for (int j = 0; j < N; j++)
                temp[j] += matrix[bottom][j];

            int cur = kadane(temp, N);
            if (cur > maxSum)
            {
                maxSum = cur;
                bestTop = top;
                bestBottom = bottom;
            }
        }
    }
    return maxSum;
}

int main()
{
    cout << "========== 最大子矩阵和 ==========" << endl;
    cout << "矩阵:" << endl;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << matrix[i][j] << "\t";
        cout << endl;
    }
    cout << "\n最大子矩阵和: " << maxSubMatrix() << endl;
    return 0;
}
