#include <iostream>

using namespace std;

bool posibilidad;

void buscar_camino(char **matriz, int n, int m, int x, int y)
{
    if (x < 0 || x >= n || y < 0 || y >= m)
        return;
    if (matriz[x][y] == '#')
        return;
    if (matriz[x][y] == 'j')
    {
        posibilidad = true;
        return;
    }
    matriz[x][y] = '#';
    buscar_camino(matriz, n, m, x + 1, y);
    buscar_camino(matriz, n, m, x - 1, y);
    buscar_camino(matriz, n, m, x, y + 1);
    buscar_camino(matriz, n, m, x, y - 1);
}

int main()
{
    /*'.' indica una área libre.
    '#' indica un bloqueo.
    'r' indica la posición en que se ubica Romeo.
    'j' indica la posición en que se ubica Julieta.*/

    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        // generar una matriz de n x m
        char **matriz = new char *[n];
        for (int i = 0; i < n; i++)
            matriz[i] = new char[m];

        int pos_x, pos_y;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> matriz[i][j];
                if (matriz[i][j] == 'r')
                {
                    pos_x = i;
                    pos_y = j;
                }
            }
        }

        // buscar camino existente entre Romeo y Julieta
        posibilidad = false;
        buscar_camino(matriz, n, m, pos_x, pos_y);
        if (posibilidad)
            cout << "Existe camino" << endl;
        else
            cout << "No existe camino" << endl;

        // liberar memoria de toda la matriz
        for (int i = 0; i < n; i++)
            delete[] matriz[i];
        delete[] matriz;
    }

    return 0;
}