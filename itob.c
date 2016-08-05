#include <stdio.h>
#include <math.h>

void itob(int n, char s[], int b);
void convert_hex(int n,int orig, char s[], int b);
void convert_binary(int n, int orig, char s[], int b);
void reduce(int n, int base, char s[], int prev);
int get_base(int n, int b);

int main()
{
    char str[20];
    itob(17, str, 16);
    return 0;
}

void itob(int n, char s[], int b)
{
    int orig;
    orig = n;
    switch(b) {
        case 16:
            convert_hex(n, orig, s, b);
            break;
        case 2:
            convert_binary(n, orig, s, b);
            break;
    }
}

void convert_binary(int n, int orig, char s[], int b)
{
    int prev, curr, j, times;
    j = 0;
    prev = -1; // keep track of previous reduced m-power   
    while(n > 0) {
        curr = get_base(n,b); // current index
        if(prev != -1) {
            times = prev - curr;
            if(times != 1) {
                while(times > 1) {
                    s[j++] = '0';
                    times--;
                }
            } else {
                s[j++] = '1';
            }
        } else {
            s[j++] = '1';
        }

        n = n - pow(b, curr);

        if(n == 0) {
            s[j++] = '1';
        }
        prev = curr; // save previous index 
    }
}

int get_base(int n, int b)
{
    int m, total; // power of 2's
    m = total = 0;
    while(total < n) {
        m++;
        total = (int) pow (b, m);
    }
    return m - 1;
}

void reduce(int n, int base, char s[], int prev)
{
    int m, total, num, power, j; // power of 2's
    m = j = total = 0;
    while(total < n) {
        m++;
        total = (int) pow (base, m);
    }

    power = m - 1;
    num = n - (int) pow(base,power);

    if(num > 0) {
        reduce(num, base, s, m);
    }

    if(prev != -1) {
        while((prev - m)  > 0) {
            s[j++] = '0';
            prev--;
        }
    } else {
        s[j++] = '1';
    }
}

void convert_hex(int n,int orig, char s[], int b)
{
    int i, r;
    i = 0;

    s[i++] = '0';
    s[i++] = 'x';

    n /= b;
    r = orig - n*b; 

    if(n % 16 == 0) {
        s[i++] = '1';
        while(n != 1) {
            n /= b;
            s[i++] = '0';
        }
    } else {
        s[i++] = n + '0';
        s[i] = r + '0';
    }
}

