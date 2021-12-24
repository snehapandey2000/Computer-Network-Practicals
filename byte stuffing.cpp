#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Flag byte Sequence: f\n";
    cout << "Escape byte Sequence: e\n";
    char flag = 'f';
    char escape = 'e';
    string oM = "hel fejie ff del";
    cout << "Message to be sent : " << oM << endl;

    string sM = "f";
    for (int i = 0; i < oM.length(); i++)
    {
        if (oM[i] == flag)
        {
            sM += escape;
            sM += flag;
        }
        else if (oM[i] == escape)
        {
            sM += escape;
            sM += escape;
        }
        else
        {
            sM += oM[i];
        }
    }
    sM += flag;
    cout << "\nencoded message : " << sM << endl
         << endl;
    string rM = "";

    for (int i = 1; i <= (sM.length() - 2); i++)
    {

        if (sM[i] == escape)
        {
            if (sM[i + 1] == flag)
                continue;
            else
            {
                rM += escape;
                i++;
            }
        }
        else
        {
            rM += sM[i];
        }
    }
    cout << "decoded message is: " << rM << endl;
    return 0;
}
