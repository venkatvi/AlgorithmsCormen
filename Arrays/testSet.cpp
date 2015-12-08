#include <set>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char** argv){
	
	vector<int> v1 = {1,2,3};
	vector<int> v2 = {1,2,3};
	set<vector<int>> vecSets = {v1, v2};

	cout << vecSets.size() << endl;
}