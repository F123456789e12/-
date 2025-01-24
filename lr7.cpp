#include <iostream>
#include <vector>
#include <numeric> // Для std::accumulate
#include <iomanip> // Для std::setprecision и std::fixed

using namespace std;

int main() {
    int n, m;

    cout << "Введите количество строк (n): ";
    cin >> n;
    cout << "Введите количество столбцов (m): ";
    cin >> m;

    if (n <= 0 || m <= 0) {
        cout << "Размеры массива должны быть положительными." << endl;
        return 1; // Ошибка, если размеры неверны
    }

    vector<vector<int>> matrix(n, vector<int>(m));

    cout << "Введите элементы массива:" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << "B[" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }

    cout << "\nСреднее арифметическое элементов в каждой строке:" << endl;
    for (int i = 0; i < n; ++i) {
       double average = 0.0;
        if(m > 0)
           average =  accumulate(matrix[i].begin(), matrix[i].end(), 0.0) / m;
         cout << "Среднее в строке " << i << ": " << fixed << setprecision(2) << average << endl;
    }

    return 0;
}
