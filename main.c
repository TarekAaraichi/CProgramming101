/* Lab 1
Ett program som MATAR IN TAL tills dess att man skriver 0.
Talen måste vara POSITIVA annars skris ut "Negativa tal är inte tillåtna"
När man skriver 0 så skrivs ut vilket det största och minsta talet var
*/

// #include <stdio.h>

// int main() {
//     int num, max = 0, min = 0;
//     int first = 1; // Används för att skilja första talet från efterföljande

//     while (1) {
//         printf("Mata in ett positivt tal (0 för att avsluta): ");
//         scanf("%d", &num);

//         if (num < 0) {
//             printf("Negativa tal är inte tillåtna\n");
//             continue;
//         }
        
//         if (num == 0) {
//             break; // Avsluta inmatning
//         }
        
//         if (first) {
//             // Första positiva talet sätter både min och max
//             max = num;
//             min = num;
//             first = 0;
//         } else {
//             if (num > max) max = num;
//             if (num < min) min = num;
//         }
//     }

//     if (!first) {
//         printf("Största talet: %d\n", max);
//         printf("Minsta talet: %d\n", min);
//     } else {
//         printf("Inga giltiga tal matades in.\n");
//     }

//     return 0;
// }

/* Lab 2
En kommun har gjort följande prognos för befolkningsutvecklingen de närmaste åren
Vid början av 2022 hade kommunen 26000 invånare
Antal födda under ett år 0.7%
Antal avlidna under ett år 0.6%
Antalet inflyttade per år uppskattas till 300
Antal utflyttade per år uppskattas till 325

I följande program matas in ett årtal (efter 2022) 
och den ska beräkna kommunens beräknade befolkning för det året
*/

// #include <stdio.h>

// int main() {
//     int startPopulation = 26000; // Befolkning i början av 2022
//     double birthRate = 0.007;    // 0.7% födda per år
//     double deathRate = 0.006;    // 0.6% avlidna per år
//     int immigrants = 300;        // Antal inflyttade per år
//     int emigrants = 325;         // Antal utflyttade per år

//     int year;
//     printf("Mata in ett årtal (efter 2022): ");
//     scanf("%d", &year);

//     if (year <= 2022) {
//         printf("Årtalet måste vara efter 2022.\n");
//         return 1; // Avslutar programmet om årtalet inte är efter 2022
//     }

//     int yearsToCalculate = year - 2022;
//     int population = startPopulation;

//     for (int i = 0; i < yearsToCalculate; i++) {
//         int births = population * birthRate;
//         int deaths = population * deathRate;

//         population = population + births - deaths + immigrants - emigrants;
//     }

//     printf("Beräknad befolkning för år %d: %d\n", year, population);
    
//     return 0;
// }

/* Lab 3
Ett program där man matar in tal och en operator sedan räknas ut resultatet
Operators ska kunna vara * / + -
*/

// #include <stdio.h>

// int main() {
//     double num1, num2, result;
//     char operator;

//     printf("Mata in första talet: ");
//     if (scanf("%lf", &num1) != 1) {
//         printf("Felaktig inmatning! Förväntat ett tal.\n");
//         return 1;
//     }

//     printf("Mata in andra talet: ");
//     if (scanf("%lf", &num2) != 1) {
//         printf("Felaktig inmatning! Förväntat ett tal.\n");
//         return 1;
//     }

//     printf("Ange operator (+, -, *, /): ");
//     scanf(" %c", &operator); // Mellanslag före %c för att ignorera tidigare newline

//     switch (operator) {
//         case '+':
//             result = num1 + num2;
//             printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
//             break;

//         case '-':
//             result = num1 - num2;
//             printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
//             break;

//         case '*':
//             result = num1 * num2;
//             printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
//             break;

//         case '/':
//             if (num2 == 0) {
//                 printf("Fel: Division med noll är inte tillåten.\n");
//             } else {
//                 result = num1 / num2;
//                 printf("%.2lf %c %.2lf = %.2lf\n", num1, operator, num2, result);
//             }
//             break;

//         default:
//             printf("Fel: Ogiltig operator. Använd +, -, * eller /.\n");
//             return 1;
//     }

//     return 0;
// }

/* Lab 4
Ett program där man först anger HUR MÅNGA tal som ska matas in
Sen matar man in så många tal och skrivs ut hur många av dessa 
tal som var mellan 100 och 200
*/

#include <stdio.h>

int main() {
    int antal, tal, count = 0;

    // Ber användaren om antalet tal
    printf("Hur många tal vill du mata in? ");
    if (scanf("%d", &antal) != 1 || antal <= 0) {
        printf("Felaktig inmatning! Förväntat ett positivt heltal.\n");
        return 1;
    }

    // Matar in de angivna talen och räknar hur många som är mellan 100 och 200
    for (int i = 0; i < antal; i++) {
        printf("Mata in tal %d: ", i + 1);
        if (scanf("%d", &tal) != 1) {
            printf("Felaktig inmatning! Förväntat ett heltal.\n");
            return 1;
        }

        if (tal >= 100 && tal <= 200) {
            count++;
        }
    }

    // Skriv ut resultatet
    printf("Antal tal mellan 100 och 200: %d\n", count);

    return 0;
}
