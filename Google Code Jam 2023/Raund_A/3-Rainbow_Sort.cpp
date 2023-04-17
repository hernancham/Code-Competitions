#include "bits/stdc++.h"

using namespace std;

int main()
{
    int n = 1;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        map<int, int> m;
        for (int j = 0; j < n; j++)
        {
            cin >> a[j];
            if (!m.count(a[j]))
                m[a[j]] = j;
        }
        bool o = false;
        cout << "Case #" << i << ":";
        for (int j = 0; j < n; j++)
        {
            if (m[a[j]] != j && a[j - 1] != a[j])
            {
                cout << " IMPOSSIBLE" << endl;
                o = true;
            }
        }
        if (o)
        {
            a.erase(unique(a.begin(), a.end()), a.end());
            for (int e : a)
                cout << " " << e;
            cout << endl;
        }
    }
    return 0;
}