// CS2211a 2023
// Assignment #4
// Salim Terzout Yettou
// 251214366
// sterzout
// November 15, 2023
#include <stdio.h>

int main() {
    float euler;
    printf("Enter num: ");
    scanf("%f", &euler);
    float eValue = 1;
    float val = 1;
    float counter = 1;
// calculates euler to the closest approximation using float variables initializations and divisions
    while (counter >= euler) {
        counter = counter/val;
        eValue = eValue + counter;
        val = val + 1;
    }

    printf("Euler Approximation Value: %f", eValue);
}