#include <bits/stdc++.h>
using namespace std;

bool Palindrome(const string &s)
{
    unordered_map<char, int> charCount;
    int oddCount = 0;

    for (char c : s)
    {
        charCount[c]++;
    }

    for (auto it : charCount)
    {
        if (it.second % 2 != 0)
        {
            oddCount++;
        }
        //cout<<it.first<<" "<<it.second<<endl;
    }

    if(oddCount <=1 )
          return 1;
    
    else return 0;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (Palindrome(s))
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}
