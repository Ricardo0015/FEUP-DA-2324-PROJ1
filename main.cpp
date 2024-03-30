#include "Graph.h"

#include "T1/App.h"
#include "T1/App.cpp"

int main(){

    // Load dataset (graph)
    Graph<std::string> graph = App::loadDataSet();

    // start the app UI
    App::startUI(graph);

    return 0;
}