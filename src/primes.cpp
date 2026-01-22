#include "primes.h"

#include <cmath>
#include <vector>

std::vector<int> generate_primes(int limit) {
    if (limit < 2) {
        return {};
    }

    std::vector<bool> is_prime(static_cast<size_t>(limit + 1), true);
    is_prime[0] = false;
    is_prime[1] = false;

    int max_factor = static_cast<int>(std::sqrt(limit));
    for (int number = 2; number <= max_factor; ++number) {
        if (!is_prime[number]) {
            continue;
        }
        for (int multiple = number * number; multiple <= limit; multiple += number) {
            is_prime[multiple] = false;
        }
    }

    std::vector<int> primes;
    primes.reserve(static_cast<size_t>(limit / std::log(limit)));
    for (int number = 2; number <= limit; ++number) {
        if (is_prime[number]) {
            primes.push_back(number);
        }
    }

    return primes;
}
