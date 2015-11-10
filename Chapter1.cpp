#include "Chapter1.h"

// solution functions
///////////////////////////////////////////////////////////////////////////////
// Problem 1.1
bool CharsAllUniqueTime(const std::string& s)
{
	int charCounts[256] = { 0 };
	for (auto it = s.begin(); it != s.end(); ++it)
	{
		char tmp = *it;
		charCounts[tmp]++;
		if (charCounts[tmp] > 1)
			return false;
	}
	return true;
}

bool CharsAllUniqueMem(const std::string& s)
{
	for (auto curChar = s.begin(); curChar != s.end(); ++curChar) 
	{
		for (auto it = s.begin(); it != s.end(); ++it)
		{
			if (curChar == it)
				continue;
			if (*curChar == *it)
				return false;
		}
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////

// test functions
// Problem 1.1
///////////////////////////////////////////////////////////////////////////////
void Problem_1_1_Test()
{
	std::vector<std::string> test_cases;
	test_cases.push_back("abcde12345");
	test_cases.push_back("");
	test_cases.push_back("aa");
	test_cases.push_back("abcc1234567890");
	std::cout << "Testing problem 1.1:\n";
	for (auto it = test_cases.begin(); it != test_cases.end(); ++it)
	{
		std::cout << "Testing string: " << *it << '\n';
		std::cout << "Time effecient solution returned: "
			<< CharsAllUniqueTime(*it) << '\n';
		std::cout << "Memory effecient solution returned: "
			<< CharsAllUniqueMem(*it) << '\n';
	}
	std::cout << "Test problem 1.1 concluded...\n\n\n\n\n";
}
///////////////////////////////////////////////////////////////////////////////