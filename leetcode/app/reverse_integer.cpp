/*
 * reverse_integer.cpp
 *
 *  Created on: Jul 11, 2015
 *      Author: zxliu
 */

/*
 * Reverse digits of an integer.

 Example1: x = 123, return 321
 Example2: x = -123, return -321

 click to show spoilers.
 Have you thought about this?

 Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

 If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

 Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

 For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

 Update (2014-11-10):
 Test cases had been added to test the overflow behavior.
 *
 */

#include "leetcode/leetcode_fwd.h"

class Solution {
public:
    int reverse(int x) {
        int result = 0;
        for (; x; x /= 10){
            int left = x % 10;
            result = result * 10 + left;
        }
        return result;
    }
};

int main(int argc, char**argv) {
    Solution s;
    assert(321 == s.reverse(123));
    assert(-321 == s.reverse(-123));
    assert(321 != s.reverse(-123));
    return EXIT_SUCCESS;
}

