#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> fun(vector<int> &A)
{
    int len = A.size();
    int s=0,e=len-1;
    vector<int> ans(A.size());
    for(int i=0;i<len;i++)
    {
        if(A[i]%2==0)
        ans[s++]=A[i];
        else
        ans[e--]=A[i];

    }

    return ans;
}
int main()
{
    ifstream fin("LeetCode/Data/905.txt");
    int n;
    vector<int> in;
    cout<<"输入参数："<<endl;
    while (fin >> n)
    {
        in.push_back(n);
        cout<<n<<" ";
    }
    cout<<endl;

    fin.close();
    vector<int> out = fun(in);
    cout<<"输出结果："<<endl;
    for (int i = 0; i < out.size(); i++)
        cout << out[i] << " ";
    cout << endl;

    return 0;
}