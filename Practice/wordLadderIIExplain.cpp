class Solution {
public:
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

	//	If string ended mark as current node as an endOfWord
	if (i == word.size()) {
		root->endOfWord = true;
		return;
	}

	//	Whether we have already node then use it else create a new node
	if (!root->children[word[i]]) {
		root->children[word[i]] = new Tries(word[i]);
	}
	insert(root->children[word[i]] , word , i + 1);
 }

void getAllPossibilities(Tries *root , string &beginWord  , vector<string>&adjacent , string curr = "" , int i = 0 , bool changed = false) {

	//	We can't get any possibilities
	if (!root) return;

	//	We got only when current node has end of word curr is most be changed
	if (i == beginWord.size()) {
		if (root->endOfWord && changed) {
			adjacent.push_back(curr);
		}
		return;
	}

	//	Explore all the possibilities
	for (auto x : root->children) {

		curr.push_back(x.first);
		if (x.first == beginWord[i]) {
			// We didn't replace
			getAllPossibilities(x.second , beginWord , adjacent , curr , i + 1 , changed);
		} else if (!changed) {
			// We did replace
			getAllPossibilities(x.second , beginWord , adjacent , curr , i + 1 , true);
		}

		//	BackTrack
		curr.pop_back();
	}
 }
void dfs(vector<vector<string>> &output , string &beginWord , string &endWord , unordered_map<string, unordered_set<string>> &adjList , vector<string> &path) {
	
	//	Store the path
	path.push_back(beginWord);

	//	We got the path
	if (beginWord == endWord) {
		output.push_back(path);
		path.pop_back();
		return;
	}

	//	Explore all neighbour
	for (auto adj : adjList[beginWord]) {
		dfs(output, adj , endWord , adjList , path);
	}

	//	Backtrack
	path.pop_back();
 }
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
	//	Make a tries
	Tries *root = new Tries('\0');

	//	Insert all word from wordlist into tries
	for (auto word : wordList) insert(root , word);

	//	Need for storing the different -2 path
	unordered_map<string , unordered_set<string>> adjacentList;

	//	For level order traversal
	queue<string> Q;

	//	For visited
	unordered_map<string, int> visited;

	//	Push beginWord into Q
	Q.push(beginWord);

	//	Mark as visited
	visited[beginWord] = 1;

	//	Iterate level by level
	while (Q.size()) {

		//	Get front from queue
		string curr = Q.front();
		Q.pop();

		//	Store all possible adjacent node from curr
		vector<string> adjacent;
		getAllPossibilities(root , curr , adjacent);

		//	Make BFS Tree
		for (auto adj : adjacent) {
			//	Whether adj is visited or not
			if (visited.count(adj) == 0) {
				visited[adj] = visited[curr] + 1;

				//	Store into BFS Tree
				adjacentList[curr].insert(adj);

				//	Push back to queue
				Q.push(adj);
			} else if (visited[adj] == visited[curr] + 1) {
				//	Curr is parent of adjacent
				adjacentList[curr].insert(adj);
			}
		}
	}

	//	For output
	vector<vector<string>> output;

	//	For the path
	vector<string> path;

	//	Store all the path
	//	We don't need visited because adjacentList has BFS tree so there wouldn't be any circle!!!
	dfs(output, beginWord, endWord, adjacentList, path);
	return output;
 }
};