#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
private:
	void findThreeSumTuples(vector<vector<int>>& allTuples, vector<int>& candidates, vector<int>& nums,  int index, int curSum){

		if(nums[index]+curSum == 0 && candidates.size() == 2){
			vector<int> temp = candidates;
			candidates.push_back(nums[index]);
			allTuples.push_back(candidates);
			findThreeSumTuples(allTuples, temp, nums, index+1, curSum);
		}else{
			candidates.push_back(nums[index]);
			findThreeSumTuples(allTuples, candidates, nums, index+1, curSum + nums[index]);
			candidates.pop_back();
			findThreeSumTuples(allTuples, candidates, nums, index+1, curSum);
		}
	}
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    	vector<vector<int>> allTuples;
    	vector<int> candidates;
    	findThreeSumTuples(allTuples, candidates, nums, 0, 0);
    	return allTuples;
    }
};
string print(vector<int>& nums){
    stringstream ss;
    ss << "[";
    for(auto x: nums){
        ss << x << ",";
    }
    ss << "]";
    return ss.str();
}
string print(vector<vector<int>>& nums){
    stringstream ss;
    ss << "{";
    for(auto x: nums){
        ss << print(x) << endl;
    }
    ss << "}";
    return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	vector<int> nums = {-1, 0, 1, 2, -1, -4};
	vector<vector<int>> allTuples = s.threeSum(nums);

	cout << "Input: " << print(nums) << " Output:" << print(allTuples) << endl;;
}