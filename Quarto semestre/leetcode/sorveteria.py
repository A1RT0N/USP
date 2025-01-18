#!/bin/python3

import math
import os
import random
import re
import sys

#
# Complete the 'icecreamParlor' function below.
#
# The function is expected to return an INTEGER_ARRAY.
# The function accepts following parameters:
#  1. INTEGER m
#  2. INTEGER_ARRAY arr
#

def list_to_dict(arr):
    
    dict_ = {}
    for index, elem in enumerate(arr):
        dict_.setdefault(elem,[])
        dict_[elem].append(index+1)
    return dict_

def icecreamParlor(m, arr):
    # Write your code here
    if len(arr) == 2:
        if sum(arr) != m:
            return []
        return [1,2]

    
    sorted_arr = sorted(arr)
    
    final_index = -1
    for i in range(len(sorted_arr)):
        element = sorted_arr[i]
        if element > m:
            break
        final_index = i
    
    sorted_arr = sorted_arr[:final_index+1]
    
    i = 0
    j = final_index
    
    final_value = []
    _dict_index_map = list_to_dict(arr=arr)    
    
    while(i < j):
        i_val = sorted_arr[i]
        j_val = sorted_arr[j]
        sum_ = i_val + j_val
        
        
        if sum_ == m:
            i_index =  _dict_index_map[i_val].pop(0)
            j_index =  _dict_index_map[j_val].pop(0)
            final_value.append(i_index)
            final_value.append(j_index)  
            break
        elif sum_ < m:
            i += 1
        else:
            j -= 1
    
    return sorted(final_value)
        

if __name__ == '__main__':
    t = int(input().strip())

    for t_itr in range(t):
        m = int(input().strip())

        n = int(input().strip())

        arr = list(map(int, input().rstrip().split()))

        result = icecreamParlor(m, arr)

        print(result)
