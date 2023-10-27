#include <bits/stdc++.h>
using namespace std;
float rnd(float var)
{
    float value = (int)(var * 100 + .5);
    return (float)value / 100;
}
void slv()
{
    cout << "Enter the three coefficients : ";
    int a, b, c;
    cin >> a >> b >> c;
    float discriminant = b * b - 4 * a * c;
    if (discriminant > 0)
    {
        discriminant = sqrt(discriminant);
        float root1 = (-1 * b + discriminant) / (2 * a);
        float root2 = (-1 * b - discriminant) / (2 * a);
        cout << "The two real roots of this equation are : ";
        cout << rnd(root1) << " and " << rnd(root2) << endl;
    }
    else if (discriminant == 0)
    {
        float root = -1 * b / (2 * a);
        cout << "The only real root of this equation is : " << rnd(root) << endl;
    }
    else
    {
        discriminant = sqrt(-1 * discriminant);
        float real = rnd(-1 * b / (2 * a));
        float imaginary = rnd(discriminant / (2 * a));
        cout << "The two imaginary roots of this equation are: " << real << (imaginary > 0 ? "+" : "") << imaginary << "i";
        cout << " and " << real << ((-1 * imaginary) > 0 ? "+" : "") << -1 * imaginary << "i"
             << endl;
    }
}
int32_t main()
{
    cout << "Enter the number of equations to solve : ";
    int t;
    cin >> t;
    while (t--)
    {
        slv();
    }
    return 0;
}