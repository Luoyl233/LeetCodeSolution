/*
 * 394. Decode String
 */


#include "common.h"


#if LEET_CODE == 394

class Solution {
public:
    string decodeString(string s) {
        int idx = 0;
        string ans;

        while (idx < s.size()) {
            string repeats;

            // extract number
            while (isDigit(s[idx]))
                repeats.push_back(s[idx++]);

            // add sigle string
            if (repeats.empty()) {
                while (isLetter(s[idx]))
                    ans.push_back(s[idx++]);
            } else { // extract string and decode recursively
                int leftBrackets = 0;
                int k = stoi(repeats);
                int start = idx+1;
                int end;
                while (true) {
                    switch (s[idx++]) {
                        case '[':  leftBrackets ++; break;
                        case ']':   leftBrackets --; break;
                    }
                    if (leftBrackets == 0) {
                        end = idx-1;
                        break;
                    }
                }

                string substr = decodeString(s.substr(start, end-start));
                while ((k--) > 0)
                    ans += substr;
            }
        }
        return ans;
    }

    bool isDigit(char c) {
        return '0' <= c && c <= '9';
    }

    bool isLetter(char c) {
        return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z');
    }
};

int main()
{
    cout << "394. Decode String" << endl;

    return 0;
}


#endif
