#include "Management.h"

int main() {
    // Criar uma instância da classe Management
    Management manager;

    // Chamar a função balanceNetworkLoad
    Metrics metrics = manager.balanceNetworkLoad();

    // Exibir as métricas retornadas
    std::cout << "Average Flow Difference: " << metrics.averageFlowDifference << std::endl;
    std::cout << "Variance Flow Difference: " << metrics.varianceFlowDifference << std::endl;
    std::cout << "Max Flow Difference: " << metrics.maxFlowDifference << std::endl;

    return 0;
}

