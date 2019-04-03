#include <iostream>
#include "surgery.h"
using namespace std;

Surgery::Surgery() {
    brainCost = 30000.00;
    heartCost = 25000.00;
    hipCost = 15000.00;
    burnCost = 10000.00;
    appendixCost = 20000.00;
}
void Surgery::listOperations() {
    cout << "1. Brain Surgery ($30000)" << endl
        << "2. Heart Transplant ($25000)" << endl
        << "3. Hip Surgery ($15000)" << endl
        << "4. Burn Treatment ($10000)" << endl
        << "5. Appednix Removal ($20000)" << endl;
}
