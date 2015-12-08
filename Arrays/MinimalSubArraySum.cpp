#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;
class Solution {
public:
    int minSubArrayLen1(int s, vector<int>& nums) {
    	int n = nums.size();
    	if(n ==0){ return 0;}
    	if(s <= 0) { return 0;}

    	int minLen = n;
    	for(int i=0; i<n; i++){
    		int sumSoFar = 0;
    		for(int j=i; j<n; j++){
    			int len = j-i+1;
    			sumSoFar+= nums[j];
    			if(sumSoFar >= s){
    				if (minLen > len){
    					minLen = len;
    					break;
    				}
    			}
    		}
    	}
    	return minLen;
    }
    int minSubArrayLen(int s, vector<int>& nums){
    	int n = nums.size();
    	if (n==0){return 0;}
    	if (s <=0){return 0;}
    	int minLen = n;

    	bool isSumFound = false;
    	int sumSoFar = 0;
    	int end =0, start=0;
    	while(end < n){
    		sumSoFar+=nums[end++];
    		int len = end-start;
    		
    		if(sumSoFar >= s){
    			isSumFound = true;
    			if(len < minLen){
    				minLen = len;
    			}
				while(start < end && sumSoFar >= s){
					sumSoFar -= nums[start++];
					len--;
				}
				if(len+1 < minLen){
					minLen = len+1;
				}
			}
    	}
    	if(isSumFound){
    		return minLen;
    	}else{
    		return 0;
    	}
    }
};
string print(std::vector<int>& nums){
	stringstream ss;
	ss << "{";
	for(auto x: nums){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	//TestCases:
	vector<int> nums={};
	int len = s.minSubArrayLen(1, nums);
	cout << "Array:" << print(nums) << " S: " << 1 << " Len:" << len << endl;

	nums.clear();
	vector<int> nums1 = {9, 23, 1, 1, 0};
	len = s.minSubArrayLen(1, nums1);
	cout << "Array:" << print(nums1) << " S: " << 1 << " Len:" << len << endl;

	vector<int> nums2 = {9, 23, 1, 1, 2};
	len = s.minSubArrayLen(2, nums2);
	cout << "Array:" << print(nums2) << " S: " << 2 << " Len:" << len << endl;

	vector<int> nums3 = {9, 23, 1, 1, 0, 0, 0, 0, 1, 3};
	len = s.minSubArrayLen(3, nums3);
	cout << "Array:" << print(nums3) << " S: " << 3 << " Len:" << len << endl;

	vector<int> nums4 = {0, 0, 1, 1, 1, 2};
	len = s.minSubArrayLen(3, nums4);
	cout << "Array:" << print(nums4) << " S: " << 3 << " Len:" << len << endl;

	vector<int> nums5 = {1, 4, 4};
	len = s.minSubArrayLen(4, nums5);
	cout << "Array:" << print(nums5) << " S: " << 4 << " Len:" << len << endl;

}