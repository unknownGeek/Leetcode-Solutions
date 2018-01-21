/*
In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.

Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.

You need to output the sentence after the replacement.

Example 1:
Input: dict = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output: "the cat was rat by the bat"
Note:
The input will only have lower-case letters.
1 <= dict words number <= 1000
1 <= sentence words number <= 1000
1 <= root length <= 100
1 <= sentence words length <= 1000
*/



class Solution {
private:
class TrieNode{
        public:
        int index;
        vector<TrieNode*> children;
        TrieNode()
        {
            index=-1;
            children.resize(26, nullptr);
            //instead, we can write as follows:
            /*
              children.reserve(26);
              fill(children.begin(), children.end(), nullptr);
            */

        }
    };

TrieNode* root;
void insert(string &s, int pos)
{
    TrieNode* currNode = root;
    for(char ch : s)
    {
        int p = ch - 'a';
        if(!currNode->children[p])
               currNode->children[p]=new TrieNode();
       currNode = currNode->children[p];
    }
    currNode->index=pos;
}
int  query(string &s)
{
    TrieNode* currNode = root;
    for(char ch : s)
    {
        if(currNode)
        {
            int p = ch - 'a';
            currNode = currNode->children[p];
            if(!currNode)break;
            if(currNode->index >= 0)
                 return currNode->index;
        }
    }
  return -1;
}
public:
    string replaceWords(vector<string>& dict, string sentence) {
        root = new TrieNode();
        int position=0;
        for(auto dictionaryWord : dict)
              insert(dictionaryWord, position++);
        stringstream ss(sentence);
        string s;
        string result = "";
        while(ss >> s)
        {
            int ind = query(s);
            if(result.size())result+=' ';
            if(ind == -1)result+=s;
            else result+=dict[ind];
        }
        return result;
    }
};
