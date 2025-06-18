#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'almostSorted' function below.
#
# The function accepts INTEGER_ARRAY arr as parameter.
#

def is_sorted(arr):
    for i in range(len(arr) -1):
        if arr[i] > arr[i+1]:
            return False
    return True

def almostSorted(arr):
    
    left = -1
    right = -1
    # first check swap
    for i in range(1,len(arr)):
        if arr[i-1] > arr[i]:
            left = i - 1
            break
    
    for i in range(left+1, len(arr)):
        if i == (len(arr) - 1) or arr[left] < arr[i+1]:
            right = i
            arr[left], arr[right] = arr[right], arr[left]
            break
    
    # print (left, right)
    if is_sorted(arr):
        print ("yes")
        print (f"swap {left+1} {right+1}")
        return
    
    arr[left], arr[right] = arr[right], arr[left]
    
    left = -1
    right = -1
    for i in range(0, len(arr)-1):
        if left == -1 and arr[i] > arr[i + 1] :
            left = i
        elif left != -1 and arr[i] < arr[i+1]:
            right = i
            break    
    
    if left != -1 and right == -1:
        right = len(arr) -1
    
    reverse = arr[left:right+1]
    new_arr = arr[:left] + reverse[::-1] + arr[right+1:]
    
    if is_sorted(new_arr):
        print ("yes")
        print (f"reverse {left+1} {right+1}")
        return
    
    # print(left, righte)
    print("no")

if __name__ == '__main__':
    n = int(input().strip())

    arr = list(map(int, input().rstrip().split()))

    almostSorted(arr)
