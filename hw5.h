// Hint: given two strings str1 and str2, we can use str1.compare(str2). compare() returns 0 if the strings are equal,
// < 0 if str1 comes first alphabetically, and > 0 if str2 comes first alphabetically.

//void InsertionSort(std::vector<std::string> &vec);

void InsertionSort(std::vector<int>& v);

// For this problem, re-implement the Insertion Sort algorithm recursively.
// Rather than use a loop to go through each position we must insert into, use a recursive call. We want to insert the smallest element into the first position first and continue until we insert the largest element into the last position last. Remember that the last recursive call (the base case) finishes executing first and that the first recursive call finishes executing last.




#endif /* __HW5_H__ */