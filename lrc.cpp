#include <bits/stdc++.h>
using namespace std;
int main()
{
    string str;
    cout << "Enter the string of bits\n";
    cin >> str;
    int n;
    cout << "Enter the number of columns\n";
    cin >> n;
    int ans[n] = {0};
    for (int i = 0; i < str.size(); i++)
    {
        ans[i % n] ^= (int(str[i]) - int('0'));
    }
    cout << "Output is\n";
    for (int i = 0; i < n; i++)
    {
        cout << ans[i];
    }
    return 0;
}
