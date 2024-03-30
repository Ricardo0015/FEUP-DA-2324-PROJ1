#include "Graph.h"
#include <iostream>
using namespace std;

class App {

public:
    static Graph<std::string> loadDataSet();
    static void startUI(Graph<std::string> graph);
};