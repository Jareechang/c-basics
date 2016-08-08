#include <stdio.h>
#include <math.h>


double atof (char s[]); 
int digit(int digit);
int get_sign(char s[]);
int scientific_notation(char s[]);
int increment_index(int i, char s[]);
int skip_index(char s[]);

int main() 
{
    printf("atof: %4.4f\n", atof("322.404"));
    return 0;
}

double atof (char s[])
{
    // Example -10.0
    double num, decimal_figures, m;
    int i, power, sign, e_sign, e_power;
    double scientific_figures = 0.0;

    power = m = 10;
    i = num = decimal_figures = e_power = 0;
    int after_decimals = 0;
    int after_exp = 0;

    sign = get_sign(&s[i]);

    while(s[i] != '\0') {
        if(skip_index(&s[i])) {
            if(s[i] == '.') {
                after_decimals = 1;
            }
            if(after_exp) {
                e_sign = get_sign(&s[i]);
            }
        } else if(digit(s[i]) && !after_decimals) {
            num = (num * power) + (s[i] - '0');
        } else if(digit(s[i]) && !after_exp) {
            decimal_figures = decimal_figures + ((s[i] - '0') / m);
            m *= 10;
        } else if(scientific_notation(&s[i])) {
            after_exp = 1;
        } else if(after_exp) {
            while(digit(s[i])) {
                e_power = (e_power * power) + (s[i] - '0');
                i++;
            }
            scientific_figures = pow(10, e_sign * e_power); /* Calculate the scientific figures */
        }
        i++;
    }

    return (sign * (num + decimal_figures)) * (after_exp ? scientific_figures : 1);
}

int skip_index(char s[])
{
    return (*s == '-' || *s == '+' || *s == '.');
}

int increment_index(int i, char s[])
{
    if(*s == '-' || *s == '+' || *s == '.') {
        return i + 1;
    }    
    return i;
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
