#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

const int N = 26;

void fillArrayRec(int a[], int i, int n, int low, int high);
void printArrayRec(const int a[], int i, int n);

bool criterion(int value, int index);

int countRec(const int a[], int i, int n);
int sumRec(const int a[], int i, int n);
void replaceRec(int a[], int i, int n);

int main() {
    srand(time(NULL));

    int a[N];

    fillArrayRec(a, 0, N, -40, 20);

    cout << "Pochatkovyi masyv:\n";
    printArrayRec(a, 0, N);

    int k = countRec(a, 0, N);
    int s = sumRec(a, 0, N);
    replaceRec(a, 0, N);

    cout << "\nKilkist: " << k << endl;
    cout << "Suma: " << s << endl;

    cout << "Zminenyi masyv:\n";
    printArrayRec(a, 0, N);

    return 0;
}


bool criterion(int value, int index) {
    return (value <= 0 && index % 2 == 0);
}

void fillArrayRec(int a[], int i, int n, int low, int high) {
    if (i == n) return;
    a[i] = low + rand() % (high - low + 1);
    fillArrayRec(a, i + 1, n, low, high);
}

void printArrayRec(const int a[], int i, int n) {
    if (i == n) {
        cout << endl;
        return;
    }
    cout << setw(4) << a[i];
    printArrayRec(a, i + 1, n);
}

int countRec(const int a[], int i, int n) {
    if (i == n) return 0;
    return (criterion(a[i], i) ? 1 : 0) + countRec(a, i + 1, n);
}

int sumRec(const int a[], int i, int n) {
    if (i == n) return 0;
    return (criterion(a[i], i) ? a[i] : 0) + sumRec(a, i + 1, n);
}

void replaceRec(int a[], int i, int n) {
    if (i == n) return;
    if (criterion(a[i], i)) a[i] = 0;
    replaceRec(a, i + 1, n);
}
