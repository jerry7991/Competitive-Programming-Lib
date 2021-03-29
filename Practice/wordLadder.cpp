#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <unordered_map>
using namespace std;
class Trie {
public:
	unordered_map<char, Trie*> children;
	bool endOfWrord;
	char ch;
	Trie(char ch) {
		this->ch = ch;
		endOfWrord = false;
		children[ch] = NULL;
	}
};
void insert(Trie *root , string &word , int i = 0) {
	if (i == word.size()) {
		root->endOfWrord = true;
		return;
	}
	if (!root->children[word[i]]) {
		root->children[word[i]] = new Trie(word[i]);
	}
	insert(root->children[word[i]] , word , i + 1);
}
void getAllPossible(Trie *root  , string &str , vector<string> &allPossible , string curr = "" , bool changed = false, unsigned int i = 0) {
	if (!root) return;
	if (curr.size() == str.size()) {
		if(root->endOfWrord)
			allPossible.push_back(curr);
		return;
	}
	for (auto x : root->children) {
		curr.push_back(x.first);
		if (x.first == str[i] ) {
			getAllPossible(x.second , str , allPossible , curr , changed , i + 1);
		} else if (!changed) {
			getAllPossible(x.second , str , allPossible , curr , !changed , i + 1);
		}
		curr.pop_back();
	}
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
	Trie *root = new Trie('\0');
	for (auto x : wordList) {
		insert(root , x);
	}
	queue<string> q;
	q.push(beginWord);
	unordered_map<string, int> visited;
	visited[beginWord] = 1;
	while (q.size() > 0) {
		string str = q.front();
		q.pop();
		if (str == endWord) return visited[str];
		vector<string> allPossible;
		getAllPossible(root , str , allPossible);
		for (auto x : allPossible) {
			// cout << x << " ";
			if (visited.count(x) == 0) {
				q.push(x);
				visited[x] = visited[str] + 1;
			}
		}
		cout << endl;
	}
	return 0;
}
int main() {
	string beginWord, endWord;
	vector<string> wordList;
	cin >> beginWord >> endWord;
	int n; cin >> n;
	while (n--) {
		string str;
		cin >> str;
		wordList.push_back(str);
	}
	cout << ladderLength(beginWord , endWord , wordList) << '\n';
}