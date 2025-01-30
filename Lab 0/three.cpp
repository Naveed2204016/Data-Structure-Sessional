#include<bits/stdc++.h>
#include<string>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int hsh[256]={0};
    for(char ch:s)
    {
        hsh[ch]++;
    }

    string c;
    for(char x:s)
    {
        if(hsh[x]==1)
        {
            cout<<x;
        }
        else if(hsh[x]>1)
        {
            cout<<x;
            hsh[x]=-1;
        }
    }
    cout<<endl;
}


/*#include <iostream>
#include <string>
using namespace std;

int main() {
    string input;
    cout << "Enter a string: ";
    cin >> input;

    int freq[256] = {0}; 

    for (char ch : input) {
        freq[ch]++;
    }

    cout << "Unique characters in the string are: ";
    for (char ch : input) {
        if (freq[ch] == 1) {
            cout << ch << " ";
        }
    }

    cout << endl;

    return 0;
}
*/