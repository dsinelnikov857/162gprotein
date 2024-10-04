#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// Функция для вычисления стоимости маршрута
int calculateRouteCost(const vector<vector<int>>& distances, const vector<int>& route) {
    int cost = 0;
    for (int i = 0; i < route.size() - 1; i++) {
        cost += distances[route[i]][route[i + 1]];
    }
    cost += distances[route.back()][route[0]]; // Возвращение в начальный город
    return cost;
}

// Рекурсивная функция для перебора всех возможных маршрутов
void findBestRoute(const vector<vector<int>>& distances, vector<int>& route, int currentCity, int& bestCost, vector<int>& bestRoute) {
    if (route.size() == distances.size()) { // Если все города посещены
        int currentCost = calculateRouteCost(distances, route);
        if (currentCost < bestCost) {
            bestCost = currentCost;
            bestRoute = route;
        }
        return;
    }

    for (int nextCity = 0; nextCity < distances.size(); nextCity++) {
        if (find(route.begin(), route.end(), nextCity) == route.end()) { // Если город ещё не посещён
            route.push_back(nextCity);
            findBestRoute(distances, route, nextCity, bestCost, bestRoute);
            route.pop_back(); // Отменяем выбор города
        }
    }
}