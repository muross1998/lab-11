#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

double f(double x) {
    int i = 8;
    double num = -i + x;
    double den = 2.5 * i + 1.0 / (i + x);
    double part1 = num / den;
    double part2 = pow(tanh(x), i + 1);
    return part1 + part2;
}

int main() {
    double x = -1.0;
    double h = 0.1;

    ofstream fout("data.txt");
    if (!fout) return 1;

    while (x <= 1.0 + 1e-9) {
        fout << x << " " << f(x) << "\n";
        x += h;
    }
    fout.close();

    ifstream fin("data.txt");
    if (!fin) return 1;

    double x_read, f_read;
    while (fin >> x_read >> f_read) {
        if (fabs(x_read) < 1e-9) {
            cout << "f(0) = " << f_read << endl;
            break;
        }
    }
    fin.close();
    return 0;
}
