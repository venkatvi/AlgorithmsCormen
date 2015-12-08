#include <iostream>
#include <string>
using namespace std;
class Solution{
private:
  string trim(string& str){
    auto strbegin = str.find_first_not_of(" ");
    if(strbegin == string::npos){
      return ""; //no content
    }
    auto strend = str.find_last_not_of(" ");
    auto range = strend - strbegin + 1;
    return str.substr(strbegin, range);
  }
  string removeConsecutiveSpaces(string& input){
    int n = input.length();
    char prev = input[n-1];
    int i = n-2, j=i;
    while(i > -1){
      if(input[i] == ' ' && input[i] == prev){
        j--;
      }
      if(i > j){
        input[i] = input[j];
      }
      prev = input[i];
      i--;
      j--;
    }
    return input.substr(i+1);
  }
public:
  void reverseWordByWord(string& input){
    input = trim(input);

    if(input.length() > 0){
      input = removeConsecutiveSpaces(input);

      reverse(input.begin(), input.end());

      int start = 0;
      int lastSpaceIndex = -1;
      for(int i=1; i<input.length(); i++){
        if(input[i] == ' '){
            lastSpaceIndex = i;
            reverse(input.begin()+start, input.begin()+i);
            start = i+1;
        }
      }
      reverse(input.begin()+lastSpaceIndex+1, input.end());
      cout << "ReversedString: " << input << endl;
    }
  }
};
int main(int argc, char** argv){
  Solution s;
  string str = "nospaces";
  s.reverseWordByWord(str);

  str = "       "; //allspaces
  s.reverseWordByWord(str);

  str = " leadingSpace";
  s.reverseWordByWord(str);

  str = "trailingSpace ";
  s.reverseWordByWord(str);

  str = "This is a string";
  s.reverseWordByWord(str);

  str = "Consecutive  spaces";
  s.reverseWordByWord(str);
}
