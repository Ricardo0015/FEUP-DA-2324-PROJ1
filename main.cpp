#include "Management.h"

int main(){
    Management citiesManager;
    Graph<string> g = citiesManager.createGraph();
    citiesManager.checkGraph(g);
    return 0;
}

