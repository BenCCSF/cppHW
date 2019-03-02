#include <iostream>
using namespace std;

int main() {
    const int MAX_FIB_LEN = 50; //We won't need more than this
    int fib[MAX_FIB_LEN] = {1, 2};
    int fibUsed = 2; //How much of fib we are using
    int sum = 0; //For adding numbers up
    //The following loop fills fib with only the numbers we need
    while (fibUsed < MAX_FIB_LEN && fib[fibUsed-1] < 1000) {
        fib[fibUsed] = fib[fibUsed-1] + fib[fibUsed-2];
        fibUsed++;
    }
    for (int i=0; i<fibUsed; i++) {
        if (!(fib[i] % 2)) {
            sum += fib[i];
        }
    }
    cout << "The sum of even values is " << sum << endl;
    return 0;
}
