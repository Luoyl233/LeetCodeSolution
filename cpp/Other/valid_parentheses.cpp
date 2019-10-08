/**
  20. Valid Parentheses
*/

#include "common.h"
#include <string>
#include <stack>
#include <iostream>

using namespace std;

#ifdef VALID_PARENTHESES


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int len = s.size();
        bool flag = true;

        for (int i=0; i < len && flag; i++) {
            char ch = s[i];
            switch (ch) {
            case '(': case '{': case '[':
                st.push(ch);
                break;
            case ')':
                if (!st.empty() && st.top() == '(')
                    st.pop();
                else
                    flag = false;
                break;
            case '}':
                if (!st.empty() && st.top() == '{')
                    st.pop();
                else
                    flag = false;
                break;
            case ']':
                if (!st.empty() && st.top() == '[')
                    st.pop();
                else
                    flag = false;
                break;
            default:
                break;
            }
        }

        if (!st.empty())
            flag = false;

        return flag;
    }
};

int main()
{

    string s("([)]");

    cout << Solution().isValid(s) << endl;

    return 0;
}



#endif


