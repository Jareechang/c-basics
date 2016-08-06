#include <stdio.h>
#include <math.h>


double atof (char s[]); 
int is_digit(int digit);

int main() 
{
    printf("atof: %4.2f\n", atof("-311.23"));
    return 0;
}

double atof (char s[])
{
    // Example -10.0
    double res, sig, dec_figures, m;
    int i, power, sign;
    power = m = 10;
    i = sig = dec_figures = 0;

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '-' || s[i] == '+') {
        i++;
    }

    while(is_digit(s[i])) {
        sig = (sig * power) + (s[i] - '0');
        i++;
    }

    if(s[i] == '.') {
        i++;
    }

    if(is_digit(s[i])) {
        while(is_digit(s[i])) {
            dec_figures = dec_figures + ((s[i] - '0') / m);
            m *= 10;
            i++;
        }
    }

    return sign * (sig + dec_figures);
}

int is_digit(int digit) 
{
    return (digit >= '0' && digit <= '9');
}
