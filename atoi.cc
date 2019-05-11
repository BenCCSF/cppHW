#include <iostream>
using namespace std;

int _atoi(const char * str) {
    //Should have same functionality as cstdlib atoi
    int total = 0; 
    while (*str && *str <= 57 && *str >= 48) {
        total = total * 10;
	//ASCII codes for integers are from 48(0) to 57 (9)
        total += (*str - 48);
        str++;
    }
    return total;
}



int main() {
    char c[32] = "123";
    //Just an example string to convert
    int d = _atoi(c);
    cout << d << endl;
    return 0;
}
