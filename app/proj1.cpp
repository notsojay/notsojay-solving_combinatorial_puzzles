#include "proj1.hpp"
#include <unordered_map>
#include <unordered_set>
#include <string>
unsigned getStrNum(const std::string &str, const std::unordered_map<char, unsigned> &mapping)
{
	if(str.empty()) return 0;
	unsigned strNum = 0;
	int exponent = str.size()-1;
	for(const auto &i : str)
	{
		strNum = (strNum + mapping.at(i));
		if(exponent--) strNum *= 10;
	}
	return strNum;
}

bool verifySolution(const std::string &s1, const std::string &s2, const std::string &s3, const std::unordered_map<char, unsigned> &mapping)
{
	return getStrNum(s1, mapping) + getStrNum(s2, mapping) == getStrNum(s3, mapping);
}

void backTracking(const std::string &s1, const std::string &s2, const std::string &s3, std::unordered_map<char, unsigned> &mapping, const std::unordered_set<char> &letters, std::unordered_set<char>::iterator itor, bool visited[10], bool &result)
{ 
	if(itor == letters.end())
	{
		if(verifySolution(s1, s2, s3, mapping))
			result = true;
		return;
	}
	for(unsigned i = 0; i <= 9; ++i)
	{
		if(visited[i] == true) continue;
		mapping[*itor] = i;
		visited[i] = true;
		backTracking(s1, s2, s3, mapping, letters, std::next(itor), visited, result);
		if(result) return;
		visited[i] = false;
	}
}

std::unordered_set<char> removeDuplcateChar(const std::string &s1, const std::string &s2, const std::string &s3)
{
	std::unordered_set<char> letters;
	for(const auto &i : s1)
		letters.insert(i);
	for(const auto &i : s2)
		letters.insert(i);
	for(const auto &i : s3)
		letters.insert(i);
	return letters;
}

bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> &mapping)
{
	bool visited[10];
	bool result = false;
	const std::unordered_set<char> letters = removeDuplcateChar(s1, s2, s3);
	for(size_t i = 0; i < 10; ++i)
		visited[i] = 0;
	backTracking(s1, s2, s3, mapping, letters, letters.begin(), visited, result);
	return result;
}
