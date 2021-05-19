#include <iostream>
#include <cmath>
using namespace std;
double fun(double _x)//Что бы поменять исодную функцию, написать её здесь
{
    return _x * _x + 5 * cos(_x);
}
int main()
{
    double d;
    double dc;
    double A = -1, B = 4;
    int k, n = 5, m;
    int i;
    int j;
    //Варинат 12 А = -1 В = 4 n = 5
    cout << "A = ";
    cin >> A;
    cout << "B = ";
    cin >> B;
    cout << "n = ";
    cin >> n;
    double y = new double[n];
    double** a = new double[n];
    for (i = 0; i < n; i++)
    {
        a[i] = new double[n];
    }
    double* c = new double[n];
    double* x = new double[n];
    dc = (B - A) / (n - 1);
    for (int i = 0; i < n; i++)
    {
        x[i] = A + dc * i;
        y[i] = fun(x[i]);
        // cout << x[i] << " " << y[i]  << endl;
    }


    for (k = 0; k < n; k++) {
        a[k][0] = 1;
        i = -1;
        for (m = 1; m < n; m++) {
            i = i + 1;
            if (i == k) {
                i = i + 1;
            }
            d = x[k] - x[i];
            a[k][m] = a[k][m - 1] / d;
            for (j = (m - 1); j > 0; j--) {
                a[k][j] = (a[k][j - 1] - a[k][j] * x[i]) / d;
            }
            a[k][0] = -a[k][0] * x[i] / d;
        }

    }
    for (i = 0; i < n; i++) {
        c[i] = 0;
        for (k = 0; k < n; k++) {
            c[i] = c[i] + a[k][i] * y[k];
        }
    }
    cout << " y = ";

    for (i = 0; i < n; i++)
    {
        cout << "+ " << c[i];
        for (int j = 0; j < i; j++)
        {
            cout << " * x ";
        }

    }
    /* for (i = 0; i < n; i++)
     {
         cout << x[i] << " " << y[i] << " " << c[i] << endl;
     }*/

    return 0;
}