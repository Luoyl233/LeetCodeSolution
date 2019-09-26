/*
 * 20. Valid Parentheses
 */


#include "common.h"


#if LEET_CODE == 20

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
    cout << "20. Valid Parentheses" << endl;

    return 0;
}


#endif
