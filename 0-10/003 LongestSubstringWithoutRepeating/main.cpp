#include <iostream>
#include <string>
#include "longestsubstring.h"

using namespace std;
#define CATCH_CONFIG_MAIN
#include "../001 two sum/catch.hpp"

TEST_CASE("Longest Substring Without Repeating Characters", "[lengthOfLongestSubstring]")
{
    Solution s;

    REQUIRE( s.lengthOfLongestSubstring("a") == 1 );
    REQUIRE( s.lengthOfLongestSubstring("au") == 2 );
    REQUIRE( s.lengthOfLongestSubstring("bwt") == 3 );
    
    //REQUIRE( s.lengthOfLongestSubstring("bbbbb") == 1 );
    REQUIRE( s.lengthOfLongestSubstring("abbwa") == 3 );
    REQUIRE( s.lengthOfLongestSubstring("abcabcbb") == 3 );
}


// int main()
// {
//     string c="abfgjdfdgfd";

//     std::cout<<c<<endl;

//     Solution s;
//     int result;
//     result=s.lengthOfLongestSubstring(c);

//     std::cout<<result<<endl;


//     return 0;
// }