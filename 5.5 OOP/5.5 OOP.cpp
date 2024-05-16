//Реализовать задание, используя объявление и методы соответствующего
//  параметризированного класса vector из стандартной библиотеки шаблонов STL.
//Задана матрица(как вектор векторов).

#include <iostream>
#include <vector>
using namespace std;

// Функция для заполнения матрицы случайными числами
void inputMatrix(int size, vector<vector<int>>& matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = rand() % 100;
        }
    }
}

// Функция для вывода матрицы на экран
void printMatrix(int size, vector<vector<int>> matrix) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// Функция для нахождения нормы матрицы, определенной как максимальная сумма элементов столбца
void findNorm(int size, vector<vector<int>> matrix, int& max_sum) {
    int sum_rows = 0;
    for (int i = 0; i < size; i++) {
        sum_rows = 0;
        for (int j = 0; j < size; j++) {
            sum_rows += abs(matrix[j][i]);
        }
        if (sum_rows > max_sum)
            max_sum = sum_rows;
    }
}

int main()
{
    srand(time(NULL));
    int size; cin >> size;
    vector<vector<int>> matrix(size, vector<int>(size));
    inputMatrix(size, matrix); // Заполняем матрицу
    printMatrix(size, matrix); // Выводим матрицу на экран
    int max_sum = 0;
    findNorm(size, matrix, max_sum); // Находим норму матрицы
    cout << endl << max_sum; // Выводим норму матрицы на экран

}
