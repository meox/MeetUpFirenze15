#!/usr/bin/env python

import sys


def is_even(n):
    return n % 2 == 0


def divides(x, n):
    return n % x == 0


def small_divisor(n):
    if is_even(n):
        return 2
    else:
        e = 3
        while e*e <= n:
            if divides(e, n):
                return e
            e = e + 2
        return n


def is_prime(n):
    return n > 1 and small_divisor(n) == n


def gen_primes(n):
    if n > 0:
        yield 2

        c, e = 1, 3
        while c < n:
            if is_prime(e):
                c = c + 1
                yield e
            e = e + 2


def show_primes(n):
    for p in gen_primes(n):
        print("%d" % p)



def sum_primes(n):
    s = 0
    for p in gen_primes(n):
        s = s + p
    return s


if __name__ == '__main__':
    if len(sys.argv) == 1:
        show_primes(100)
    else:
        show_primes(int(sys.argv[1]))
