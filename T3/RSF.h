#include "Graph.h"
#include <iostream>
using namespace std;

class RSF {
    public:
        static void reservoirRemoval(Graph<string>* graph);
        static void pumpingStationRemoval(Graph<string>* graph);
        static void pipeRemoval(Graph<string>* graph);
};
