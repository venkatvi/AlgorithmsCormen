#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
private:
   int getNeighbors(int i, int j, vector<vector<int>>& board){
     int neigbors = 0;
     int n = board.size(), m=board[0].size();
     neigbors+=(i>0)?board[i-1][j]:0;
     neigbors+=(j>0 && i>0)?board[i-1][j-1]:0;
     neigbors+=(j<m-1 && i>0)?board[i-1][j+1]:0;
     neigbors+=(i<n-1)?board[i+1][j]:0;
     neigbors+=(j>0 && i<n-1)?board[i+1][j-1]:0;
     neigbors+=(j<m-1 && i<n-1)?board[i+1][j+1]:0;
     neigbors+=(j>0)?board[i][j-1]:0;
     neigbors+=(j<n-1)?board[i][j+1]:0;
     return neigbors;
   }
public:
    void gameOfLife(vector<vector<int>>& board) {
        if(board.size() != 0){
          int n = board.size(), m = board[0].size();
          vector<int> temp(m, 0);
          vector<vector<int>> newState(n, temp);
          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                int neighbors = getNeighbors(i,j, board);
                newState[i][j] = ((board[i][j]==1) && (neighbors<2 || neighbors>3))?0:1;
                newState[i][j] = ((board[i][j]==0) && (neighbors==3))?1:0;
            }
          }
          for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                board[i][j] = newState[i][j];
            }
          }

        }
    }
};
string print(vector<int>& row){
  stringstream ss;
  ss << "{";
  for(auto x:row){
    ss << x << ",";
  }
  ss << "}";
  return ss.str();
}
string print(vector<vector<int>>& board){
  stringstream ss;
  ss << "{";
  for(auto x: board){
    ss << print(x) << "," << endl;
  }
  ss << "}";
  return ss.str();
}
int main(int argc, char** argv){
  Solution s;

  vector<int> row1 = {1, 0, 1, 0, 1, 0};
  vector<int> row2 = {0, 1, 0, 1, 0, 1};
  vector<int> row3 = {1, 0, 0, 0, 0, 0};
  vector<int> row4 = {0, 1, 0, 1, 0, 1};
  vector<int> row5 = {1, 0, 1, 0, 1, 0};
  vector<int> row6 = {0, 0, 0, 0, 0, 1};
  vector<vector<int>> board = {row1, row2, row3, row4, row5, row6};

  cout << "Before:" << endl;
  cout << print(board) << endl;
  for(int i=0; i<10; i++){
    s.gameOfLife(board);
    cout << print(board) << endl;
    cout << "----------------------------------------" << endl;
  }
}
