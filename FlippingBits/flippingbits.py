#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'flippingBits' function below.
#
# The function is expected to return a LONG_INTEGER.
# The function accepts LONG_INTEGER n as parameter.
#


#change to string
def flippingBtsMethod2(n):
    binary_string = format(n, f'0{32}b')

    # Flip the bits in the string
    flipped_binary_string = ''.join(['1' if bit == '0' else '0' for bit in binary_string])

    # Convert the flipped binary string back to an integer
    new_integer = int(flipped_binary_string, 2)

    return

#use xor
def flippingBits(n):
    # Write your code here
    
    return  n ^ 0xFFFFFFFF
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    q = int(input().strip())

    for q_itr in range(q):
        n = int(input().strip())

        result = flippingBits(n)

        fptr.write(str(result) + '\n')

    fptr.close()
