/**
748. Shortest Completing Word::
Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate. Such a word is said to complete the given string licensePlate

Here, for letters we ignore case. For example, "P" on the licensePlate still matches "p" on the word.

It is guaranteed an answer exists. If there are multiple answers, return the one that occurs first in the array.

The license plate might have the same letter occurring multiple times. For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.

Example 1:
Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
Output: "steps"
Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
Note that the answer is not "step", because the letter "s" must occur in the word twice.
Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
Example 2:
Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
Output: "pest"
Explanation: There are 3 smallest length words that contains the letters "s".
We return the one that occurred first.
Note:
licensePlate will be a string with length in range [1, 7].
licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
words will have a length in the range [10, 1000].
Every words[i] will consist of lowercase letters, and have length in range [1, 15].
**/

class Solution {
public:
    string shortestCompletingWord(string licensePlate, vector<string>& words) {
        int freq1[26], freq2[26];
        memset(freq1, 0, sizeof freq1);
        for(char ch : licensePlate){
            if( ('a'<=ch && ch<='z' ) ){              
                ++freq1[ch - 'a'];
            }
            else if('A'<=ch && ch<='Z'){
                ++freq1[ch + 32 - 'a'];
            }
        }
        const int oo = 1e9;
        int minLength = oo;
        int selectedWordIndex = -1;
        int n = words.size();
        for(int i=0; i<n; ++i){
            string &word = words[i];        
            memset(freq2, 0, sizeof freq2);
            for(char ch : word){
                ++freq2[ch - 'a'];
            }
            int j;
            for(j=0; j<26; ++j){
                if(freq1[j]){
                    if(freq1[j] > freq2[j]){
                        break;
                    }
                }
            }
            if(j == 26 ){
                if(minLength > word.length()){
                    minLength = word.length();
                    selectedWordIndex = i;
                }
            }
        }
       return words[selectedWordIndex]; 
    }
};