#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <queue>
#include <unordered_set>
using namespace std;
class Tries {
public:
	char ch;
	unordered_map<char, Tries *> children;
	bool endOfWord;
	Tries(char ch) {
		this->ch = ch;
		children[ch] = NULL;
		endOfWord = false;
	}
};
void insert(Tries *root , string &word , unsigned int i = 0) {
	if (i == word.size()) {
		root->endOfWord = true;
		return;
	}
	if (!root->children[word[i]] == 0) {
		root->children[word[i]] = new Tries(word[i]);
	}
	insert(root->children[word[i]] , word , i + 1);
}

void getAllPossibilities(Tries *root , string &beginWord  , vector<string>&adjacent , string curr = "" , int i = 0 , bool changed = false) {
	if (!root) return;
	if (i == beginWord.size()) {
		if (root->endOfWord && changed) {
			adjacent.push_back(curr);
		}
		return;
	}
	for (auto x : root->children) {
		curr.push_back(x.first);
		if (x.first == beginWord[i]) {
			getAllPossibilities(x.second , beginWord , adjacent , curr , i + 1 , changed);
		} else if (!changed) {
			getAllPossibilities(x.second , beginWord , adjacent , curr , i + 1 , true);
		}
		curr.pop_back();
	}
}
void dfs(vector<vector<string>> &output ,string &beginWord , string &endWord ,unordered_map<string,unordered_set<string>> &adjList , vector<string> &path){
	path.push_back(beginWord);
	if(beginWord==endWord){
		output.push_back(path);
		path.pop_back();
		return;
	}
	for(auto adj:adjList[beginWord]){
		dfs(output, adj , endWord , adjList ,path);
	}
	path.pop_back();
}
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	Tries *root = new Tries('\0');
	for (auto word : wordList) insert(root , word);
	unordered_map<string , unordered_set<string>> adjacentList;
	queue<string> Q;
	unordered_map<string, int> visited;
	Q.push(beginWord);
	visited[beginWord] = 1;
	while (Q.size()) {
		string curr = Q.front();
		Q.pop();
		vector<string> adjacent;
		getAllPossibilities(root , curr , adjacent);
		for (auto adj : adjacent) {
			if (visited.count(adj) == 0) {
				visited[adj] = visited[curr] + 1;
				adjacentList[curr].insert(adj);
				Q.push(adj);
			}else if(visited[adj]==visited[curr]+1){
				adjacentList[curr].insert(adj);
			}
		}
	}
	vector<vector<string>> output;
	vector<string> path;
	dfs(output,beginWord,endWord,adjacentList,path);
	return output;
}
int main() {
	string beginWord , endWord;
	cin >> beginWord >> endWord;
	int n; cin >> n;
	vector<string> wordList;
	for (int i = 0; i < n; i++) {
		string st;
		cin >> st;
		wordList.push_back(st);
	}
	vector<vector<string>> output = findLadders(beginWord , endWord , wordList);
	for (auto x : output) {
		for (auto y : x) cout << y << " ,";
		cout << '\n';
	}
}