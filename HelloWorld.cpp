#include <iostream>
using namespace std;
int main()
{
    cout << "Hello World" << endl;
    unsigned int l = 1;
    int ll = -1;
    if(l>ll)
    cout<<"true"<<endl;
    else
    {
        cout<<"false"<<endl;
    }
    string s = "1A3";
    for(char c : s)
    {
        if(isupper(c))
        cout<<c<<" ";
    }
    cout<<endl;

    return 0;
}