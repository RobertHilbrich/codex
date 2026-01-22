#include "primes.h"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    {
        auto primes = generate_primes(1);
        assert(primes.empty());
    }

    {
        auto primes = generate_primes(2);
        std::vector<int> expected{2};
        assert(primes == expected);
    }

    {
        auto primes = generate_primes(30);
        std::vector<int> expected{2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
        assert(primes == expected);
    }

    {
        auto primes = generate_primes(1'000'000);
        assert(primes.size() == 78498);
        assert(primes.front() == 2);
        assert(primes.back() == 999983);
    }

    std::cout << "All prime tests passed.\n";
    return 0;
}
