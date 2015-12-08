#include <iostream>
#include <string>
#include <limits.h>
#include <math.h>
using namespace std;
class Solution{
public:
  int myatoi(string s){
    long long num=0;
    int j=0;
    bool isNegative = false;
    for(auto x : s){
      if(j==0 && x == '-'){
        isNegative = true;
        continue;
      }
      if(j==0 && x == '+'){
        continue;
      }
      int val = x - '0';
      if(val < 0 || val > 9){
        return -1; // invalid char
      }
      num = (num*pow(10, (j >0)?1:0))+val;
      if(num > INT_MAX && !isNegative){
        return INT_MAX;
      }
      if(num > INT_MAX && isNegative){
        return INT_MIN;
      }
      j++;
    }
    return num*(isNegative?-1:1);
  }
};
int main(int argc, char** argv){
  Solution s;
  string str = "-121";
  int res = s.myatoi(str);
  cout << "Input: " << str << " Output: " << res << endl;
}
