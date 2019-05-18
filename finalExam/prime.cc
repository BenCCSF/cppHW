#include <iostream>
#include <vector>
using namespace std;

//Using a basic method for calculating primes here - efficiency could be improved

const int PRIME_TARGET = 10001; //What prime number are we searching for

bool isPrime(long int testNum, const vector<int>& prevPrimes) {
    //Using a long int to be sure we have plenty of space (we don't want int overflow)
    int i = 0; //Our position in the vector
    while (((prevPrimes[i] * prevPrimes[i]) <= testNum) && (prevPrimes.size() > i)) {
        //If our number is smaller than the square of a prime, and we have tested all previous primes, our number cannot be a multiple of that prime
        if ((testNum % prevPrimes[i]) == 0) {
            //This number is not prime if this is true
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    long int iter = 3; //Which number are we on (iterating)
    vector <int> primes; //A vector of all the prime numbers we have found, inserted sorted 
    primes.push_back(2);
    //Note: initializing this vector with one value to preseve elegance of isPrime function
    while (primes.size() < PRIME_TARGET) {
        if (isPrime(iter, primes)) {
            primes.push_back(iter);
            if (primes.size() == PRIME_TARGET) {
                cout << iter << endl;
            }
        }
        iter++;
    }
    return 0; 
}
