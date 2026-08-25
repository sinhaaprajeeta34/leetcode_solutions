class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        stringstream ss(s);
        string word;

        for (char ch : pattern) {
            if (!(ss >> word)) {
                return false;
            }

            if (charToWord.count(ch) && charToWord[ch] != word) {
                return false;
            }

            if (wordToChar.count(word) && wordToChar[word] != ch) {
                return false;
            }

            charToWord[ch] = word;
            wordToChar[word] = ch;
        }

        // Extra words present hain ya nahi
        if (ss >> word) {
            return false;
        }

        return true;
    }
};