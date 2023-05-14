#include <iostream>

using namespace std;

int descartes(int *cinta, int n, int m)
{
    int descartes = 0;

    for (int i = n; i < m; i++)
    {
        for (int j = n; j < m; j++)
        {
            if (cinta[j] % cinta[i] != 0)
            {
                descartes++;
                break;
            }
        }
    }
    return descartes;
}

int main()
{
    int n;
    cin >> n;
    int *cinta = new int[n];

    for (int i = 0; i < n; i++)
        cin >> cinta[i];

    int c, inf, sup;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        cin >> inf >> sup;
        cout << descartes(cinta, inf - 1, sup) << endl;
    }

    return 0;
}
