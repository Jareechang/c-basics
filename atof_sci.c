#include <stdio.h>
#include <math.h>


double atof (char s[]); 
int digit(int digit);
int get_sign(char s[]);
int scientific_notation(char s[]);

int main() 
{
    printf("atof: %4.4f\n", atof("-3.23e-2"));
    return 0;
}

double atof (char s[])
{
    // Example -10.0
    double res, num, decimal_figures, m;
    int i, power, sign, e_sign, e_power;
    double scientific_figures = 0.0;

    power = m = 10;
    i = num = decimal_figures = e_power = 0;

    sign = get_sign(&s[i]);

    if(s[i] == '-' || s[i] == '+') {
        i++;
    }

    while(digit(s[i])) {
        num = (num * power) + (s[i] - '0');
        i++;
    }

    if(s[i] == '.') {
        i++;
    }

    if(digit(s[i])) {
        while(digit(s[i])) {
            decimal_figures = decimal_figures + ((s[i] - '0') / m);
            m *= 10;
            i++;
        }
    }

    if(scientific_notation(&s[i++])) {
        e_sign = get_sign(&s[i]);
        if(s[i] == '-' || s[i] == '+') {
            i++;
        }
        while(digit(s[i])) {
            e_power = (e_power * power) + (s[i] - '0');
            i++;
        }
        scientific_figures = pow(10, e_sign * e_power); /* Calculate the scientific figures */
    }

    return (sign * (num + decimal_figures)) * scientific_figures;
}

int get_sign(char s[]) 
{
    return (*s == '-') ? -1 : 1;
}

int scientific_notation(char s[])
{
   return *s == 'e' || *s == 'E';
}

int digit(int digit) 
{
    return (digit >= '0' && digit <= '9');
}
