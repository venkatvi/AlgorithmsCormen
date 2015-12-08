#include <iostream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
	bool findIfStringExists(int startPos, vector<int>& ancestors, vector<vector<char>>& board, string word, int index){
		ancestors[startPos] = 1;
		int m=board.size(), n=board[0].size();
		
		vector<int>neigbors;
		int i = startPos/n;
		int j = startPos-(n*i);
		if(i >0){
			int pos = (i-1)*n +j;
			if(ancestors[pos] == 0){
				neigbors.push_back(pos);
			}
		}	
		if(j >0){
			int pos = i*n +j-1;
			if(ancestors[pos] == 0){
				neigbors.push_back(pos);
			}
		}
		
		if( i<m-1){
			int pos = (i+1)*n +j;
			if(ancestors[pos] == 0){
				neigbors.push_back(pos);
			}
		}
		if(j <n-1){
			int pos = i*n +j+1;
			if(ancestors[pos] == 0){
				neigbors.push_back(pos);
			}
		}
		
		for(auto x : neigbors){
			int pos = x;
			int i = pos/n;
			int j = pos-(n*i);
			if(board[i][j] == word[index]){
				if(index == word.length() -1){
					ancestors[x] = 1;
					return true;
				}
				startPos = pos;
				bool res = findIfStringExists(startPos, ancestors, board, word, index+1 );
				if(res){
					return true;
				}else{
					ancestors[x] = 0;
				}
			}
			
		}
		return false;
	}
    bool exist(vector<vector<char>>& board, string word) {
    	if(word.length() == 0) { return true;}
    	int m = board.size();
    	int n = board[0].size();

    	vector<int> startPos; 
		for(int i=0; i<m; i++){
			for(int j=0; j<n; j++){
				if(board[i][j] == word[0]){
					startPos.push_back(i*n + j);
				}
			}
		}	        
		if(word.length() == 1 && startPos.size() > 0) { return true;}

		for(auto x : startPos){
			//for each startPos get all neighbours
			vector<int> ancestors(m*n, 0);
			bool res = findIfStringExists(x, ancestors, board, word, 1);
			if(res){
				 return true;
			}
		}
		return false;
    }
    string print(vector<int>& pos){
    	stringstream ss;
    	ss << "[";
    	for(auto x:pos){
    		ss << x << ",";
    	}
    	ss << "]";
    	return ss.str();
    }
    string print(vector<char>& pos){
    	stringstream ss;
    	ss << "[";
    	for(auto x:pos){
    		ss << x << ",";
    	}
    	ss << "]";
    	return ss.str();	
    }
    string print(vector<vector<int>>& poss){
    	stringstream ss;
    	ss << "[";
    	for(auto x : poss){
    		ss << print(x) << "," << endl;;
    	}
    	ss << "]";
		return ss.str();
    }
    string print(vector<vector<char>>& poss){
    	stringstream ss;
    	ss << "[";
    	for(auto x : poss){
    		ss << print(x) << "," << endl;;
    	}
    	ss << "]";
		return ss.str();
    }
};
int main(int argc, char** argv){
	Solution s;
	
	vector<char> r1 = {'a', 'b', 'c', 'e'};
	vector<char> r2 = {'s', 'f', 'c', 's'};
	vector<char> r3 = {'a', 'd', 'e', 'e'};
	vector<vector<char>> board = {r1, r2, r3};
	
	string str = "abcced";
	bool res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	str = "see";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;
	
	str = "abcb";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	board[0][2] = 'e';
	str = "see";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;
	

	str = "a";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	str = "ab";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;
	
	str = "";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	str = "z";
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	str = "a";
	board.clear();
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;

	board.clear();
	vector<char> r11 ={'a', 'a', 'a', 'a'};
	vector<char> r12 ={'a', 'a', 'a', 'a'};
	vector<char> r13 ={'a', 'a', 'a', 'a'};
	vector<char> r14 ={'a', 'a', 'a', 'a'};
	vector<char> r15 ={'a', 'a', 'a', 'b'};
	board.push_back(r11);
	board.push_back(r12); board.push_back(r13); board.push_back(r14); board.push_back(r15);
	str = "aaaaaaaaaaaaaaaaaaaa";
	cout << str << " length: " << str.length() << endl;
	res = s.exist(board, str);
	cout << "Board:" << s.print(board) << " string:" << str << " res:" << res << endl;
	cout << "----------------------------------------------" << endl;	
}