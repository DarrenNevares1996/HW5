/*
#################################################
                    PSUEDOCODE
#################################################
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#################################################
################## BUBBLE SORT ##################
#################################################
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void Bubble Sort:BubbleSort(std::vector<std::string>& vec):
    IF (vec size is = 1 OR vec size =0):
        THEN:
            return;
    ELSE:
        Declare boolean sorted to FALSE
        Declare boolean tempSort
        DO WHILE LOOP:
            DO:
                Set tempSort to TRUE
                FOR(Int i = 1, from i to the size of vec):
                    IF(The vector array with the index of [i - 1] comes after vec with the index of [i] alphabetically):
                        Swap the locations of the ORIGINAL vector with the index of [i - 1] with vec with the index of [i]
                        Set tempSort = FALSE
                    IF(tempSort is EQUAL to true and i is EQUAL to the size of vec minus one):
                        Set sorted EQUAL to TRUE
            WHILE(sorted is EQUAL to false) 
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
################################################
################ INSERTION SORT ################
################################################
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
void InsertionSort(std::vector<int>& v):
    Call InsertionSortHelper(v, v.size())

void InsertionSortHelper(std::vector<int>& v, int n):
    If length is less than or EQUAL to 1
        RETURN, the sorting is complete.
    Call InsertionSortHelper(v,n-1) recursively with (v, and n-1)
    Declare Integer last to store v[n-1]
    Declare Integer j to hold position of n-2
    While Loop:
        While j is greater than 0 and v[j] is greater than last value
            Set v[j+1] EQUAL to v[j]
            Subtract 1 from j
        Set v[j+1] EQUAL to value of last
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
################################################
################## MERGE SORT ##################
################################################
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
# vector<std::string>& vec = vector passed
# int left = left index of array for sorting
# int right = right index of array for sorting

void MergeSort(std::vector<std::string> &vec)):
    Call the MergeSortHelper function and pass the parameters vec, zero, and the size of vec minus 1
    MergeSortHelper(vec, 0, vec.size() - 1)

void MergeSortHelper(std::vector<std::string>& vec, int left, int right):
    IF(right index is greater than left index ):
        Declare integer middle and assign it to the size of array divided by 2
    Call MergeSort for the first half of the vector array with left as the leftmost and middle as the rightmost value
        MergeSort(vec, left, middle):
    Call MergeSort for the second half of the vector array with middle + 1 as the leftmost value and right as the rightmost value
        MergeSort(vec, middle + 1, right):
    Merge the first sorted array and second sorted array:
        MergeSortFinal(vec, left, middle, right)
# MergeSortFinal will sort the already sorted vector arrays in its same memory location
void MergeSortFinal(std::vector<std::string>& vec, int left, int right):
    Declare a new temporary vector array tempArray with size of ORIGINAL vector
    Delcare int leftEnd EQUAL to the rightPos - 1;
    Delcare int tempPos EQUAL to the leftPos
    Delcare int numElements EQUAL to the rightEnd - leftPos + 1;
    WHILE(leftPos is less than or EQUAL to rightPos AND rightPos is less than or EQUAL to rightEnd):
        IF(ORIGINAL vector array with the index of [leftPos] is less than or EQUAL to ORIGINAL vector array with the index of rightPos):
            Set the TEMPORARY vector array tempArray with the index of [tempPos++] EQUAL to the ORIGINAL vector array with the index of [leftPos++]
        ELSE:
            Set the TEMPORARY vector array tempArray with the index of [tempPos++] EQUAL to the ORIGINAL vector array with the index of [rightPos++]
    
    WHILE(leftPos is less than or EQUAL ot leftEnd):
        // Copies the remainder of the first half of the vector array
        Set the TEMPORARY vector array tempArray with the index of [tempPos++] EQUAL to the ORIGINAL vector array with the index of [leftPos++]
    WHILE(rightPos is less than or EQUAL ot rightEnd):
        // Copies the remainder of the first half of the vector array
        Set the TEMPORARY vector array tempArray with the index of [tempPos++] EQUAL to the ORIGINAL vector array with the index of [rightPos++]
    
    FOR(Int i = 0, from i to numElement, with each loop adding 1 to i (i++) and subtracting 1 from rightEnd (rightEnd--)):
        Set ORIGINAL vector array with the index of [tempPos++] EQUAL to the TEMPORARY vector array with the index of [rightPos++]
*/

#ifndef __H_
#define __HW5_H__
#include "hw5.h"
#include <iostream>
#include <string>
#include <vector>

void BubbleSort(std::vector<std::string> &vec) {
  if (vec.size() == 1 || vec.size() == 0) {
    return;
  }
  bool sorted = false;
  bool tempSort;
  do {
    tempSort = true;
    for (int i = 1; i < vec.size(); i++) {
      // vec[i-1] is second alphabetically
      if (vec[i - 1].compare(vec[i]) > 0) { 
        // shift needed, swap places
        std::swap(vec[i - 1], vec[i]);
        tempSort = false;
      }
      // Checks if vector is sorted
      if (tempSort && i == vec.size() - 1) {
        sorted = true;
      }
    }
  } while (!sorted);
}

void InsertionSortHelper(std::vector<int> &v, int n) {
  if (n <= 1) {
    return;
  }
  InsertionSortHelper(v, n - 1);

  int last = v[n - 1];
  int j = n - 2;

  while (j >= 0 && v[j] > last) {
    v[j + 1] = v[j];
    j--;
  }
  v[j + 1] = last;
}

void InsertionSort(std::vector<int> &v) { InsertionSortHelper(v, v.size()); }

void MergeSortFinal(std::vector<std::string> &vec, int leftPos, int rightPos,
                    int rightEnd) {

    // Declare tempArray vector with size of original vector.
    std::vector<std::string> tempArray(vec.size());

    // Declare variables
    int leftEnd = rightPos - 1;
    int tmpPos = leftPos;
    int numElements = rightEnd - leftPos + 1;

    // Main loop
    while(leftPos <= leftEnd && rightPos <= rightEnd)
        if(vec[leftPos] <= vec[rightPos])
            tempArray[tmpPos++] = vec[leftPos++];
        else
            tempArray[tmpPos++] = vec[rightPos++];
    
    // Copies the remainder of first half
    while(leftPos <= leftEnd)       
        tempArray[tmpPos++] = vec[leftPos++];
    
    // Copies the remainder of second half
    while(rightPos <= rightEnd)     
        tempArray[tmpPos++] = vec[rightPos++];
    
    // Copy tmpArray back
    for(int i = 0; i < numElements; i++, rightEnd--)
        vec[rightEnd] = tempArray[rightEnd];
}

void mergeSortHelper(std::vector<std::string> &vec, int left, int right) {
  if (left < right) {
    int middle = (left + right) / 2;

    // Calls MergeSort for the first half of the vector array
    mergeSortHelper(vec, left, middle);

    // Calls MergeSort for the second half of the vector array
    mergeSortHelper(vec, middle + 1, right);

    // Merge the two halves
    MergeSortFinal(vec, left, middle + 1, right);
  }
}

void MergeSort(std::vector<std::string> &vec) {
  mergeSortHelper(vec, 0, vec.size() - 1);
}

#endif /* __HW5_H__ */
