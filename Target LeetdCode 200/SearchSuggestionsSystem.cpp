#include <bits/stdc++.h>
using namespace std;

class Trie {
   public:
    Trie** children;
    bool eow;
    Trie() {
        eow = false;
        children = new Trie*[26];
        for (int i = 0; i < 26; i++) children[i] = nullptr;
    }
};

class Solution {
    Trie* root;

   public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        root = new Trie();
        for (string& str : products) insert(str);
        vector<vector<string>> output;
        string str = "";
        for (char ch : searchWord) {
            str.push_back(ch);
            vector<string> curr;
            Trie* temp = root;
            int i = 0;
            while (i < str.size() && temp) temp = temp->children[str[i++] - 'a'];
            getSuggestions(temp, curr, str);
            output.push_back(curr);
        }
        return output;
    }

   private:
    void getSuggestions(Trie* rootNode, vector<string>& out, string& word) {
        if (!rootNode) {
            return;
        }
        if (rootNode->eow) {
            out.push_back(word);
        }
        if (out.size() == 3) {
            return;
        }
        for (int i = 0; i < 26 && out.size() != 3; i++) {
            word.push_back(i + 'a');
            getSuggestions(rootNode->children[i], out, word);
            word.pop_back();
        }
    }

    void insert(string& str) {
        Trie* temp = root;
        for (int i = 0; i < str.size(); i++) {
            char ch = str[i];
            if (!(temp->children[ch - 'a'])) {
                temp->children[ch - 'a'] = new Trie();
            }
            temp = temp->children[ch - 'a'];
        }
        temp->eow = true;
    }
};

int main() {
}