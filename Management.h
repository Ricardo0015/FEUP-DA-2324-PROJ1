//
// Created by ricardo on 06-03-2024.
//

#ifndef PROJECT1DATASETSMALL_MANAGEMENT_H
#define PROJECT1DATASETSMALL_MANAGEMENT_H

#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <iostream>
#include <sstream>
#include <fstream>
#include <list>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include "Graph.h"

using namespace std;
class Management {
    unordered_map<string, int> cities;
    unordered_map<string, int> stations;
    unordered_map<string, int> reservoirs;
    unordered_map<int, unordered_set<string>> municipality;
    unordered_map<int, unordered_set<int>> maxdel;
    unordered_map<int, unordered_set<string>> reserv;
    unordered_map<int, unordered_set<string>> city;
    unordered_map<int, unordered_set<int>> demand;
    unordered_map<int, unordered_set<int>> population;
public:
    Management();
    void checkGraph(const Graph<string> &g);
    Graph<string> createGraph();

};
#endif //PROJECT1DATASETSMALL_MANAGEMENT_H
