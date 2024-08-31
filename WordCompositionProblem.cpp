#include<bits/stdc++.h>
#include <fstream>
#include<chrono>
using namespace std;

//We use DP to check the word is compound or not
bool isCompound(const string &word, const unordered_set<string> &wordSet, unordered_map<string,bool> &dp){
    if(dp.find(word)!= dp.end())
    return dp[word];

    for(int i=1; i<word.size(); i++){
        string left = word.substr(0,i);
        string right = word.substr(i);

        if(wordSet.find(left) != wordSet.end() && (wordSet.find(right)!= wordSet.end() || isCompound(right, wordSet, dp))){
            dp[word] = true;
            return true;
        }
    }
    dp[word] = false;
    return false;
}

// find longest and second longest compound words
pair<string, string> LongestCompound(const vector<string> &words){
    unordered_set<string> wordSet(words.begin(), words.end());
    unordered_map<string,bool> dp;
    string longestWord = "", secondLongest = "";

    for(const string &word : words){
        if(isCompound(word, wordSet, dp)){
            if(word.size() > longestWord.size()) {
                secondLongest = longestWord;
                longestWord = word;

            }
            else if (word.size() > secondLongest.size())
            {
                secondLongest = word;
            }
            
        }
    }
    return {longestWord, secondLongest};
}

int main(){
    vector<string> words;
    string line;
    ifstream inputF("Input_02.txt");
    if(!inputF.is_open()){
        cout<<"Failed to open file"<<endl;
        return 1;
    }
    while (getline(inputF, line))
    {
        words.push_back(line);
    }
    inputF.close();

    auto start = chrono::high_resolution_clock::now();
    auto result = LongestCompound(words);
    auto end = chrono:: high_resolution_clock::now();

    chrono::duration<double, milli> processTime = end-start;

    cout<<"Longest compound word is: "<< result.first<<endl;
    cout<<"Second Longest compound word is: "<<result.second<<endl;
    cout<<"Time taken to process file: "<<processTime.count()<<"milliseconds"<<endl;

    return 0;
}