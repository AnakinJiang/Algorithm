#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> sortedSquares(vector<int> &A)
{
    int start = 0, leng = A.size(), end = A.size() - 1;
    vector<int> ans(leng);
    if (A[start] >= 0)
    {
        for (int i = 0; i < leng; i++)
            ans[i] = A[i] * A[i];
    }
    else if (A[end] <= 0)
    {
        for (int i = leng - 1; i >= 0; i--)
            ans[leng - 1- i]= A[i] * A[i];
    }
    else
    {
        int p = leng-1;

        while (start <= end)
        {

            if (A[start] >= 0)
            {
                while (start <= end)
                {
                    ans[p--]=A[end] * A[end];
                    end--;
                }
                break;
            }
            else if (A[end] <= 0)
            {
                while (start <= end)
                {
                    ans[p--]= A[start] * A[start];
                    start++;
                }
                break;
            }
            else
            {
                if (-A[start] >= A[end])
                {
                    ans[p--]= A[start] * A[start];
                    start++;
                }
                else
                {
                    ans[p--]=A[end] * A[end];
                    end--;
                }
            }
        }
    }
    return ans;
}
int main()
{
    vector<int> in;
    int n;
    ifstream file;
    string filename = "LeetCode/Data/977.txt";
    file.open(filename);
    while (file >> n)
    {
        in.push_back(int(n));
    }
    vector<int> out = sortedSquares(in);
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";

    return 0;
}