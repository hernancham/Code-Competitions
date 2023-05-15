#include <iostream>
#include <vector>

using namespace std;

int menor_inmediato(int *array, int n, int pos_actual, int valor)
{
    int pos = pos_actual;
    if (valor > array[n - 1])
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
        int *piedras = new int[n];
        vector<int> saltos;

        for (int i = 0; i < n; i++)
            cin >> piedras[i];

        int pos_act = 0, pos_sig;

        while (pos_act < n)
        {
            pos_sig = menor_inmediato(piedras, n, pos_act, 2 * piedras[pos_act]);
            if (pos_sig == pos_act)
                break;
            saltos.push_back(piedras[pos_act]);
            pos_act = pos_sig;
        }

        if (pos_act < n)
            cout << "Imposible para Pepito" << endl;
        else
            for (auto elem : saltos)
                cout << elem << " ";

        delete[] piedras;
        saltos.clear();
    }
    return 0;
}