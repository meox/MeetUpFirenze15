#include <stdio.h>
#include <stdlib.h>

typedef int bool;
#define true 1
#define false 0


bool is_even(unsigned int n)
{
    return n % 2 == 0;
}


bool is_prime(unsigned int n)
{
    if (n == 2)
        return true;
    else if (is_even(n))
        return false;
    else
    {
        for (unsigned int e = 3; e*e <= n; e += 2)
            if (n % e == 0) return false;
        return true;
    }
}



void primes(unsigned int n)
{
    unsigned int c = 1, i = 3;

    printf("2\n");
    while(c < n)
    {
        if(is_prime(i))
        {
            printf("%d\n", i);
            c++;
        }
        i += 2;
    }
}


int main(int argc, char* argv[])
{
    if (argc == 1)
    {
        //cout << sum_primes(100) << endl;
        primes(100);
    }
    else if (argc > 1)
    {
        //cout << sum_primes(std::stoi(argv[1])) << endl;
        primes(strtol(argv[1], (char **)NULL, 10));
    }
}

