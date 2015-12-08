#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
    	int n = nums.size();
        if (n == 0){ return 0;}
        if (s < 0) { return 0;}
        if (s == 0) { return 1;}
        
        bool isSumFound = false;
        int minLen = n;
        int sumSoFar = 0, end = 0, start = end;
        while(end < n){
        	sumSoFar += nums[end++];
        	if(sumSoFar >= s){
        		cout << "Sum found:" << start << ":" << end << endl;
        		isSumFound = true;
        		if(end-start < minLen){
        			minLen = end-start;
        			while(start < end && sumSoFar >= s){
        				sumSoFar -=nums[start++];
        				minLen--;
        			}
        		}
        	}
        }
        if(!isSumFound){
        	return 0;
        }
        return minLen;
    }
};
string print(vector<int>& nums){
	stringstream ss;
	ss << "{";
	for(auto x :nums){
		ss << x << ",";
	}
	ss << "}";
	return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	
	vector<int> nums={};
	int minLen = s.minSubArrayLen(0, nums);
	cout << "Array:" << print(nums) << " s:" << 0 << " minLen:" << minLen << endl;

	vector<int> nums1 = {0, 0, 0, 0, 0, 0};
	minLen = s.minSubArrayLen(1, nums1);
	cout << "Array:" << print(nums1) << " s:" << 1 << " minLen:" << minLen << endl;

	vector<int> nums2 = {1,2,3,4,0};
	minLen = s.minSubArrayLen(0, nums2);
	cout << "Array:" << print(nums2) << " s:" << 0 << " minLen:" << minLen << endl;

	vector<int> nums3 = {1, 1, 1, 0, 0, 3};
	minLen = s.minSubArrayLen(3, nums3);
	cout << "Array:" << print(nums3) << " s:" << 3 << " minLen:" << minLen << endl;

	vector<int> nums5 = {1, 1, 1, 1, 0, 0, 2, 2, 3, 1, 4};
	minLen = s.minSubArrayLen(4, nums5);
	cout << "Array:" << print(nums5) << " s:" << 4 << " minLen:" << minLen << endl;

	vector<int> nums4 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	minLen = s.minSubArrayLen(55, nums4);
	cout << "Array:" << print(nums4) << " s:" << 55 << " minLen:" << minLen << endl;
}