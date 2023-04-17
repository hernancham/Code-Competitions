#include <bits/stdc++.h>

using namespace std;

int main()
{
    int64_t n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int m, l = 0;
        cin >> m;
        while (m > ++l * 26)
            m -= l * 26;
        cout << "Case #" << i + 1 << ": " << char((--m / l) + 'A') << endl;
    }
    return 0;
}
