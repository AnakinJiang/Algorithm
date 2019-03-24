#include <iostream>
#include <fstream>
#include <vector>
using namespace std;
vector<int> fun(vector<int> &A)
{
    vector<int> ans;

    return ans;
}
int main()
{
    ifstream fin("LeetCode/Data/.txt");
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