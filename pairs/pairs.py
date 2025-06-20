#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'pairs' function below.
#
# The function is expected to return an INTEGER.
# The function accepts following parameters:
#  1. INTEGER k
#  2. INTEGER_ARRAY arr
#

def pairs(k, arr):
    # Write your code here
    map_ ={}
    for elemnt in arr:
        if elemnt in map_:
            map_[elemnt] +=1
        else:
            map_[elemnt] = 1
    
    pairs = 0
    keys_ = list(map_.keys())
    
    for key in keys_:
        if key + k in map_:
            pairs = pairs + 1
        
    
    return pairs
        
    
if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    first_multiple_input = input().rstrip().split()

    n = int(first_multiple_input[0])

    k = int(first_multiple_input[1])

    arr = list(map(int, input().rstrip().split()))

    result = pairs(k, arr)

    fptr.write(str(result) + '\n')

    fptr.close()
