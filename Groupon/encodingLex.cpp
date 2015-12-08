#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <map>
using namespace std;
string print(vector<string>& encodings){
  stringstream ss;
  ss << "{";
  for(auto x : encodings){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(map<int, int>& encodings){
  stringstream ss;
  ss << "{";
  for(auto x : encodings){
    ss << x.first << ":" << x.second << ",";
  }
  ss << "}";
  return ss.str();
}
class Solution {
private:
    int numDecodings(string s, int curIndex, string stringSoFar, map<int, int>& encodingMemo){
      if(curIndex >= s.length()) { return 1;}
      if(encodingMemo.find(curIndex) != encodingMemo.end()){
        return encodingMemo[curIndex];
      }else{
        int numEncodings = 0;
        int val = atoi(s.substr(curIndex, 1).c_str());
        char y = val + 64;
        if(val >=1 && val <=26){
          string mutatedStr  = stringSoFar;
          mutatedStr.push_back(y);

          //compute encodings ffrom curIndex+1;
          numEncodings = numDecodings(s, curIndex+1, stringSoFar, encodingMemo);

          if(curIndex < s.length()-1){
            val = atoi(s.substr(curIndex,2).c_str());
            y = val + 64;
            if(val >=1 && val <=26){
                // combinatorial encodings in its substring.
                numEncodings+= numDecodings(s, curIndex+2, stringSoFar, encodingMemo);
            }
          }
          encodingMemo.insert({curIndex, numEncodings});
        }

        return numEncodings;
      }
    }
public:
    int numDecodings(string s) {
      if(s.length() == 0){return 0;}
      map<int, int> encodingMemo;
      return numDecodings(s, 0, "", encodingMemo);
    }
};
int main(int argc, char** argv){
  Solution s;
  //string str = "4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948";
  string str = "0";
  int res = s.numDecodings(str);
  cout << "Input: " << str << " Res:" << res << endl;
}
