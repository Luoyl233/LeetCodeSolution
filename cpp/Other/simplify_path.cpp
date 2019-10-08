/**
 * 71. Simplify Path
 */

#include "common.h"

#if LEET_CODE == 71

class Solution {
public:
        string simplifyPath(string path) {
                int n = path.size();
                int curPos = -1;
                int nextPos = path.find('/');
                int levelUp = 0;
                vector<string> vec;

                while (curPos < nextPos) {
                        //printf("%d, %d\n", curPos, nextPos);
                        string token = path.substr(curPos + 1, nextPos - 1 - curPos);

                        //cout << token << endl;
                        if (token.compare(".") == 0 || token.empty()) {} // Do nothing.
                        else if (token.compare("..") == 0) {
                                if (!vec.empty())
                                        vec.pop_back();
                        }
                        else
                                vec.push_back(token);
                        curPos = nextPos;
                        nextPos = path.find('/', curPos + 1);
                        if (nextPos == -1)
                                nextPos = path.size();
                }

                string res("/");
                if (!vec.empty()) {
                        for (int i = 0; i < vec.size() - 1; i++)
                                res += vec[i] + "/";
                        res += vec.back();
                }

                return res;
        }
};

#endif
