#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

int calculateRouteCost(const vector<vector<int>>& distances, const vector<int>& route);

void findBestRoute(const vector<vector<int>>& distances, vector<int>& route, int currentCity, int& bestCost, vector<int>& bestRoute);


