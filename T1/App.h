#include "../Graph.h"
#include <iostream>
using namespace std;

class App {
public:
    static Graph<string> loadDataSet();
    static void startUI(Graph<string> graph);
};