#include <sstream>
#include "App.h"
#include "Management.h"

/**Método auxiliar
 * Este método é executado quando é necessário modificar uma string para que o programa consiga ler as strings.
 * Complexidade: O(n).
 * @param s Indica a string a modificar.
 * @return a string modificada.
 */

string StringFix(string s) {
    string newString;
    for (char c: s) {
        if ((c >= 65 && c <= 90) || (c >= 95 && c <= 122)) newString += c;
        else if (c == 32 || c == 45) {
            newString += c;
        } else {
            if (c == -58) newString += "ã";
            else if (c == -125) newString += "â";
            else if (c == -96) newString += "á";
            else if (c == -123) newString += "à";
            else if (c == -126) newString += "é";
            else if (c == -120) newString += "ê";
            else if (c == -95) newString += "í";
            else if (c == -94) newString += "ó";
            else if (c == -28) newString += "õ";
            else if (c == -109) newString += "ô";
            else if (c == -93) newString += "ú";
            else if (c == -121) newString += "ç";
            else if (c == -57) newString += "Ã";
            else if (c == -74) newString += "Â";
            else if (c == -75) newString += "Á";
            else if (c == -73) newString += "À";
            else if (c == -112) newString += "É";
            else if (c == -46) newString += "Ê";
            else if (c == -42) newString += "Í";
            else if (c == -32) newString += "Ó";
            else if (c == -27) newString += "Õ";
            else if (c == -30) newString += "Ô";
            else if (c == -23) newString += "Ú";
            else if (c == -128) newString += "Ç";
            else newString += c;
        }
    }
    return newString;
}

/**Variável check.
 * Esta variável é usada pelo código para determinar se as tabelas já foram apresensentadas ao utilizador.
 * Complexidade: O(1).
 */
bool check = true;

/**Chamada ao construtor da classe Management.
 * Usado para fazer chamadas as funções da classe Management, que apresentam os dados pedidos pelo utilizador.
 * Complexidade: O().
 */
Management m = Management();

/**Variável option.
 * Esta variável é usada pelo código para determinar qual a opção escolhida pelo utilizador, para poder apresentar os dados corretos.
 * Complexidade: O(1).
 */
int option = 0;

/**Programa principal.
 * App() é o método chamado em main para correr o programa. Este método contém a primeira tabela com opções para o utilizador escolher, processadas por um switch case.
 * Complexidade: O(N^2).
 */
App::App() {
    std::string choice = "1";
    do {
        if (check) {
            std::cout << "+---------------------------------------------------------------+\n"
                         "|                              Menu                             |\n"
                         "+---------------------------------------------------------------+\n"
                         "|        1) Basic Service Metrics                               |\n"
                         "|        2) Reliability and Sensitivity to Failures             |\n"
                         "|        0) Exit                                                |\n"
                         "+---------------------------------------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option!\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    std::cout << "Goodbye!\n";
                    break;
                case '1':
                    check = true;
                    BSM();
                    break;
                case '2': {
                    check = true;
                    RSF();
                    break;
                }
                default:
                    std::cout << "Insert a valid option!\n\n";
                    continue;
            }
        }
    }
    while(choice[0] != '0');
}

/**Basic Service Metrics.
 * Este método é executado após selecionar a opção Basic Service Metrics em App().
 * Apresenta uma tabela com opções para o utilazador escolher, mais uma vez processadas por switch case.
 * Determina a operação que o utilizador pretende executar, e executa após receber os inputs necessários.
 * Complexidade: O(N^2).
 */
void App::BSM() {
    std::string choice = "1";
    do {
        if (check) {
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
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    check = true;
                    option = 1;
                    std::string s = TSF();
                    if(s != "") TSS(s);
                    break;
                }
                case '2':
                    check = true;
                    option = 2;
                    m.maxCapacity();
                    do {
                        std::cout << "(1 to go back): ";
                        std::getline(std::cin, choice);
                        std::cout << "\n";
                    } while (choice != "1");
                    break;
                case '3': {
                    check = true;
                    option = 3;
                    std::string s = MOD();
                    if (s != "") K(s);
                    break;
                }
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    }
    while(choice != "0");
}

/**Reliability and Sensitivity to Failures.
 * Este método é executado após a seleção de Reliability and Sensitivity to Failures em App().
 * Apresenta uma tabela com opções para o utilazador escolher, mais uma vez processadas por switch case.
 * Determina a operação que o utilizador pretende executar, e executa após receber os inputs necessários.
 * Complexidade: O(N^2).
 */
void App::RSF() {
    std::string choice = "1";
    do {
        if (check) {
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
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    break;
                case '1': {
                    check = true;
                    option = 6;
                    std::string s = TSF();
                    if(s != "") TSS(s);
                    break;
                }
                case '2':
                    check = true;
                    option = 7;
                    K("Stations");
                    break;
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    }
    while(choice != "0");
}

/**Escolha entre municipalities e districts.
 * Este método é executado após escolher a opção What municipalities and districts should have a larger budget for purchasing and maintaining trains em BSM().
 * Ele apresenta uma tabela com opções para o utilazador escolher, mais uma vez processadas por switch case.
 * O seu objetivo é determinar se o utilizador pretende obter a informação sobre municipalities ou districts.
 * Complexidade: O(N).
 * @returns o texto da opção escolhida numa string.
 */
std::string App::MOD() {
    std::string choice = "1";
    do {
        if (check) {
            std::cout << "+--------------------------------------------+\n"
                         "|        Municipalities or districts?        |\n"
                         "+--------------------------------------------+\n"
                         "|        1) Municipalities                   |\n"
                         "|        2) Districts                        |\n"
                         "|        0) Back                             |\n"
                         "+--------------------------------------------+\n\n";
            check = false;
        }
        std::cout << "Option: ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() != 1) std::cout << "Insert a valid option\n\n";
        else {
            switch (choice[0]) {
                case '0':
                    check = true;
                    return "";
                case '1':
                    check = true;
                    return "Municipalities";
                case '2':
                    check = true;
                    return "Districts";
                default:
                    std::cout << "Insert a valid option\n\n";
                    continue;
            }
        }
    }
    while(choice != "0");
    return "";
}

/**Escolha de número de registos.
 * Este método é executado após escolher uma das opções em MOD().
 * Ele pede um input do utilizador com o número de registos que pretende ver.
 * Complexidade: O(N log N).
 * @param s Indica a string com 3 opções possíveis: Municipalities, Districs (ambas originárias da função MOD()) ou Stations, caso a chamada da função venha de RSLF().
 */
void App::K(std::string s) {
    std::string choice = "1";
    do {
        std::cout << "Insert the number of registers you what to see (Q to go back): ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() == 1 && choice[0] == 'Q') check = true;
        else if (isNumber(choice)) {
            check = true;
            if(s == "Municipalities") m.budget(0, stoi(choice));
            else if(s == "Districts") m.budget(1, stoi(choice));
            if(s == "Stations") m.mostAffectedStations(stoi(choice));
            std::cout << "\n\n";
            do {
                std::cout << "(1 to go back): ";
                std::getline(std::cin, choice);
                std::cout << "\n";
            } while (choice != "1");
            break;
        }
        else std::cout << "Insert a number\n\n";
    }
    while(choice != "Q");
}

/**Escolha de estação.
 * Semelhante a TSF() e TSS().
 * Este método é executado após escolher a opção Maximum number of trains that can arrive at a station at the same time em BSM().
 * Ele pede um input do utilizador com o nome da estação que pretende obter a informação.
 * Complexidade: O(N).
 */
void App::TS() {
    std::string choice = "1";
    do {
        std::cout << "Insert the name of the station (0 to go back): ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() == 1 && choice[0] == '0') check = true;
        else if (choice.length() != 0) {
            if (option == 4) m.flowSingleStation(StringFix(choice));
            std::cout << "\n\n";
            do {
                std::cout << "(1 to go back): ";
                std::getline(std::cin, choice);
                std::cout << "\n";
            } while (choice != "1");
            break;
        }
        else std::cout << "Insert something\n\n";
    }
    while(choice != "0");
}

/**Escolha de primeira estação.
 * Semelhante a TS() e TSS().
 * Este método é executado após escolher uma das opções que requerem duas estações em BSM(), OCO() e RSLF().
 * Ele pede um input do utilizador com o nome da primeira estação que pretende obter a informação.
 * Complexidade: O(N).
 * @returns string com o nome da estação.
 */
std::string App::TSF() {
    std::string choice = "1";
    do {
        std::cout << "Insert the name of the first station (0 to go back): ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() == 1 && choice[0] == '0') check = true;
        else if (choice.length() != 0) {
            return StringFix(choice);
        }
        else std::cout << "Insert something\n\n";
    }
    while(choice != "0");
    return "";
}

/**Escolha de segunda estação.
 * Semelhante a TS() e TSF().
 * Este método é executado após escolher uma das opções que requerem duas estações em BSM(), OCO() e RSLF(), em seguida a TSF().
 * Ele pede um input do utilizador com o nome da segunda estação que pretende obter a informação.
 * Complexidade: O(N * E * V^2).
 * @param s string com o nome da primeira estação escolhida pelo utilizador.
 */
void App::TSS(std::string s) {
    std::string choice = "1";
    do {
        std::cout << "Insert the name of the second station (0 to go back): ";
        std::getline(std::cin, choice);
        std::cout << "\n";
        if (choice.length() == 1 && choice[0] == '0') check = true;
        else if (choice.length() != 0) {
            if (option == 1) m.maxFlow(s, StringFix(choice));
            else if (option == 5) m.maxTrainsMinCost(s, StringFix(choice));
            else if (option == 6) m.maxFlowReducedConnectivity(s, StringFix(choice));
            std::cout << "\n\n";
            do {
                std::cout << "(1 to go back): ";
                std::getline(std::cin, choice);
                std::cout << "\n";
            } while (choice != "1");
            break;
        }
        else std::cout << "Insert something\n\n";
    }
    while(choice != "0");
}

/**Método auxiliar.
 * Este método é executado quando é necessário saber se uma string é um número.
 * Complexidade: O(N).
 * @param s Indica a string que se pretende verificar.
 * @returns true ou false dependendo se a string é um número ou não.
 */
bool App::isNumber(std::string s) {
    std::istringstream iss(s);
    float f;
    iss >> f;
    return iss.eof() && !iss.fail();
}