#include "gtest/gtest.h"
#include "proj1.hpp"
#include "ver.hpp" 
#include <unordered_map>
#include <string>


/*
 
Note that this IS NOT a comprehensive set of test cases.
You should still write additional test cases.

This is to get you started and serve as a sanity check.


Note that "gradeYesAnswer" is provided for use in your test cases, but 
you may NOT use it in any code you write otherwise for this project.

 */


namespace{

TEST(SimpleCases, PotPanBib){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("POT", "PAN", "BIB", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("POT", "PAN", "BIB", puzzle) ) ;
}

TEST(SimpleCases, NeatFind){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("UCI", "ALEX", "MIKE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("UCI", "ALEX", "MIKE", puzzle) );
} // end test two, "NeatFind"


TEST(SimpleCases, FirstNo){

    std::unordered_map<char, unsigned> puzzle;

    bool p1 = puzzleSolver("LARRY", "CAREER", "LEGEND", puzzle);
    EXPECT_FALSE( p1 );
}

TEST(SimpleCases, First){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("AA", "BB", "AA", puzzle);
    EXPECT_FALSE( p1 && gradeYesAnswer("AA", "BB", "AA", puzzle) );
}

TEST(SimpleCases, Second){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("UCI", "BE", "GOOD", puzzle);
    EXPECT_FALSE( p1 && gradeYesAnswer("UCI", "BE", "GOOD", puzzle) );
}

TEST(SimpleCases, Third){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("NBA", "NBA", "UGG", puzzle);
    EXPECT_FALSE( p1 && gradeYesAnswer("NBA", "NBA", "UGG", puzzle) );
}

TEST(SimpleCases, Fourth){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("CAT", "DOG", "PIG", puzzle);
    EXPECT_FALSE( p1 && gradeYesAnswer("CAT", "DOG", "PIG", puzzle) );
}

TEST(SimpleCases, Fifth){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("L", "O", "L", puzzle);
    EXPECT_FALSE( p1 && gradeYesAnswer("L", "O", "L", puzzle) );
}

} // end namespace
