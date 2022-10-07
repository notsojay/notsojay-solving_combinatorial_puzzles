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
        
    bool p1 = puzzleSolver("PEACE", "LOVE", "UNITY", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("PEACE", "LOVE", "UNITY", puzzle) );
}

TEST(SimpleCases, Second){
        
    std::unordered_map<char, unsigned> puzzle;
    
    bool p1 = puzzleSolver("L", "O", "L", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("L", "O", "L", puzzle) );
}

TEST(SimpleCases, Third){
        
    std::unordered_map<char, unsigned> puzzle;
    
    bool p1 = puzzleSolver("JIAHAO", "BAITAO", "YUNHUI", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("JIAHAO", "BAITAO", "YUNHUI", puzzle) );
}

TEST(SimpleCases, FOUTH){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("PACMAN", "N", "CONTROL", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("PACMAN", "N", "CONTROL", puzzle) );
}

TEST(SimpleCases, FIFTH){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("OOP", "C", "N", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("OOP", "C", "N", puzzle) );
}

TEST(SimpleCases, SIXTH){
        
    std::unordered_map<char, unsigned> puzzle;
        
    bool p1 = puzzleSolver("AAB", "CDCI", "IRVINE", puzzle);
    EXPECT_TRUE( p1 &&  gradeYesAnswer("AAB", "CDCI", "IRVINE", puzzle) );
}

} // end namespace
