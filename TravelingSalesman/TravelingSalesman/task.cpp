#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

// ������� ��� ���������� ��������� ��������
int calculateRouteCost(const vector<vector<int>>& distances, const vector<int>& route) {
    int cost = 0;
    for (int i = 0; i < route.size() - 1; i++) {
        cost += distances[route[i]][route[i + 1]];
    }
    cost += distances[route.back()][route[0]]; // ����������� � ��������� �����
    return cost;
}

// ����������� ������� ��� �������� ���� ��������� ���������
void findBestRoute(const vector<vector<int>>& distances, vector<int>& route, int currentCity, int& bestCost, vector<int>& bestRoute) {
    if (route.size() == distances.size()) { // ���� ��� ������ ��������
        int currentCost = calculateRouteCost(distances, route);
        if (currentCost < bestCost) {
            bestCost = currentCost;
            bestRoute = route;
        }
        return;
    }

    for (int nextCity = 0; nextCity < distances.size(); nextCity++) {
        if (find(route.begin(), route.end(), nextCity) == route.end()) { // ���� ����� ��� �� �������
            route.push_back(nextCity);
            findBestRoute(distances, route, nextCity, bestCost, bestRoute);
            route.pop_back(); // �������� ����� ������
        }
    }
}