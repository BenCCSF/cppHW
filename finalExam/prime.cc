#include <iostream>
#include <vector>
using namespace std;

//Using a basic method for calculating primes here - efficiency could be improved

const int PRIME_TARGET = 10001; //What prime number are we searching for

bool isPrime(long int testNum, const vector<int>& prevPrimes) {
    //Using a long int to be sure we have plenty of space (we don't want int overflow - although that is not an error here, if we want to find bigger primes, it could be a problem)
    //NOTE: the vector must have at least one element in it or this will not work
    int i = 0; //Our position in the vector
    while (((prevPrimes[i] * prevPrimes[i]) <= testNum)) {
        //If our number is smaller than the square of a prime, and we have tested all previous primes, our number cannot be a multiple of any prime, and is therefore prime 
        if ((testNum % prevPrimes[i]) == 0) {
            //If the remainder is 0, then the number can be evenly divided by a prime number and therefore cannot be prime
            return false;
        }
        i++;
    }
    return true;
}

int main() {
    long int iter = 3; //Which number are we on (iterating)
    vector <int> primes; //A vector of all the prime numbers we have found, inserted sorted - dynamic size allows for any number of primes 
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
