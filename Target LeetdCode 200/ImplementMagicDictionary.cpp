#include <bits/stdc++.h>
using namespace std;

class Trie {
   public:
    bool eow;
    unordered_map<char, Trie *> children;
    Trie() {
        this->eow = false;
    }
};

class MagicDictionary {
    Trie *root;

   public:
    MagicDictionary() {
        root = new Trie();
    }

    void buildDict(vector<string> dictionary) {
        for (string &str : dictionary) insert(str);
    }

    bool search(string searchWord) {
        return doSearch(searchWord, root);
    }

   private:
    bool doSearch(string &str, Trie *node, bool change = false, int i = 0) {
        if (!node) {
            return false;
        }
        if (i == str.size()) {
            return node->eow && change;
        }
        if (!node->children[str[i]] && change) {
            return false;
        }

        bool found = false;
        if (change) {
            found = doSearch(str, node->children[str[i]], change, i + 1);
        } else {
            for (auto child : node->children) {
                found |= doSearch(str, child.second, child.first != str[i], i + 1);
                if (found) break;
            }
        }
        return found;
    }

    void insert(string &str) {
        int i = 0;
        Trie *temp = root;
        while (i < str.size()) {
            if (!temp->children[str[i]])
                temp->children[str[i]] = new Trie();
            temp = temp->children[str[i]];
            i++;
        }
        temp->eow = true;
    }
};

int main() {
}