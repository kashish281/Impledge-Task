#include<bits/stdc++.h>
#include <fstream>
#include <chrono>
using namespace std;

bool isCompoundWord(const string &word, const unordered_set<string> &wordSet, bool isOriginal) {
    if (wordSet.find(word) != wordSet.end() && !isOriginal)
        return true;

    for (int i = 1; i < word.size(); i++) {
        string left = word.substr(0, i);
        string right = word.substr(i);

        if (wordSet.find(left) != wordSet.end() && isCompoundWord(right, wordSet, false))
            return true;
    }
    return false;
}

pair<string, string> findLongestCompoundWords(const vector<string> &words) {
    unordered_set<string> wordSet(words.begin(), words.end());
    string longestWord = "", secondLongestWord = "";

    for (const string &word : words) {
        if (isCompoundWord(word, wordSet, true)) {
            if (word.size() > longestWord.size()) {
                secondLongestWord = longestWord;
                longestWord = word;
            } else if (word.size() > secondLongestWord.size()) {
                secondLongestWord = word;
            }
        }
    }

    return {longestWord, secondLongestWord};
}

int main() {
    vector<string> words;
    string line;

    ifstream inputFile("Input_01.txt");
    if (!inputFile.is_open()) {
        cout << "Failed to open file" << endl;
        return 1;
    }

    while (getline(inputFile, line)) {
        words.push_back(line);
    }

    inputFile.close();

    auto start = chrono::high_resolution_clock::now();
    auto result = findLongestCompoundWords(words);
    auto end = chrono::high_resolution_clock::now();

    chrono::duration<double, milli> processingTime = end - start;

    cout << "Longest Compound Word: " << result.first << endl;
    cout << "Second Longest Compound Word: " << result.second << endl;
    cout << "Time taken to process file: " << processingTime.count() << " milliseconds" << endl;

    return 0;
}
