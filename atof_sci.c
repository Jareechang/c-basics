#include <stdio.h>
#include <math.h>


double atof (char s[]); 
int is_digit(int digit);
int get_sign(char s[]);

int main() 
{
    printf("atof: %4.4f\n", atof("-3.23e-2"));
    return 0;
}

double atof (char s[])
{
    // Example -10.0
    double res, sig, decimal_figures, m;
    int i, power, sign, e_sign, e_power;
    power = m = 10;
    i = sig = decimal_figures = e_power = 0;

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
            decimal_figures = decimal_figures + ((s[i] - '0') / m);
            m *= 10;
            i++;
        }
    }

    if(s[i++] == 'e' || s[i++] == 'E') {
        e_sign = get_sign(&s[i]);
        if(s[i] == '-' || s[i] == '+') {
            i++;
        }
        while(is_digit(s[i]) && s[i] != '\0') {
            e_power = (e_power * power) + (s[i] - '0');
            i++;
        }
    }

    return (sign * (sig + decimal_figures)) * pow(10, e_sign * e_power);
}

int get_sign(char s[]) 
{
    return (*s == '-') ? -1 : 1;
}

int is_digit(int digit) 
{
    return (digit >= '0' && digit <= '9');
}
