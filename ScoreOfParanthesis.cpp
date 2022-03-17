/*

Given a balanced parentheses string s, return the score of the string.

The score of a balanced parentheses string is based on the following rule:

    "()" has score 1.
    AB has score A + B, where A and B are balanced parentheses strings.
    (A) has score 2 * A, where A is a balanced parentheses string.

 

Example 1:

Input: s = "()"
Output: 1

Example 2:

Input: s = "(())"
Output: 2

Example 3:

Input: s = "()()"
Output: 2

@LeetCode
*/

class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> score;
        int i=0;
        for(auto j : s){
            if(j == '('){
                score.push(i);
                i=0;
            }
            else{
                i = score.top()+max(2*i, 1);
                score.pop();
            }
        }
        return i;
    }
};