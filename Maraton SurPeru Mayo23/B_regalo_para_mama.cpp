#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> precios(n);

    for (int i = 0; i < n; i++)
        cin >> precios[i];

    sort(precios.begin(), precios.end());

    int precio_promedio = (precios[0] + precios[n - 1]) / 2;

    int pos = 0;
    for (int i = 0; i < n; i++)
        if (abs(precios[i] - precio_promedio) < abs(precios[pos] - precio_promedio))
            pos = i;

    cout << precios[pos] << endl;
    return 0;
}