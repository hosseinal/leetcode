#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'equal' function below.
#
# The function is expected to return an INTEGER.
# The function accepts INTEGER_ARRAY arr as parameter.
#

def equal(arr):
    # Write your code here
    min_val = min(arr)
    sums = []
    for i in range(5):
        total = 0
        for element in arr:
            val = element - (min_val - i)
            total += val//5 + (val%5)//2 + (val%5%2)
        sums.append(total)
    
    return min(sums)
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    t = int(input().strip())

    for t_itr in range(t):
        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = equal(arr)

        fptr.write(str(result) + '\n')

    fptr.close()

