#include "Chapter1.h"

// solution functions
// Problem 1.1
///////////////////////////////////////////////////////////////////////////////
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

// Problem 1.2
///////////////////////////////////////////////////////////////////////////////
void SwapChars(char* str, size_t i, size_t j)
{
	char tmp = str[i];
	str[i] = str[j];
	str[j] = tmp;
}

void reverse(char* str)
{
	size_t length = strlen(str);
	if (length <= 1) return;
	size_t endIt = length - 1;
	size_t beginIt = 0;
	while (endIt > beginIt)
	{
		SwapChars(str, beginIt, endIt);
		beginIt++;
		endIt--;
	}
}
///////////////////////////////////////////////////////////////////////////////

// Problem 1.3
///////////////////////////////////////////////////////////////////////////////
bool Permutation(const std::string& s, const std::string& match)
{
	if (s == match)
		return true;
	std::map<char, int> sMap;
	std::map<char, int> matchMap;
	for (auto it = s.begin(); it != s.end(); ++it)
		sMap[*it]++;
	for (auto it = match.begin(); it != match.end(); ++it)
		matchMap[*it]++;
	if (sMap.size() != matchMap.size())
		return false;
	for (auto it = sMap.begin(); it != sMap.end(); ++it)
	{
		if (matchMap[it->first] != it->second)
			return false;
	}
	return true;
}
///////////////////////////////////////////////////////////////////////////////

// Problem 1.4
///////////////////////////////////////////////////////////////////////////////
void ReplaceSpaces(char* str, int len)
{
	int spaceCount = 0;
	int newLen = 0;
	for (int i = 0; i < len; i++)
		if (str[i] == ' ') spaceCount++;
	newLen = len + spaceCount*2;
	str[newLen - 1] = '\0';
	for (int i = len-1; i >= 0; i--)
	{
		if (str[i] == ' ')
		{
			str[newLen - 1] = '0';
			str[newLen - 2] = '2';
			str[newLen - 3] = '%';
			newLen -= 3;
		}
		else
		{
			str[newLen - 1] = str[i];
			newLen--;
		}
	}
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

// Problem 1.2
///////////////////////////////////////////////////////////////////////////////
void Problem_1_2_Test()
{
	std::vector<std::string> test_cases;
	test_cases.push_back("abcde12345");
	test_cases.push_back("");
	test_cases.push_back("aa");
	test_cases.push_back("abcc1234567890");
	std::cout << "Testing problem 1.2:\n";
	for (auto it = test_cases.begin(); it != test_cases.end(); ++it)
	{
		char* tmpArray;
		tmpArray = new char[it->size() + 1];
		strcpy(tmpArray, it->c_str());
		std::cout << "Testing string: " << *it << '\n';
		std::cout << "Reverse function returned: ";
		reverse(tmpArray);
		std::cout << tmpArray << '\n';
		delete[] tmpArray;
	}
	std::cout << "Test problem 1.2 concluded...\n\n\n\n\n";
}
///////////////////////////////////////////////////////////////////////////////

// Problem 1.3
///////////////////////////////////////////////////////////////////////////////
void Problem_1_3_Test()
{
	std::vector<std::string> test_cases;
	test_cases.push_back("abc");
	test_cases.push_back("cab");
	test_cases.push_back("aaaassdfsd");
	test_cases.push_back("aaaadfssdsc");
	test_cases.push_back("");
	test_cases.push_back("");
	test_cases.push_back("def");
	test_cases.push_back("def");
	std::cout << "Testing problem 1.3:\n";
	for (auto it = test_cases.begin(); it != test_cases.end(); it +=2)
	{
		auto it2 = it+1;
		std::cout << "Testing match: " << *it << ' ' << *it2 << '\n';
		std::cout << "Permutation checker returned: "
		<< Permutation(*it, *it2) << '\n';
	}
	std::cout << "Test problem 1.3 concluded...\n\n\n\n\n";
}

///////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////////////////////////////////////////////
void Problem_1_4_Test()
{
	std::string testStr("Mr John Smith    ");
	std::cout << "Testing problem 1.4:\n";
	std::cout << "Input string: " << testStr << '\n';
	std::cout << "Output string: ";
	char* output = new char[testStr.length() + 1];
	strcpy(output, testStr.c_str());
	ReplaceSpaces(output, 13);
	std::cout << output << '\n';
	std::cout << "Test problem 1.4 concluded...\n\n\n\n\n";
	delete [] output;
}
///////////////////////////////////////////////////////////////////////////////




