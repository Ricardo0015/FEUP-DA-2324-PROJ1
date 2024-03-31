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
#include <locale>
#include "Graph.h"

using namespace std;
struct Metrics {
    double averageFlowDifference;
    double varianceFlowDifference;
    double maxFlowDifference;
};
class Management {
    unordered_map<string, int> cities;
    unordered_map<string, int> stations;
    unordered_map<string, int> reservoirs;
    unordered_map<int, string> municipality;
    unordered_map<int, int> maxdel;
    unordered_map<int, string> reserv;
    unordered_map<int, string> city;
    unordered_map<int, int> demand;
    unordered_map<int, int> population;
public:
    Management();
    Graph<string> createGraph();
    void maxFlow(string& targetCity);
    void checkGraph(const Graph<string> &g);
    string cityNameToCode(string& cityName);
    void printCityMap();
    void checkWaterSupply();
    void maxFlowEachCity();
    Metrics balanceNetworkLoad();
    double calculateVarianceFlowDifference(const Graph<string>& g);
    double calculateMaxFlowDifference(const Graph<string>& g);
    double calculateAverageFlowDifference(const Graph<string>& g);
    Metrics test();
};
#endif //PROJECT1DATASETSMALL_MANAGEMENT_H
