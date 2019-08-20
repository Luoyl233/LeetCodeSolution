/**
 * 76. Minimum Window Substring
 */

#include "common.h"


#if LEET_CODE == 76

class Solution {
public:
        /*
         * Slow ???
        Runtime: 32 ms, faster than 32.38% of C++ online submissions for Minimum Window Substring.
        Memory Usage: 9.9 MB, less than 98.00% of C++ online submissions for Minimum Window Substring.
        */
        string minWindow1(string s, string t) {
                if (s.empty() || t.empty())
                        return "";

                unordered_map<char, int> required;	// Map that contains all the unique char and its frequency in string t
                unordered_map<char, int> contained;	// Map thet contains chars required in string t in current sliding window
                for (auto ch : t) {
                        if (required.find(ch) == required.end()) {
                                required[ch] = 1;
                                contained[ch] = 0;
                        }
                        else
                                required[ch] += 1;
                }

                int numRequired = required.size();
                int numContained = 0;

                int left = 0, right = -1;
                int minLeft = -1, minLength = 0x7fffffff; // Record the best result
                int curWindowLength = 0;
                int n = s.size();
                while (right < n) {
                        // Add char
                        right += 1;
                        curWindowLength += 1;
                        char ch = s[right];
                        if (required.find(ch) != required.end()) { // Only handle the chars which is also in string t
                                int cnt = contained[ch];
                                contained[ch] = cnt + 1;
                                numContained += required[ch] == (cnt + 1);
                        }

                        for (auto pair : contained)
                                printf("(%c,%d) ", pair.first, pair.second);
                        printf("\n\n");

                        // Current sliding window contains all the chars, then contract the window
                        while (numContained == numRequired && left <= right) {
                                if (curWindowLength < minLength) {
                                        minLeft = left;
                                        minLength = curWindowLength;
                                }
                                char removed = s[left];
                                if (required.find(removed) != required.end()) {
                                        int cnt = contained[removed];
                                        contained[removed] = cnt - 1;
                                        numContained -= required[removed] == cnt;
                                }
                                left++;
                                curWindowLength--;
                        }
                }

                return (minLeft != -1) ? s.substr(minLeft, minLength) : "";
        }

        /*
         * Runtime: 20 ms
         * Memory Usage: 9.9 MB
        */
        string minWindow(string s, string t) {
                if (s.empty() || t.empty())
                        return "";

                unordered_map<char, int> required;	// Map that contains all the unique char and its frequency in string t
                for (auto ch : t)
                        required[ch] ++;

                int numRequired = t.size();

                int left = 0, right = -1;
                int minLeft = -1, minLength = 0x7fffffff; // Record the best result
                int curWindowLength = 0;
                int n = s.size();
                while (right < n) {
            right++;
                        char ch = s[right];
                        int cnt = required[ch];
                        if (cnt > 0)
                                numRequired --;
                        required[ch] = cnt - 1;
                        curWindowLength++;

                        // for (auto pair : required)
                        // 	printf("(%c,%d) ", pair.first, pair.second);
                        // printf("\n\n");

                        while (numRequired == 0) {
                                if (curWindowLength < minLength) {
                                        minLength = curWindowLength;
                                        minLeft = left;
                                }
                                char ch = s[left];
                                int cnt = required[ch];
                                required[ch] = cnt + 1;
                                if (cnt == 0)
                                        numRequired ++;
                                left++;
                                curWindowLength--;
                        }
                }

                return (minLeft != -1) ? s.substr(minLeft, minLength) : "";
        }
};

#endif
