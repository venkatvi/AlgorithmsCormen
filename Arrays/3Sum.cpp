#include <vector>
#include <map>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <set>
using namespace std;
class Solution {
public:
	string print(vector<int>& tuple){
		stringstream ss;
		ss << "{";
		for(auto x : tuple){
			ss << x << ",";
		}
		ss << "}";
		return ss.str();
	}
    void print(set<vector<int>>& tuples){
        stringstream ss;
        ss << "{";
        for(auto x : tuples){
            ss <<  print(x) << ",";
        }
        ss << "}";
        cout << "Tuples: " << ss.str() << endl;
    }
    void threeSum(vector<int>& nums) {
    	map<int, set<vector<int>>> twoSums;
        for(int i=0; i<nums.size(); i++){
        	for(int j=i+1; j < nums.size(); j++){
        		int twoSum = nums[i] + nums[j];
        		vector<int> tuple = {nums[i], nums[j]};
        		if(twoSums.find(twoSum) != twoSums.end()){
        			set<vector<int>> tuples = {tuple}; 
        			twoSums.insert({twoSum, tuples});
        		}else{
        			twoSums[twoSum].push_back(tuple);
        		}
        	}
        }
        set<vector<int>> uniqueTuples;
        for(int i=0; i<nums.size(); i++){
        	if(twoSums.find(nums[i]*-1)  != twoSums.end()){
                set<vector<int>> tuples = twoSums[nums[i]*-1];
                for(auto x : tuples){
    				vector<int>& tuple = x;
    				tuple.push_back(nums[i]);
    				sort(tuple.begin(), tuple.end());
    				uniqueTuples.insert(tuple);
    			}
        	}
        }
        print(uniqueTuples);
    }
};
int main(int argc, char** argv){
	Solution s;

    vector<int> nums = { -1, 0, 1, 2, -1, 4};
    cout << "Input: " << s.print(nums) << " "; 
    s.threeSum(nums);
    cout << "-----------------------------------" << endl;

    vector<int> nums1 = {0, 0, 0, 2, -1, -1, 4, -4};
    cout << "Input: " << s.print(nums1) << " "; 
    s.threeSum(nums1);
    cout << "-----------------------------------" << endl;

    vector<int> nums2 = {0, 1, 2, 43};
    cout << "Input: " << s.print(nums2) << " "; 
    s.threeSum(nums2);
    cout << "-----------------------------------" << endl;

    vector<int> nums3 = {0, -1, -2, -3};
    cout << "Input: " << s.print(nums3) << " "; 
    s.threeSum(nums3);
    cout << "-----------------------------------" << endl;

    vector<int> nums4 = {};
    cout << "Input: " << s.print(nums4) << " "; 
    s.threeSum(nums4);
    cout << "-----------------------------------" << endl;

    vector<int> nums5 = {-3,14,-10,-1,12,13,-3,2,-6,4,13,7,-8,4,0,-13,11,-4,7,0,4,-3,12,11,5,-14,-8,8,3,-1,-8,-15,-2,-11,-9,-12,9,3,5,-11,-8,3,3,-9,-15,-12,-15,3,-9,0,-12,3,12,-14,-1,-6,-13,-2,-13,-3,12,-14,-3,-13,-9,3,-10,-15,13,2,11,13,-9,-1,11,13,-6,4,1,1,-11,5,-11,8,-2,-5,-12,-8,8,-10,4,-3,-8,-14,-1,-10,-4,-3,12,-14,14,9,6,12,-15,3,10,-13,-8,-11,3,-4,1,-1};
    cout << "Input: " << s.print(nums5) << " "; 
    s.threeSum(nums5);
    cout << "-----------------------------------" << endl;
}