#include <iostream>
#include <vector>

using namespace std;

int menor_inmediato(int *array, int n, int pos_actual, int valor)
{
    int pos = pos_actual;
    if (array[n - 1] >= valor)
        return n;
    for (int i = pos_actual; i < n; i++)
        if (array[i] <= valor)
            pos = i;
    return pos;
}

int main()
{
    int n;
    while (cin >> n && n != 0)
    {
        int pos = 0;
        int *piedras = new int[n];
        vector<int> saltos;

        for (int i = 0; i < n; i++)
            cin >> piedras[i];

        while (pos < n)
        {
            int pos_menor = menor_inmediato(piedras, n, pos, 2 * piedras[pos]);
            if (pos_menor == pos)
            {
                cout << "Imposible para Pepito" << endl;
                break;
            }
            else
            {
                saltos.push_back(piedras[pos_menor]);
                pos = pos_menor;
            }
        }

        if (pos == n)
            for (auto elem : saltos)
                cout << elem << " ";

        delete[] piedras;
        saltos.clear();
    }
    return 0;
}