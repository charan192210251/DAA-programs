#include <stdio.h>
#include <stdbool.h>

// Function to check if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // 1 and numbers less than 1 are not prime
    }
    
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // Number is divisible by i, so it's not prime
        }
    }
    return true; // If no divisors were found, the number is prime
}

int main() {
    printf("Prime numbers between 1 and 100 are:\n");

    for (int i = 1; i <= 100; i++) {
        if (isPrime(i)) {
            printf("%d ", i);
        }
    }

    return 0;
}

