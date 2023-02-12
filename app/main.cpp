// If you really want to make a program for the app, be my guest.
// Or better yet, use gtest to automate your own test cases!
// Remember, we use gtest to grade, not your main.
#include <iostream>
#include "proj1.hpp"

int main()
{
    std::unordered_map<char, unsigned> mapping;
    std::cout << puzzleSolver("NBA", "NBA", "UGG", mapping) << '\n';
    for(const auto &i : mapping)
        std::cout << i.first << " " << i.second << '\n';
    return 0;
}



