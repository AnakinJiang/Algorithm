#include <iostream>
using namespace std;
const int maxn = 100;
struct Matrix //结构体，矩阵类型
{
    int m[maxn][maxn];
} ans, res;

/**计算矩阵乘法的函数，参数是矩阵a
 * 矩阵b和一个n，代表这两个矩阵是几阶方阵
 * **/

Matrix Mul(Matrix A, Matrix B, int n)
{
    Matrix tmp; //定义一个临时的矩阵，存放A×B的结果
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            tmp.m[i][j] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            for (int k = 1; k <= n; k++)
                tmp.m[i][j] = (tmp.m[i][j]+A.m[i][k] * B.m[k][j]%10000)%10000;
            
        }

    return tmp;
}

// 整数快速幂
int QuickPow(int x, int N)
{
    int res = x;
    int ans = 1;
    while (N)
    {
        if (N & 1)
        {
            ans = ans * res;
        }
        res = res * res;
        N = N >> 1;
    }
    return ans;
}

// 矩阵快速幂
// N表示幂次，n表示方阵的维度

void QuickPower(int N, int n)
{
    // 相对于整数初始化为1.矩阵初始化为单位矩阵
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
                ans.m[i][j] = 1;
            else
                ans.m[i][j] = 0;
        }
    while (N)
    {
        if (N & 1)
        {
            ans = Mul(ans, res, n);
            // cout << ans.m[1][1] << endl;
        }
        res = Mul(res, res, n);
        N = N >> 1;
    }
}

int main()
{
    // int N = 15, n = 2;
    res.m[1][1] = 1;
    res.m[1][2] = 1;
    res.m[2][1] = 1;
    res.m[2][2] = 0;
    // // QuickPower(3, 2);

    // // cout << ans.m[1][1] + ans.m[1][2];
    // for (int i = 3; i <= N; i++)
    // {
    //     res.m[1][1] = 1;
    //     res.m[1][2] = 1;
    //     res.m[2][1] = 1;
    //     res.m[2][2] = 0;
    //     int ans1=1,ans2=1;
    //     QuickPower(i, n);
    //     ans1 = ans.m[1][1]+ans.m[1][2];
    //     cout<<ans1<<endl;
    // }
    int N;
    while (cin >> N)
    {
        if (N == -1)
            break;
        res.m[1][1] = 1;
        res.m[1][2] = 1;
        res.m[2][1] = 1;
        res.m[2][2] = 0;
        if(N==0)
        cout<<0<<endl;
        else if (N == 1)
            cout << 1 << endl;
        else if (N == 2)
            cout << 1 << endl;
        else
        {
            QuickPower(N - 2, 2);
            cout << (ans.m[1][1] + ans.m[1][2])%10000 << endl;
        }
    }

    return 0;
}