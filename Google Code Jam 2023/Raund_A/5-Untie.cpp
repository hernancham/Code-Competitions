#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        string s;
        cin >> s;
        int a = INT_MAX;
        int n = s.size();
        for (int j = 0; j < n; j++)
        {
            string t;
            for (int k = 0; k < n; k++)
                t += s[(j + k) % n];
            int c = 0;
            for (int k = 1; k < n; k++)
            {
                if (t[k] == t[k - 1])
                {
                    c++;
                    t[k] = ' ';
                }
            }
            if (t[0] == t[n - 1])
                c++;
            a = min(a, c);
        }
        cout << "Case #" << i << ": " << a << endl;
    }
    return 0;
}
