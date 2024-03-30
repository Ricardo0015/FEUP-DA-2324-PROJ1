#include "App.h"
#include "../T2/BSM.h"
#include "../T3/RSF.h"

void App::loadDataSet() {
    // Load dataset (graph)
}

void App::startUI(Graph<std::string> graph){
    // there is a state machine here
    enum MenuOption {MENU, BSM, RSF, EXIT};
    MenuOption currentState = MENU;
    std::string choice;
    switch (currentState){
        case MENU:
            std::cout << "+---------------------------------------------------------------+\n"
                         "|                              Menu                             |\n"
                         "+---------------------------------------------------------------+\n"
                         "|        1) Basic Service Metrics                               |\n"
                         "|        2) Reliability and Sensitivity to Failures             |\n"
                         "|        0) Exit                                                |\n"
                         "+---------------------------------------------------------------+\n\n";
            std::cout << "Option: ";
            std::getline(std::cin, choice);
            std::cout << "\n";
            if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
            switch (choice[0]){
                case '1':
                    currentState = BSM;
                    break;
                case '2':
                    currentState = RSF;
                    break;
                case '0':
                    currentState = EXIT;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
            }
            break;
        case BSM:
            std::cout << "+-------------------------------------------------------------------+\n"
                         "|                       Basic Service Metrics                       |\n"
                         "+-------------------------------------------------------------------+\n"
                         "|        1) Maximum number mount of water that can reach            |\n"
                         "|        each or a specific city                                    |\n"
                         "|        2) Verify network capacity to meet water demands           |\n"
                         "|        and list cities with deficits                              |\n"
                         "|        3) Minimize the differences of flow to capacity on each    |\n"
                         "|        pipe across the entire network                             |\n"
                         "|        0) Back                                                    |\n"
                         "+-------------------------------------------------------------------+\n\n";
            std::cout << "Option: ";
            std::getline(std::cin, choice);
            std::cout << "\n";
            if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
            switch (choice[0]){
                case '1':
                    BSM::maxAmountSpecificCity(&graph);
                    break;
                case '2':
                    BSM::verifyNetworkCapacity(&graph);
                    break;
                case '3':
                    BSM::minimizeDifferencesFlowCapacity(&graph);
                    break;
                case '0':
                    currentState = MENU;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
            }
            break;
        case RSF:
            std::cout << "+-------------------------------------------------------------------+\n"
                         "|           Reliability and Sensitivity to Failures                 |\n"
                         "+-------------------------------------------------------------------+\n"
                         "|        1) Selectively remove one reservoir and list the           |\n"
                         "|        affected cities whose water supply does not meet           |\n"
                         "|        its demand                                                 |\n"
                         "|        2) Affected cities if a pumping station is                 |\n"
                         "|        out of service (if possible, don't affect                  |\n"
                         "|        delivery capacity                                          |\n"
                         "|        3) Affected cities if a rupture in a pipeline occurs       |\n"
                         "|        and pipelines that would make impossible to deliver        |\n"
                         "|        the desired amount of water to a given city                |\n"
                         "|        0) Back                                                    |\n"
                         "+-------------------------------------------------------------------+\n\n";
            std::cout << "Option: ";
            std::getline(std::cin, choice);
            std::cout << "\n";
            if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
            switch (choice[0]){
                case '1':
                    RSF::reservoirRemoval(&graph);
                    break;
                case '2':
                    RSF::pumpingStationRemoval(&graph);
                    break;
                case '3':
                    RSF::pipeRemoval(&graph);
                    break;
                case '0':
                    currentState = MENU;
                    break;
                default:
                    std::cout << "Invalid choice!" << std::endl;
                    break;
            }
            break;
        case EXIT:
            exit(0);
            break;
        default:
            std::cout << "Invalid state" << std::endl;
            break;
    }
}