#include <iostream>
#include <vector>
#include <sstream>
#include <string>
using namespace std;
class Solution{
public:
  int removeDuplicates(vector<char>& colors){
    int n = colors.size();
    int i=0, similarNeighbors = 0, prevIndex = -1;;
    while (i < n && prevIndex != i){
      prevIndex = i;
      while(colors[i] == ' ' && i < n){
        i++;
      }
      int neighbor = i+1;
      while(colors[neighbor] == ' ' && neighbor < n){
        neighbor++;
      }

      if(neighbor < n){
        //ensures both i and neighbors are  < n and nonspace
        if(colors[i] == colors[neighbor]){
          colors[i] = ' ';
          colors[neighbor] = ' ';
          similarNeighbors++;
          //retract to last known nonspace.
          i--;
          while(colors[i] == ' ' && i >=0){
            i--;
          }
          if (i<0){
            //if reached begining of the list, move right until you find the non-space color
            i++;
            while(colors[i] == ' ' && i <n){
              i++;
            }
          }
        }else{
          //move to next color
          i++;
        }
      }
    }
    if(similarNeighbors > 0){
      vector<char> newColors(n-(similarNeighbors*2));
      int i = 0;
      for(auto x : colors){
        if( x != ' '){
          newColors[i] = x;
          i++;
        }
      }
      colors = newColors;
    }
    return similarNeighbors;
  }
};
string print(vector<char>& colors){
  stringstream ss;
  ss << "{";
  for(auto x : colors){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
int main(int argc, char** argv){
  Solution s;
  vector<char> colors = {'Y', 'R', 'G', 'G', 'R', 'B', 'B', 'Y'};
  cout << "Input: " << print(colors);
  int pairsRemoved = s.removeDuplicates(colors);
  cout << " PairsRemoved:" << pairsRemoved << " Output:" << print(colors) << endl;


  vector<char> colors1 = {'Y', 'G', 'R', 'Y'};
  cout << "Input: " << print(colors1);
  pairsRemoved = s.removeDuplicates(colors1);
  cout << " PairsRemoved:" << pairsRemoved << " Output:" << print(colors1) << endl;
}
