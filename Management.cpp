#include "Management.h"

string decapitalize(const string& str) {
    string result;
    for (char c : str) {
        if (c != ',' && c != '"') {
            result += c;
        }
        else{
            continue;
        }
    }
    return result;
}

Management::Management() {
    ifstream file;
    string city_1, id, code, demand_str, population_str, line;
    file.open("Cities_Madeira.csv");
    getline(file, line); // skip header
    while (getline(file, city_1, ',')) {
        getline(file, id, ',');
        getline(file, code, ',');
        getline(file, demand_str, ',');
        getline(file, population_str, '\n');

        string pop_result;
        pop_result = decapitalize(population_str);
        int demand_val, population_val;
        stringstream demand_stream(demand_str), population_stream(pop_result);
        demand_stream >> demand_val;
        population_stream >> population_val;
        cities[code] = stoi(id);
        city[stoi(id)].insert(city_1);
        demand[stoi(id)].insert(demand_val);
        population[stoi(id)].insert(population_val);
    }
    file.close();

    ifstream file1;
    string reservoir, municipality_1, id_1, code_1, maxdel_str, line1;
    file.open("Reservoirs_Madeira.csv");
    getline(file, line1); // skip header
    while (getline(file, reservoir, ',')) {
        getline(file, municipality_1, ',');
        getline(file, id_1, ',');
        getline(file, code_1, ',');
        getline(file, maxdel_str, '\n');
        string maxdel_result;
        int maxdel_val;
        maxdel_result = decapitalize(maxdel_str);
        stringstream maxdel_stream(maxdel_result);
        maxdel_stream >> maxdel_val;
        reservoirs[code_1] = stoi(id_1);
        reserv[stoi(id_1)].insert(reservoir);
        municipality[stoi(id_1)].insert(municipality_1);
        maxdel[stoi(id_1)].insert(maxdel_val);
    }
    file1.close();

    ifstream file2;
    string id_2, code_2, line2; // Add a dummy variable to handle the empty fields
    file2.open("Stations_Madeira.csv");
    getline(file2, line2); // skip header
    while (getline(file2, line2)) {
        stringstream ss(line2);
        if (getline(ss, id_2, ',') && getline(ss, code_2, ',')) {
            if (!id_2.empty() && !code_2.empty()) {
                string code_result;
                code_result = decapitalize(code_2);
                stations[code_result] = stoi(id_2);
            }
        }
    }
    file.close();
}

Graph<string> Management::createGraph(){
    Graph<string> g;
    int n = 0;
    Vertex<std::string>* sourceVertex;
    Vertex<std::string>* destVertex;
    ifstream file3;
    string a, b, capacity, direction, line3;
    file3.open("Pipes_Madeira.csv");
    getline(file3, line3);
    while(!file3.eof()) {
        getline(file3, a, ',');
        getline(file3, b, ',');
        getline(file3, capacity, ',');
        getline(file3, direction, '\n');
        double capacity_val;
        stringstream capacity_stream(capacity);
        capacity_stream >> capacity_val;
        if (cities.find(a) != cities.end() || stations.find(a) != stations.end() || reservoirs.find(a) != reservoirs.end()) {
            g.addVertex(a);
        } else {
            cerr << "Invalid vertex: " << a << endl;
        }

        if (cities.find(b) != cities.end() || stations.find(b) != stations.end() || reservoirs.find(b) != reservoirs.end()) {
            g.addVertex(b);
        } else {
            cerr << "Invalid vertex: " << b << endl;
        }

        // Add bidirectional edge between the vertices
        g.addBidirectionalEdge(a, b, capacity_val, direction);

    }
    file3.close();
    return g;
}

void Management::checkGraph(const Graph<string> &g) {
    cout << "Vertices:" << endl;
    for (const auto &v : g.getVertexSet()) {
        cout << "Vertex: " << v->getInfo() << endl;
        cout << "Outgoing Edges:" << endl;
        for (const auto &edge : v->getAdj()) {
            cout << v->getInfo() << " -> " << edge->getDest()->getInfo() << " (Weight: " << edge->getWeight() << ")" << endl;
        }
        cout << endl;
    }
}
