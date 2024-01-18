#include <iostream>
#include <iomanip>

using namespace std;

double CoordX[10002];
double CoordY[10002];

double adj = 100000;

double Area(int idx)
{
    double x1 = adj + CoordX[idx];
    double y1 = CoordY[idx];
    double x2 = adj + CoordX[idx+1];
    double y2 = CoordY[idx+1];

    return ((x1 + x2) * (y1 - y2) / 2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int N;
    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> CoordX[i] >> CoordY[i];
    }
    CoordX[N] = CoordX[0];
    CoordY[N] = CoordY[0];

    double area = 0.0f;

    for(int i = 0; i < N; i++)
    {
        area += Area(i);
    }

    cout << fixed;
    cout << setprecision(1) << abs(area);

    return 0;
}
