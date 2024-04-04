#include "Management.h"
#include "App.h"

int main() {

    // change to true if you want to test the Management.h functions
    bool testing = false;

    if (!testing) {
        App app;
        app.startUI();
    } else {
        // Management.h functions can be called from here while testing
        Management management;
        Management::maxAmountSpecificCity();
    }

    return 0;
}

