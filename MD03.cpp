#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool isPrime(unsigned long long num) {
    if (num < 2) return false;
    for (unsigned long long i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) return false;
    }
    return true;
}

void decodeHash(vector<unsigned long long> hashes) {
    for (auto hash : hashes) {
        unsigned long long id = 0;
        for (unsigned long long key = 2; key <= sqrt(hash); key++) {
            if (isPrime(key) && hash % key == 0) {
                id = hash / key;
                break;
            }
        }
        cout << "HASH = " << hash << " => ID = " << id << endl;
    }
}

int main() {
    vector<unsigned long long> hashes = {
        893142186867131ULL,
        1523998012134749ULL,
        7145200861828339ULL,
        12193227629792731ULL,
        1219325544212859089ULL
    };

    decodeHash(hashes);

    return 0;
}
