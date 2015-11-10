#ifndef _CHAPTER_1_H
#define _CHAPTER_1_H

#include<iostream>
#include<vector>
#include<string>
#include<cstring>

// solution functions
// Problem 1.1
bool CharsAllUniqueTime(const std::string& s);
bool CharsAllUniqueMem(const std::string& s);

// Problem 1.2
void SwapChars(char* str, size_t i, size_t j);
void reverse(char* str);

// test functions
// Problem 1.1
void Problem_1_1_Test();
void Problem_1_2_Test();

#endif