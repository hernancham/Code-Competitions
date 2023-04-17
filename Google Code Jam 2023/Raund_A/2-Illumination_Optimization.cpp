#include "bits/stdc++.h"

using namespace std;

int main()
{
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++)
    {
        int m, r, n;
        cin >> m >> r >> n;
        int x[n + 1];
        for (int j = 1; j <= n; j++)
            cin >> x[j];
        int f = 0, a = 0;
        for (int j = 1; j <= n; j++)
        {
            if (x[j] - r > f)
            {
                a = -1;
                break;
            }
            int k = j;
            while (k + 1 <= n && x[k + 1] - r <= f)
            {
                k++;
            }
            a++;
            f = x[k] + r;
            j = k;
            if (f >= m)
                break;
        }
        if (f < m)
            a = -1;
        cout << "Case #" << i << ": " << (a >= 0 ? to_string(a) : "IMPOSSIBLE") << endl;
    }
    return 0;
}
