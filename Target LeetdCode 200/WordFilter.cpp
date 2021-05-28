#include <bits/stdc++.h>
using namespace std;

class Trie {
   public:
    char ch;
    int idx;
    unordered_map<char, Trie*> children;

    Trie(char ch, int idx) {
        this->ch = ch;
        this->idx = idx;
    }

    Trie() {
        this->ch = '\0';
        this->idx = -1;
    }
};

class WordFilter {
    Trie* trie;

   public:
    WordFilter(vector<string>& words) {
        trie = new Trie();
        for (int i = 0; i < words.size(); i++) {
            string end = "#" + words[i];
            string start = "";
            int j = words.size() - 1;
            while (j >= 0) {
                insertIntoTrie(trie, start.append(end), i, 0);
                start += words[i][j--];
            }
        }
    }

    int f(string prefix, string suffix) {
        suffix.append("#");
        suffix.append(prefix);
        return getIndex(trie, suffix, 0);
    }

   private:
    int getIndex(Trie* trie, string& word, int i) {
        if (!trie) {
            return -1;
        }

        if (i == word.size()) {
            return trie->idx;
        }
        return getIndex(trie->children[word[i]], word, i + 1);
    }

    void insertIntoTrie(Trie* trie, string& word, int wt, int sId) {
        if (sId == word.size()) {
            return;
        }
        Trie* childNode = trie->children[word[sId]];
        if (!childNode) {
            childNode = new Trie(word[sId], wt);
        } else {
            childNode->idx = wt;
        }
        trie->children[word[sId]] = childNode;
        insertIntoTrie(childNode, word, wt, sId + 1);
    }
};

int main() {
}