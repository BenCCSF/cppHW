#include <iostream>
//#include <cstdlib>
using namespace std;

int _atoi(const char * str) {
    //Should have same functionality as cstdlib atoi
    int total = 0; 
    while (*str && *str <= 57 && *str >= 48) {
        total = total * 10;
        total += (*str - 48);
        str++;
    }
    return total;
}



int main() {
    char c[32] = "123";
    int d = _atoi(c);
    cout << d << endl;

    return 0;
}
