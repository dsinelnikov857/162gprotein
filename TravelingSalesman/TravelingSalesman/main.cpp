#include <iostream>
#include "task.h"
using namespace std;


int main() {
    setlocale(LC_ALL, "RUSSIAN");
    // Пример матрицы расстояний
    vector<vector<int>> distances = {
      {0, 10, 15, 20},
      {10, 0, 35, 25},
      {15, 35, 0, 30},
      {20, 25, 30, 0}
    };

    vector<int> route;
    route.push_back(0); // Начинаем с города 0
    int bestCost = numeric_limits<int>::max();
    vector<int> bestRoute;

    findBestRoute(distances, route, 0, bestCost, bestRoute);

    cout << "Оптимальный маршрут: ";
    for (int city : bestRoute) {
        cout << city << " ";
    }
    cout << endl;
    cout << "Общая стоимость маршрута: " << bestCost << endl;

    return 0;
}