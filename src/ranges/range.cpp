#include <iostream>
#include <vector>
#include <string>
#include <range/v3/all.hpp>


bool is_even(uint n)
{
    return n % 2 == 0;
}


bool divides(uint x, uint n)
{
    return n % x == 0;
}


uint small_divisor(uint n)
{
    if (is_even(n))
        return 2;
    else
    {
        for (uint e = 3; e*e <= n; e += 2)
            if (divides(e, n)) return e;
    }
    return n;
}


bool is_prime(uint n)
{
    return n > 1 and small_divisor(n) == n;
}


using namespace std;
using namespace ranges;

auto gen_primes(uint n)
{
    return view::take(view::ints(2) | view::filter(is_prime), n);
}


template <typename F>
void primes(uint n, F f)
{
    ranges::for_each(gen_primes(n), f);
}


void show_primes(uint n)
{
    primes(n, [](uint e) { cout << e << '\n'; });
}


uint sum_primes(uint n)
{
    uint r{};
    primes(n, [&r](uint e) { r += e; });
    return r;
}


int main(int argc, char* argv[])
{
    if (argc == 1)
        show_primes(100);
    else if (argc > 1)
    {
        show_primes(std::stoi(argv[1]));
    }
}

