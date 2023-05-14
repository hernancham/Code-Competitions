#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

double dist(double b1, double a1, double b2, double a2)
{
    /*
        a y b son angulos en radianes dentro de una esfera unitaria
        0 <= a <= pi  , a se encuentra en el plano
        0 <= b <= 2pi
        por lo que a,b representa una coordenada en el espacio tridimensional x,y,z
        quiero encontrar la distancia entre dos puntos en el espacio tridimensional
    */
    double x1 = sin(b1) * sin(a1);
    double y1 = cos(b1) * sin(a1);
    double z1 = cos(a1);

    double x2 = sin(b2) * sin(a2);
    double y2 = cos(b2) * sin(a2);
    double z2 = cos(a2);

    double d = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return d;
}

double minima_dist(double *a, double *b, int n)
{
    double aux = 3;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && dist(a[i], b[i], a[j], b[j]) < aux)
                aux = dist(a[i], b[i], a[j], b[j]);
    return aux;
}

int main()
{
    int n;
    cin >> n;
    double *ang_a = new double[n];
    double *ang_b = new double[n];

    for (int i = 0; i < n; i++)
        cin >> ang_a[i] >> ang_b[i];

    cout << minima_dist(ang_a, ang_b, n) << endl;

    return 0;
}