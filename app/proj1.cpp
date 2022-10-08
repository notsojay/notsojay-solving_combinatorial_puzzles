#include "proj1.hpp"
#include <unordered_map>
#include <array>
#include <string>

/*
**		TOP
**		NAP
**		---
**		BIB
**		The processing order of the backtracking function should be from top to bottom.
** 		whether T + N is equal to B, O + A is equal to I, and P + P is equal to B.
**		So the traversal order should be T->N->B->O->A->I->P->P->B.
*/
void reverseWord(std::array<std::string, 2> &strs, std::string &s3)
{
	/*
	**	i.e.
	**		POT, PAN, BIB
	**		will be
	**		TOP, NAP, BIB
	*/
	std::reverse(s3.begin(), s3.end());
	for(size_t i = 0; i < strs.size(); ++i)
	{
		std::reverse(strs[i].begin(), strs[i].end());
	}
}

bool isAnyCharLeft(const std::array<std::string, 2> &strs, std::unordered_map<char, unsigned> &mapping, bool visited[10])
{
	for(const auto &i : strs)
	{
		for(const auto &j : i)
		{
			if(!mapping.count(j))
			{
				if(!visited[0])
				{
					mapping[j] = 0;
					visited[0] = true;
				}
				else 
				{
					return false;
				}
			}
		}
	}
	return true;
}

/*
**		TOP
**		NAP
**		---
**		BIB
**		The processing order of the backtracking function should be from top to bottom.
** 		whether T + N is equal to B, O + A is equal to I, and P + P is equal to B.
**		So the traversal order should be T->N->B->O->A->I->P->P->B.
*/
bool backTracking(const std::array<std::string, 2> &strs, const std::string &s3, std::unordered_map<char, unsigned> &mapping, const unsigned &row, const unsigned &col, const unsigned &sum, bool visited[10])
{
	if(col >= s3.size())
	{
		if(sum != 0) return false;
		return isAnyCharLeft(strs, mapping, visited);
	}
	if(row >= strs.size())
	{
		if(mapping.count(s3[col]) && mapping[s3[col]] != 10)
		{
			return mapping[s3[col]] != sum % 10 ? false : backTracking(strs, s3, mapping, 0, col+1, sum/10, visited);
		}
		else 
		{
			if(visited[sum%10] == true) return false;
			mapping[s3[col]] = sum % 10;
			visited[sum%10] = true;
			if(backTracking(strs, s3, mapping, 0, col+1, sum/10, visited)) return true;
			mapping[s3[col]] = 10;
			visited[sum%10] = false;
			return false;
		}
	}
	if(col >= strs[row].size())
	{
		return backTracking(strs, s3, mapping, row+1, col, sum, visited);
	}
	if(mapping.count(strs[row][col]) && mapping[strs[row][col]] != 10)
	{
		return backTracking(strs, s3, mapping, row+1, col, sum+mapping[strs[row][col]], visited);
	}
	else 
	{
		for(unsigned i = 0; i <= 9; ++i)
		{
			if(visited[i]) continue;
			mapping[strs[row][col]] = i;
			visited[i] = true;
			if(backTracking(strs, s3, mapping, row+1, col, sum+i, visited)) return true;
			mapping[strs[row][col]] = 10; // means that the character has not been mapped in the mapping, i.e. the original second value is removed.
			visited[i] = false;
		}
		return false;
	}
	return true;
}

bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> &mapping)
{
	bool visited[10]; // Note whether the number has been used in the mapping.
	std::array<std::string, 2> strs = {s1, s2};
	reverseWord(strs, s3);
	for(size_t i = 0; i < 10; ++i)
	{
		visited[i] = false;
	}
	return backTracking(strs, s3, mapping, 0, 0, 0, visited);
}