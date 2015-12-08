#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        if(word1 == word2){
            return 0;
        }
        if(words.size() == 0){
            return -1;
        }
        int i1 = 0, i2 = 0;
        for(int i=0; i<words.size(); i++){
            if(word1 == words[i]){
                if(abs(i-i2) < abs(i1-i2)){
                    i1 = i;
                }
            }
            if(word2 == words[i]){
                if(abs(i-i1) < abs(i1-i2)){
                    i2 = i;
                }
            }
        }
        if(i1 == -1 || i2 == -1){
            return -1;
        }
        return abs(i1-i2);
    }
};
string print(vector<string>& words){
    stringstream ss;
    ss << "{";
    for(auto& x : words){
        ss << x << ",";
    }
    ss << "}";
    return ss.str();
}
int main(int argc, char** argv){
    Solution s;
    vector<string> testCase1 = {"practice", "makes", "man", "man", "perfect", "prefect", "song", "adress", "alter"};
    string s1 = "man", s2 = "alter";
    int result = s.shortestDistance(testCase1, s1, s2);
    cout << "Strings: " << print(testCase1) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;

    s1 = "makes", s2 = "practice";
    result = s.shortestDistance(testCase1, s1, s2);
    cout << "Strings: " << print(testCase1) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;

    s1 = "man", s2 = "perfect";
    result = s.shortestDistance(testCase1, s1, s2);
    cout << "Strings: " << print(testCase1) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;

    vector<string> testCase2 = {"Only one word"};
    s1 = "Only one word", s2 = "Only one word";
    result = s.shortestDistance(testCase2, s1, s2);
    cout << "Strings: " << print(testCase2) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;

    vector<string> testCase3 = {}; // nowords
    result = s.shortestDistance(testCase3, s1, s2);
    cout << "Strings: " << print(testCase3) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;

    vector<string> testCase4 = {"soft", "soft", "hard", "hard"};
    s1 = "soft", s2 = "hard";
    result = s.shortestDistance(testCase4, s1, s2);
    cout << "Strings: " << print(testCase4) << "S1: " << s1  << " S2:" << s2 << " Result:" << result << endl;


}