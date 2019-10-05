/*
 * 208. Implement Trie (Prefix Tree)
 */


#include "common.h"


#if LEET_CODE == 208

struct TrieNode {
    unordered_map<char, TrieNode*> dict;
    bool isWord;
    TrieNode() : isWord(false) {}
};

class Trie {
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }

    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->dict.find(ch) == cur->dict.end()) {
                cur->dict[ch] = new TrieNode();
            }
            cur = cur->dict[ch];
        }
        cur->isWord = true;
    }

    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for (char ch : word) {
            if (cur->dict.find(ch) == cur->dict.end())
                return false;
            cur = cur->dict[ch];
        }

        return cur->isWord;
    }

    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for (char ch : prefix) {
            if (cur->dict.find(ch) == cur->dict.end())
                return false;
            cur = cur->dict[ch];
        }

        return true;
    }

private:
    TrieNode *root;
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main()
{
    cout << "208. Implement Trie (Prefix Tree)" << endl;

    return 0;
}


#endif
