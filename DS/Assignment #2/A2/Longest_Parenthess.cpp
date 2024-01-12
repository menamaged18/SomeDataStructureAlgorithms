#include <bits/stdc++.h>
using namespace std;

int longestValidParentheses(string str)
{
    stack<int> stk;
    stk.push(-1);
    int ans = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '(')
        {
            stk.push(i);
        }
        else
        {
            stk.pop();
            if (stk.empty())
            {
                stk.push(i);
            }
            else
            {
                ans = max(ans, i - stk.top());
            }
        }
    }
    return ans;
}

int main()
{
    string s = "(())";
    cout << longestValidParentheses(s) << endl;
    return 0;
}
