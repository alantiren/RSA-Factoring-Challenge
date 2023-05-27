#!/usr/bin/env bash

import sys

def factorize(num):
    factors = []
    for i in range(2, num // 2 + 1):
        if num % i == 0:
            factors.append((i, num // i))
    return factors

def main():
    if len(sys.argv) != 2:
        print("Usage: factors <file>")
        return

    file_path = sys.argv[1]

    try:
        with open(file_path, 'r') as file:
            for line in file:
                num = int(line.strip())
                factor_pairs = factorize(num)
                for pair in factor_pairs:
                    print(f"{num}={pair[0]}*{pair[1]}")
    except FileNotFoundError:
        print(f"File '{file_path}' not found.")

if __name__ == '__main__':
    main()
