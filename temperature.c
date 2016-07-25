#include <stdio.h>

/* print Fahrenheit-Celcius Table
  For fahr = 0, 20, ... 300 */
int main()
{
    float fahr, celcius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while(fahr <= upper) {
        // Added heading of the table
        if(fahr == 0 ) {
            printf("T(C)  T(F)\n");
        }
        celcius = (5.0/9.0) * (fahr-32);
        printf("%3.0f %6.1f\n", fahr, celcius);
        fahr = fahr + step;
    }
    // End
    return 0;
}
