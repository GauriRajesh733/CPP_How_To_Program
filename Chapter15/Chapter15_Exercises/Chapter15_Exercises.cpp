// Chapter15_Exercises.cpp

#include <iostream>
#include <vector>
#include <bitset>
using namespace std;


template<typename T> bool isPalindrome(vector<T>);

int main()
{
    // determine if vector is a palindrome
    vector<int> intNotPalindrome{ 1,2,3,4,5 };
    cout << isPalindrome(intNotPalindrome) << endl;

    vector<char> stringPalindrome{ 'r','a','c','e','c','a','r' };
    cout << isPalindrome(stringPalindrome) << endl;

    vector<double> doublePalindrome{ 1.34 };
    cout << isPalindrome(doublePalindrome) << endl;

    // list all primes up to 100 (sieve of eratosthenes)
    bitset<100> is_prime; // NOTE: efficient for storing boolean values
    is_prime.set(); // set all bits to true
    is_prime[0] = false; // 0 and 1 are not prime
    is_prime[1] = false;

    // mark 2 as prime and remove multiples
    for (int i = 2; i < 100; i++) {
        // if prime number remove multiples
        if (is_prime[i]) {
            for (int j = i * 2; j < 100; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for (int i = 0; i < 100; i++) {
        // display if prime
        if (is_prime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

template<typename T>
bool isPalindrome(vector<T> v)
{
    auto rit = v.rbegin(); // NOTE: auto means compiler infers type based on initialization expression
    auto it = v.cbegin();

    while (rit != v.rend()) {
        if (*rit != *it) {
            return false;
        }

        rit++;
        it++;
    }

    return true;
}
