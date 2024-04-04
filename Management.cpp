#include "Management.h"

/******************************* Basic Service Metrics **************************/

/* T2.1 */
// Determine the maximum amount of water that can reach each or a specific city (to
// be selected via the Menu) and display it in a natural graphical format, such as by listing one pair
// (city, code, value) per line on the output as well as to a file.
void Management::maxAmountSpecificCity() {
    // todo
    // Criar uma instância da classe Management
    Management manager;

    // Chamar a função balanceNetworkLoad
    Metrics metrics = manager.balanceNetworkLoad();

    // Exibir as métricas retornadas
    std::cout << "Average Flow Difference: " << metrics.averageFlowDifference << std::endl;
    std::cout << "Variance Flow Difference: " << metrics.varianceFlowDifference << std::endl;
    std::cout << "Max Flow Difference: " << metrics.maxFlowDifference << std::endl;
}

/* T2.2 */
// Can an existing network configuration meet the water needs of its customer? In
// other words, can all the water reservoirs supply enough water to all its delivery sites?
void Management::verifyNetworkCapacity() {
    // todo
    printf("\nNot implemented yet\n");
}

/* T2.3 */
// Use the results from T2.1. and develop a simple algorithm or heuristic to balance
// the load across the network so that, as much as possible, you can minimize the differences of
// flow to capacity on each pipe across the entire network.
void Management::minimizeDifferencesFlowCapacity() {
    // todo
    printf("\nNot implemented yet\n");
}

/******************* Reliability and Sensitivity to Failures *******************/

/* T3.1 */
// You might be concerned about the network's resiliency. In this context, you should
// evaluate what happens in terms of the delivery capacity of the network if one specific water reservoir
// is out of commission. In other words, how much water can be delivered to the network's delivery
// sites if one specific water reservoir is out of commission?
void Management::reservoirRemoval() {
    // todo
    printf("\nNot implemented yet\n");
}

/* T3.2 */
// As periodic maintenance is required, some of the pumping stations often need to
// be temporarily removed from the network. Can any pumping station be temporarily taken out of service
// without affecting the delivery capacity to all the cities?  If not, which cities are most affected?
// For each examined pumping station, list the affected cities displaying their codes and water supply
// deficits.
void Management::pumpingStationRemoval() {
    // todo
    printf("\nNot implemented yet\n");
}

/* T3.3 */
// Sometimes, pipeline failures can occur. For each city, determine which pipelines, if
// ruptured, i.e., with a null flow capacity, would make it impossible to deliver the desired amount of
// water to a given city. For each examined pipeline, list the affected cities displaying their codes and
// water supply in deficit.
void Management::pipeRemoval() {
    // todo
    printf("\nNot implemented yet\n");
}

/************* Other functions (auxiliary and loading/parsing data) *************/

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

string normalizeCityName(string cityName) {
    // Definindo a localização como português para garantir que os caracteres acentuados sejam tratados corretamente
    setlocale(LC_ALL, "pt_PT.UTF-8");

    // Mapa para mapear caracteres acentuados para suas formas normalizadas
    unordered_map<string, string> accentMap = {
            {"á", "a"}, {"à", "a"}, {"ã", "a"}, {"â", "a"},
            {"é", "e"}, {"è", "e"}, {"ê", "e"},
            {"í", "i"}, {"ì", "i"},
            {"ó", "o"}, {"ò", "o"}, {"õ", "o"}, {"ô", "o"},
            {"ú", "u"}, {"ù", "u"},
            {"ç", "c"},
            {"Á", "A"}, {"À", "A"}, {"Ã", "A"}, {"Â", "A"},
            {"É", "E"}, {"È", "E"}, {"Ê", "E"},
            {"Í", "I"}, {"Ì", "I"},
            {"Ó", "O"}, {"Ò", "O"}, {"Õ", "O"}, {"Ô", "O"},
            {"Ú", "U"}, {"Ù", "U"},
            {"Ç", "C"}
    };
    string normalizedName;
    for (size_t i = 0; i < cityName.length(); ++i) {
        string currentChar = cityName.substr(i, 1);
        if (isalpha(cityName[i]) || cityName[i] == ' ' || cityName[i] == '-') {
            // Mantendo letras, espaços, hífens
            normalizedName += cityName[i];
        } else if (accentMap.find(currentChar) != accentMap.end()) {
            normalizedName += accentMap[currentChar];
        } else {
            // Se não houver correspondência no mapa, manter o caractere original
            normalizedName += currentChar;
        }
    }

    return normalizedName;
}

string Management::cityNameToCode(string& cityNamex){
    int cityId = -1;
    for (const auto& pair : city) {
        if (pair.second == cityNamex) {
            cityId = pair.first;
            break; // Sai do loop se o nome da cidade for encontrado
        }
    }

    string cityCode;
    for (const auto& pair1 : cities) {
        if (pair1.second == cityId) {
            cityCode = pair1.first;
            break;
        }
    }

    return cityCode;
}

Management::Management() {
    ifstream file;
    string city_1, id, code, demand_str, population_str, line;
    file.open(CITIES_FILE);
    getline(file, line); // skip header
    while (getline(file, city_1, ',')) {
        getline(file, id, ',');
        getline(file, code, ',');
        getline(file, demand_str, ',');
        getline(file, population_str, '\n');
        city_1 = normalizeCityName(city_1);
        string pop_result;
        pop_result = decapitalize(population_str);
        int demand_val, population_val;
        stringstream demand_stream(demand_str), population_stream(pop_result);
        demand_stream >> demand_val;
        population_stream >> population_val;
        cities[code] = stoi(id);
        city[stoi(id)] = city_1;
        demand[stoi(id)] = demand_val;
        population[stoi(id)] = population_val;
    }
    file.close();

    ifstream file1;
    string reservoir, municipality_1, id_1, code_1, maxdel_str, line1;
    file.open(RESERVOIRS_FILE);
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
        reserv[stoi(id_1)] = reservoir;
        municipality[stoi(id_1)] = municipality_1;
        maxdel[stoi(id_1)] = maxdel_val;
    }
    file1.close();

    ifstream file2;
    string id_2, code_2, line2; // Add a dummy variable to handle the empty fields
    file2.open(STATIONS_FILE);
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
    file3.open(PIPES_FILE);
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

void Management::maxFlow(string& targetCity) {
    string targetCityCode = cityNameToCode(targetCity);
    // Get the values
    Graph<string> g = createGraph();
    int max_flow = 0;
    for (auto it = reservoirs.begin(); it != reservoirs.end(); ++it) {
        if (g.maxFlow(it->first, targetCityCode) > max_flow) {
            max_flow = g.maxFlow(it->first, targetCityCode);
            cout << "Max-Flow between " << it->first << " and " << targetCityCode << " is: " << max_flow << endl;
        }
    }
    // Determine the maximum flow using Edmonds-Karp algorithm

    // Display the result
    if (max_flow == 0)
        cout << "No water can reach the city " << targetCity << ".";
    else
        cout << "Maximum amount of water that can reach the city " << targetCity << ": " << max_flow;
}

void Management::maxFlowEachCity() {
    Graph<string> g = createGraph();
    for (auto cityIt = cities.begin(); cityIt != cities.end(); ++cityIt) {
        int max_flow = 0;
        for (auto reservoirIt = reservoirs.begin(); reservoirIt != reservoirs.end(); ++reservoirIt) {
            int flow = g.maxFlow(reservoirIt->first, cityIt->first);
            if (flow > max_flow) {
                max_flow = flow;
            }
        }
        cout << "Max-Flow to " << city[cities[cityIt->first]] << " is: " << max_flow << endl;
    }
}

void Management::checkWaterSupply() {
    unordered_map<string, int> cityWaterSupply; // Para armazenar o suprimento de água para cada cidade

    // Inicialize cityWaterSupply com a demanda de cada cidade
    for (const auto& entry : demand) {
        if (city.count(entry.first) > 0) {
            cityWaterSupply[city[entry.first]] = 0;
        } else {
            cout << "City with demand not found: " << entry.first << endl;
        }
    }

    // Calcule o suprimento total de água para cada cidade
    Graph<string> g = createGraph();
    for (const auto& reservoir : reservoirs) {
        string reservoirCode = reservoir.first;
        int reservoirId = reservoir.second;
        string reservoirMunicipality = municipality[reservoirId];

        // Distribua a água do reservatório para as cidades conectadas
        Vertex<string>* reservoirVertex = g.findVertex(reservoirMunicipality);
        if (reservoirVertex != nullptr) {
            for (const auto& edge : reservoirVertex->getAdj()) {
                string cityCode = edge->getDest()->getInfo();
                if (cities.count(cityCode) > 0 && demand.count(cities[cityCode]) > 0) {
                    int cityId = cities[cityCode];
                    int waterDemand = demand[cityId];
                    double waterFlow = edge->getWeight();

                    // Verifique se o fluxo de água pode atender à demanda da cidade
                    if (waterFlow >= waterDemand) {
                        cityWaterSupply[city[cityId]] += waterDemand;
                    } else {
                        cityWaterSupply[city[cityId]] += waterFlow;
                    }
                } else {
                    cout << "City or demand not found for edge destination: " << cityCode << endl;
                }
            }
        }
        else {
            cout << "Reservoir vertex not found: " << reservoirMunicipality << endl;
        }
    }

    // Verifique se há déficit no suprimento de água para cada cidade
    cout << "Cities with water deficits:\n";
    for (const auto& entry : cityWaterSupply) {
        if (demand.count(cities[entry.first]) > 0) {
            int cityDemand = demand[cities[entry.first]];
            if (entry.second < cityDemand) {
                cout << "(" << entry.first << ", " << cityDemand - entry.second << ")\n";
            }
        } else {
            cout << "City demand not found: " << cities[entry.first] << endl;
        }
    }
}


void Management::checkGraph(const Graph<string> &g) {
    cout << "Cities with their respective demands:\n";
    for (const auto& entry : demand) {
        int cityId = entry.first;
        string cityName = city[cityId];
        int cityDemand = entry.second;
        cout << cityName << ": " << cityDemand << endl;
    }
}

void Management::printCityMap() {
    cout << "Cities:" << endl;
    for (const auto& entry : city) {
        int id = entry.first;
        string cidade = entry.second;
        cout << "Id: " << id << ", Name: " << cidade << endl;
    }
    cout << endl;
}

Metrics Management::balanceNetworkLoad() {
    // Criar o grafo
    Graph<string> g = createGraph();

    // Calcular as diferenças entre capacidade e fluxo em cada tubulação
    unordered_map<string, double> flowDifferences; // diferenças de fluxo em cada tubulação
    for (auto vertex : g.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            double capacity = edge->getWeight();
            double flow = edge->getFlow();
            double difference = capacity - flow;
            flowDifferences[vertex->getInfo() + "->" + edge->getDest()->getInfo()] = difference;
        }
    }

    // Identificar tubulações com maior desequilíbrio
    string maxDifferenceEdge;
    double maxDifference = 0.0;
    for (const auto& pair : flowDifferences) {
        if (pair.second > maxDifference) {
            maxDifference = pair.second;
            maxDifferenceEdge = pair.first;
        }
    }

    // Desenvolver um algoritmo de balanceamento simples
    for (auto vertex : g.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            double capacity = edge->getWeight();
            double flow = edge->getFlow();
            double difference = capacity - flow;
            double newFlow = flow + (difference * 0.1); // redistribuir 10% da diferença
            edge->setFlow(newFlow);
        }
    }

    // Recalcular métricas após o balanceamento
    double averageFlowDifference = calculateAverageFlowDifference(g);
    double varianceFlowDifference = calculateVarianceFlowDifference(g);
    double maxFlowDifference = calculateMaxFlowDifference(g);

    // Criar e retornar as métricas
    Metrics metrics;
    metrics.averageFlowDifference = averageFlowDifference;
    metrics.varianceFlowDifference = varianceFlowDifference;
    metrics.maxFlowDifference = maxFlowDifference;

    return metrics;
}

double Management::calculateAverageFlowDifference(const Graph<string>& g) {
    double totalDifference = 0.0;
    int count = 0;
    for (auto vertex : g.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            double capacity = edge->getWeight();
            double flow = edge->getFlow();
            double difference = capacity - flow;
            totalDifference += difference;
            count++;
        }
    }
    if (count == 0) {
        return 0.0; // Evitar divisão por zero
    }
    return totalDifference / count;
}

double Management::calculateVarianceFlowDifference(const Graph<string>& g) {
    double meanDifference = calculateAverageFlowDifference(g);
    double squaredDifferenceSum = 0.0;
    int count = 0;
    for (auto vertex : g.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            double capacity = edge->getWeight();
            double flow = edge->getFlow();
            double difference = capacity - flow;
            squaredDifferenceSum += (difference - meanDifference) * (difference - meanDifference);
            count++;
        }
    }
    if (count == 0) {
        return 0.0; // Evitar divisão por zero
    }
    return squaredDifferenceSum / count;
}

double Management::calculateMaxFlowDifference(const Graph<string>& g) {
    double maxDifference = 0.0;
    for (auto vertex : g.getVertexSet()) {
        for (auto edge : vertex->getAdj()) {
            double capacity = edge->getWeight();
            double flow = edge->getFlow();
            double difference = capacity - flow;
            if (difference > maxDifference) {
                maxDifference = difference;
            }
        }
    }
    return maxDifference;
}
