#include <iostream>
#include <cstdlib>
#include <ctime>
#include <iomanip>
using namespace std;

const int MAX_N = 100;
const int MAX_SIZE = 2 * MAX_N;

void printArray(const int a[], int n) {
    for (int i = 0; i < n; i++) cout << setw(4) << a[i];
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");
    int a[MAX_SIZE], n, k;

    cout << "Введите количество элементов массива (1-100): ";
    cin >> n;
    if (n < 1 || n > MAX_N) {
        cout << "Ошибка: недопустимый размер массива." << endl;
        return 1;
    }

    srand(static_cast<unsigned int>(time(nullptr)));
    for (int i = 0; i < n; i++) a[i] = rand() % 21 - 10;

    cout << "\nИсходный массив:" << endl;
    printArray(a, n);

    cout << "\nВведите номер удаляемого элемента K (нумерация с 1): ";
    cin >> k;
    if (k < 1 || k > n) {
        cout << "Ошибка: элемента с таким номером нет." << endl;
        return 1;
    }

    // Удаление элемента с номером K.
    for (int i = k - 1; i < n - 1; i++) a[i] = a[i + 1];
    n--;

    cout << "\nМассив после удаления:" << endl;
    printArray(a, n);

    // Вставка нуля после каждого четного элемента.
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            for (int j = n; j > i + 1; j--) a[j] = a[j - 1];
            a[i + 1] = 0;
            n++;
            i++; // Не обрабатываем вставленный ноль повторно.
        }
    }

    cout << "\nИтоговый массив:" << endl;
    printArray(a, n);
    return 0;
}
