/* 
Lab 1
A program that inputs NUMBERS until the user types 0.
The numbers must be POSITIVE; otherwise, it outputs "Negative numbers are not allowed".
When 0 is typed, it prints out what the largest and smallest number was.
*/

#include <stdio.h>

int main() {
    int num, max = 0, min = 0;
    int first = 1; // Used to distinguish the first number from subsequent ones

    while (1) {
        printf("Enter a positive number (0 to quit): ");
        scanf("%d", &num);

        if (num < 0) {
            printf("Negative numbers are not allowed\n");
            continue;
        }
        
        if (num == 0) {
            break; // End input
        }
        
        if (first) {
            // The first positive number sets both min and max
            max = num;
            min = num;
            first = 0;
        } else {
            if (num > max) max = num;
            if (num < min) min = num;
        }
    }

    if (!first) {
        printf("Largest number: %d\n", max);
        printf("Smallest number: %d\n", min);
    } else {
        printf("No valid numbers were entered.\n");
    }

    return 0;
}

/* 
Lab 2
A municipality has made the following forecast for population development in the coming years:
At the beginning of 2022, the municipality had 26,000 inhabitants.

Number of births per year: 0.7%.
Number of deaths per year: 0.6%.
The number of immigrants per year is estimated to be 300.
The number of emigrants per year is estimated to be 325.

In the following program, a year (after 2022) is input,
and it calculates the municipality's estimated population for that year.
*/

#include <stdio.h>

int main() {
    int startPopulation = 26000; // Population at the beginning of 2022
    double birthRate = 0.007;    // 0.7% born per year
    double deathRate = 0.006;    // 0.6% died per year
    int immigrants = 300;        // Number of immigrants per year
    int emigrants = 325;         // Number of emigrants per year

    int year;
    printf("Enter a year (after 2022): ");
    scanf("%d", &year);

    if (year <= 2022) {
        printf("The year must be after 2022.\n");
        return 1; // Exit the program if the year is not after 2022
    }

    int yearsToCalculate = year - 2022;
    int population = startPopulation;

    for (int i = 0; i < yearsToCalculate; i++) {
        int births = population * birthRate;
        int deaths = population * deathRate;

        population = population + births - deaths + immigrants - emigrants;
    }

    printf("Estimated population for the year %d: %d\n", year, population);
    
    return 0;
}

/* 
Lab 3
A program (calculator) where you input numbers and an operator, then the result is calculated.
Operators can be * / + -.
*/

#include <stdio.h>

int main() {
    double num1, num2, result;
    char operator;

    printf("Enter the first number: ");
    if (scanf("%lf", &num1) != 1) {
        printf("Invalid input! Expected a number.\n");
        return 1;
    }

    printf("Enter the second number: ");
    if (scanf("%lf", &num2) != 1) {
        printf("Invalid input! Expected a number.\n");
        return 1;
    }

    printf("Enter operator (+, -, *, /): ");
    scanf(" %c", &operator); // Space before %c to ignore previous newline

    switch (operator) {
        case '+':
            result = num1 + num2;
            printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
            break;

        case '-':
            result = num1 - num2;
            printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
            break;

        case '*':
            result = num1 * num2;
            printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
            break;

        case '/':
            if (num2 == 0) {
                printf("Error: Division by zero is not allowed.\n");
            } else {
                result = num1 / num2;
                printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
            }
            break;

        default:
            printf("Error: Invalid operator. Use +, -, * or /.\n");
            return 1;
    }

    return 0;
}

/* 
Lab 4
A program where you first specify HOW MANY numbers will be entered.
Then you input that many numbers and it prints how many of them
were between 100 and 200.
*/

#include <stdio.h>

int main() {
    int countToInput, number, count = 0;

    // Ask the user for the number of entries
    printf("How many numbers would you like to enter? ");
    if (scanf("%d", &countToInput) != 1 || countToInput <= 0) {
        printf("Invalid input! Expected a positive integer.\n");
        return 1;
    }

    // Input the specified numbers and count how many are between 100 and 200
    for (int i = 0; i < countToInput; i++) {
        printf("Enter number %d: ", i + 1);
        if (scanf("%d", &number) != 1) {
            printf("Invalid input! Expected an integer.\n");
            return 1;
        }

        if (number >= 100 && number <= 200) {
            count++;
        }
    }

    // Output the result
    printf("Count of numbers between 100 and 200: %d\n", count);

    return 0;
}
