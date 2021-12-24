#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> addr(4, 0);

    cout << "Enter the IP address (Use space to separate the 4 bytes) : \n";

    for (int i = 0; i < 4; i++)
    {
        cin >> addr[i];
    }

    int numSubs;
    cout << "\nEnter the number of subnets : ";
    cin >> numSubs;

    int numRem = 256 - addr[3];
    int inc = numRem / numSubs;

    vector<int> last(numSubs, addr[3]);

    for (int i = 0; i < numSubs; i++)
        last[i] += i * inc;

    cout << "\nAll the Subnets are : \n";

    for (int i = 0; i < numSubs; i++)
    {
        cout << "\nSubnet " << i + 1 << " : "
             << " ranges from " << addr[0] << "." << addr[1] << "." << addr[2] << "." << last[i] << " to " << addr[0] << "." << addr[1] << "." << addr[2] << ".";
        if (i == numSubs - 1)
            cout << 255;
        else
            cout << last[i + 1] - 1;

        cout << " with Subnet mask of " << 255 << "." << 255 << "." << 255 << "." << last[i];
    }

    return 0;
}
