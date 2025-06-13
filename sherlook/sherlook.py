#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'isValid' function below.
#
# The function is expected to return a STRING.
# The function accepts STRING s as parameter.
#

def isValid(s):
    index = {}
    # Write your code here
    for s_char in s:
        if s_char not in index:
            index[s_char] = 1
        else:
            index[s_char] = index[s_char] + 1
    
    
    first = next(iter(index.values()))
    values = list(index.values())
    counter = 0

    for c in range(len(values)):
        difference1 = first - values[c]
        if difference1 != 0:
            counter += 1
            
    if counter > 1:
        return 'NO'
    
    return 'YES'    
    

if __name__ == '__main__':
    fptr = open(os.environ['OUTPUT_PATH'], 'w')

    s = input()

    result = isValid(s)

    fptr.write(result + '\n')

    fptr.close()
