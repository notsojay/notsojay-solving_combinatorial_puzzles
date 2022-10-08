#ifndef __PROJ_1__HPP
#define __PROJ_1__HPP

#include <unordered_map>
#include <unordered_set>
#include <string>

/* 
 * Project 1:  you need to implement this function.
 I promise that any of my test cases will have an empty 
 	map as the fourth parameter when called.
 If the puzzle IS solvable, return true AND make the mapping indicate the solution.
 If the puzzle is NOT solvable, it is enough to return false.

 See the project 1 write-up for a better description. 
*/

void reverseWord(std::array<std::string, 2> &strs, std::string &s3);

unsigned getStrNum(const std::string &str, const std::unordered_map<char, unsigned> &mapping);

bool verifySolution(const std::string &s1, const std::string s2, const std::string &s3, const std::unordered_map<char, unsigned> &mapping);

bool isAnyCharLeft(const std::array<std::string, 2> &strs, std::unordered_map<char, unsigned> &mapping, bool visited[10]);

bool backTracking(std::array<std::string, 2> strs, std::string s3, std::unordered_map<char, unsigned> &mapping, const unsigned &row, const unsigned &col, const unsigned &sum, bool visited[10]);

bool puzzleSolver(std::string s1, std::string s2, std::string s3, std::unordered_map<char, unsigned> &mapping);

#endif
