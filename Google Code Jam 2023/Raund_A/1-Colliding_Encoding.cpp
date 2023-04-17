#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    set<string> s;
    for (int i = 1; i <= n; i++)
    {
        char a[26];
        for (int j = 0; j < 26; j++)
            cin >> a[j];
        int m;
        cin >> m;
        for (int j = 0; j < m; j++)
        {
            string t;
            cin >> t;
            string k = "";
            for (auto c : t)
                k += a[c - 'A'];
            s.insert(k);
        }
        cout << "Case #" << i << ": " << (s.size() == m ? "NO" : "YES") << endl;
        s.clear();
    }
    return 0;
}
