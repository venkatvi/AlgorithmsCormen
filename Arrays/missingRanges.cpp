
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
private:
	void insertMissingRange(vector<string>& missingRanges, int mstart, int mend){
		stringstream ss;
		if(mstart == mend){
			ss << mstart;
		}else{
			if(mstart < mend){
				ss << mstart << "->" << mend;
			}
		}
		if(!ss.str().empty()){
			missingRanges.push_back(ss.str());
		}
	}
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
    	vector<string> missingRanges;
    	stringstream ss;
        
        if(nums.size() == 0 ) { 
        	if (lower == upper){
        		ss << lower;
        	}else{
        		ss << lower << "->" << upper;
        	}
        	missingRanges.push_back(ss.str());
        	return missingRanges;
        }
        int start, prev, endd, mstart, mend;
        bool rangeLookUpStarted = false;
        int i = 0;
        while (i < nums.size() && nums[i] <= upper){
        	if(nums[i] < lower){
        		i++;
        		continue;
        	}else{
        		if(!rangeLookUpStarted){
        			rangeLookUpStarted = true;
        			start = nums[i], prev = start, endd = start;
        			if(start > lower){
        				mstart = lower, mend = start-1;
        				insertMissingRange(missingRanges, mstart, mend);
        			}
        		}else{
        			if(nums[i] == (prev+1)){
        				endd = nums[i];
        				prev = nums[i];
        			}else{
        				mstart = endd + 1, mend = nums[i] -1;
        				insertMissingRange(missingRanges, mstart, mend);
        				start = nums[i];
        				prev = nums[i];
        				endd = nums[i];
        			}
        		}
        		i++;
        	}
        }
        mstart = endd + 1, mend = upper;
    	insertMissingRange(missingRanges, mstart, mend);
        return missingRanges;
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
	int lower = 4, upper = 11;
	vector<string> ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;

	vector<int> temp = {1,2,3, 5, 6,7, 11,12, 31,32, 34, 45,46, 47,48, 56, 97};
	nums = temp;
	lower = 6, upper = 110;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) <<  " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;

	nums.clear();
	lower = 0, upper = 10;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;


	vector<int> temp1 = {1, 3,4,5,6,7,8};
	nums.clear();
	nums = temp1;
	lower = 3, upper = 8;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;

	vector<int> temp2 = {1,3,4,5,6,7,8};
	nums.clear();
	nums = temp1;
	lower = 1, upper = 1;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;

	vector<int> temp3 = {-1};
	nums.clear();
	nums = temp3;
	lower = -2, upper = -1;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;

	vector<int> temp4 = {1,3,4,5,6,7,8};
	nums.clear();
	nums = temp4;
	lower = 0, upper = 9;
	ranges = s.findMissingRanges(nums, lower, upper);
	cout << "Nums: " << print(nums) << " limits: [" << lower << "," << upper << "] Ranges:" << print(ranges) << endl;
}