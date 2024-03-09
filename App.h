#ifndef RAILWAY_NETWORK_APP_H
#define RAILWAY_NETWORK_APP_H

#include <iostream>

class App {
public:
    App();
    void BSM();
    void OCO();
    void RSF();
    std::string MOD();
    void K(std::string s);
    void TS();
    std::string TSF();
    void TSS(std::string s);
    bool isNumber(std::string s);
};

#endif //RAILWAY_NETWORK_APP_H
