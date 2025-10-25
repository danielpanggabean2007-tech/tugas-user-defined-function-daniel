#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.1416;

double distanceTwoPoints(double x1, double y1, double x2, double y2) {
    double dx = x2 - x1;
    double dy = y2 - y1;
    return sqrt(dx*dx + dy*dy);
}

double radiusFromCenterAndPoint(double cx, double cy, double px, double py) {
    return distanceTwoPoints(cx, cy, px, py);
}

double circumference(double r) {
    return 2.0 * PI * r;
}

double area(double r) {
    return PI * r * r;
}

void printResults(double r) {
    double d = 2.0 * r;
    double c = circumference(r);
    double a = area(r);

    cout.setf(ios::fixed);
    cout.precision(4);

    cout << "\nHasil Perhitungan:\n";
    cout << "Radius        = " << r << '\n';
    cout << "Diameter      = " << d << '\n';
    cout << "Keliling      = " << c << '\n';
    cout << "Luas          = " << a << '\n';
}

bool readInput(double &cx, double &cy, double &px, double &py) {
    cout << "Masukkan pusat (cx cy): ";
    if (!(cin >> cx >> cy)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harus angka.\n";
        return false;
    }
    cout << "Masukkan titik pada lingkaran (px py): ";
    if (!(cin >> px >> py)) {
        cin.clear(); cin.ignore(1000, '\n');
        cout << "Input tidak valid! Harus angka.\n";
        return false;
    }
    return true;
}

int main() {
    cout << "=== Program Menghitung Lingkaran dari Dua Titik ===\n";
    cout << "(Input: pusat (cx, cy) dan titik pada lingkaran (px, py))\n\n";

    char ulang;
    do {
        double cx, cy, px, py;

        if (!readInput(cx, cy, px, py)) {
            cout << "Silakan coba lagi.\n\n";
            continue; 
        }

        double r = radiusFromCenterAndPoint(cx, cy, px, py);

        if (r == 0.0) {
            cout << "r = 0 (titik sama dengan pusat). Silakan input ulang.\n\n";
            continue; 
        }

        printResults(r);

        cout << "\nHitung lagi? (y/n): ";
        cin >> ulang;
        cout << '\n';
    } while (ulang == 'y' || ulang == 'Y');

    cout << "Selesai.\n";
    return 0;
}
