/*
/*
PSUEDOCODE:
Bubble Sort:
InsertionSort(<int>vector):
    Call InsertionSortHelper(vector, vector.size())
InsertionSortHelper(<int>vector, int n):
    If length is less than or equal to 1
        RETURN, the sorting is complete.
    Call InsertionSortHelper(vector,n-1) recursively with (vector, and n-1)
    Declare Integer 'last' to store vector[n-1]
    Declare Integer 'j' to hold position of n-2
    While Loop:
        While j is greater than 0 and vector[j] is greater than 'last' value
            Set vector[j+1] equal to vector[j]
            Subtract 1 from j
        Set vector[j+1] equal to value of 'last'
*/

#ifndef __H_
#define __HW5_H__
#include <iostream>
#include <string>
#include <vector>
#include "hw5.h"

