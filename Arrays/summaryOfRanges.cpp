
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ranges;
		stringstream ss;
    	if(nums.size() == 0) { return ranges;}
    	int start = nums[0], prev = start, endd=start;    
    	for(int i=1; i<nums.size(); i++){
    		if(nums[i] == (prev+1)){
    			endd = nums[i];
    			prev = nums[i];
    		}else{
    			ss.str("");
    			if(start != endd){
    				ss << start << "->" << endd;
    			}else{
    				ss << start;
    			}
    			ranges.push_back(ss.str());
    			start = nums[i];
    			prev = start;
    			endd = nums[i];
    		}
    	}
    	ss.str("");
    	if(start != endd){
    		ss << start << "->" << endd;
    	}else{
    		ss << start;
    	}
    	ranges.push_back(ss.str());
    	return ranges;
    }
};
string print(vector<string>& ranges){
	stringstream ss;
	ss << "{";
	for(auto x : ranges){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
string print(vector<int> nums){
	stringstream ss;
	ss << "{";
	for(auto x : nums){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();

}
int main(int argc, char** argv){
	Solution s;
	//testcases
	vector<int> nums = {0, 1, 2, 3, 4, 5, 6, 10};
	vector<string> ranges = s.summaryRanges(nums);
	cout << "Nums: " << print(nums) << " Ranges:" << print(ranges) << endl;

	vector<int> temp = {1,2,3, 5, 6,7, 11};
	nums = temp;
	ranges = s.summaryRanges(nums);
	cout << "Nums: " << print(nums) << " Ranges:" << print(ranges) << endl;

	nums.clear();
	ranges = s.summaryRanges(nums);
	cout << "Nums: " << print(nums) << " Ranges:" << print(ranges) << endl;


	vector<int> temp1 = {1, 3};
	nums.clear();
	nums = temp1;
	ranges = s.summaryRanges(nums);
	cout << "Nums: " << print(nums) << " Ranges:" << print(ranges) << endl;


}