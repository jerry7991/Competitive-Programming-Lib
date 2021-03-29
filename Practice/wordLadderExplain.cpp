class Solution {
public:
class Trie {
public:
	unordered_map<char, Trie*> children;

	//	For getting end of word
	bool endOfWrord;
	char ch;
	Trie(char ch) {
		this->ch = ch;
		endOfWrord = false;
        children[ch]=NULL;
	}
};
void insert(Trie *root , string &word , int i = 0) {
	if (i == word.size()) {
		//	Set end of word as true and return
		root->endOfWrord = true;
		return;
	}

	//	If already an subtree then use it else make a new subtree node
	if (!root->children[word[i]]) {
		root->children[word[i]] = new Trie(word[i]);
	}

	//	insert rest part of the word into tries
	insert(root->children[word[i]] , word , i + 1);
}

void getAllPossible(Trie *root  , string &str , vector<string> &allPossible , string curr="" , bool changed = false,unsigned int i=0) {
	//	We can not get any string
	if (!root) return;

	// Finaly we got a string but will store only when it is a valid word from wordList
	if (curr.size() == str.size()) {
		if(root->endOfWrord)
			allPossible.push_back(curr);
		return;
	}

	// Explore all the node
	for (auto x : root->children) {
		curr.push_back(x.first);
		if (x.first == str[i] ) {
			// We are not replacing any char
			getAllPossible(x.second , str , allPossible , curr , changed , i + 1);
		} else if (!changed) {

			//	Replace a character only when if it has not yet changed single time
			getAllPossible(x.second , str , allPossible , curr , !changed , i + 1);
		}

		//	BackTrack what we stored
		curr.pop_back();
	}
}
int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

	//	Make a Trie
	Trie *root = new Trie('\0');

	//	Insert all word from wordList into trie
	for (auto x : wordList) {
		insert(root , x);
	}

	//	For Breadth First Search
	queue<string> q;

	//	Push beginWord into queue
	q.push(beginWord);

	//	For mark whether any string already visited or not?
	unordered_map<string,int> visited;

	//	Begin Word at level 1
	visited[beginWord]=1;

	//	Iterate over queue until it does not become empty
	while (q.size()>0) {

		//	Take the front from queue
		string str = q.front();
		q.pop();

		//	If str is endWord then return it
		if(str==endWord) return visited[str];

		//	Explore all possibilities which can be make way replacing a single character
		vector<string> allPossible;
		getAllPossible(root , str , allPossible);

		//	Push into queue if they are not visited yet!!!
		for(auto x:allPossible){
			if(visited.count(x)==0){
				q.push(x);
                visited[x]=visited[str]+1;
			}
		}
	}
	return 0;
}
};