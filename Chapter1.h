#ifndef _CHAPTER_1_H
#define _CHAPTER_1_H

#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<cstring>

// solution functions
// Problem 1.1
bool CharsAllUniqueTime(const std::string& s);
bool CharsAllUniqueMem(const std::string& s);

// Problem 1.2
void SwapChars(char* str, size_t i, size_t j);
void reverse(char* str);

// Problem 1.3
bool Permutation(const std::string& s, const std::string& match);

// Problem 1.4
void ReplaceSpaces(char* str, int len);

// test functions
void Problem_1_1_Test();
void Problem_1_2_Test();
void Problem_1_3_Test();
void Problem_1_4_Test();

#endif
