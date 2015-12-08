#include <iostream>
#include <vector>
#include <sstream>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
    	if(nums.size() <= 1) { return nums.size();}
    	int i=1, j=0;
    	while(i<nums.size()){
        	if(nums[j] != nums[i]){
				j++;
				nums[j] = nums[i];
        	}
        	i++;
        }
        return j+1;
    }
};
string print(vector<int>& words){
    stringstream ss;
    ss << "{";
    for(auto& x : words){
        ss << x << ",";
    }
    ss << "}";
    return ss.str();
}
int main(int argc, char** argv){
	Solution s;
	vector<int> nums = { 1, 1, 1, 1};
	int newLength = s.removeDuplicates(nums);
	cout << "Vector:" << print(nums) << " newLength:" << newLength << endl;

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	newLength = s.removeDuplicates(nums);
	cout << "Vector:" << print(nums) << " newLength:" << newLength << endl;

	nums.clear();
	newLength = s.removeDuplicates(nums);
	cout << "Vector:" << print(nums) << " newLength:" << newLength << endl;	

	nums.clear();
	nums.push_back(1);
	newLength = s.removeDuplicates(nums);
	cout << "Vector:" << print(nums) << " newLength:" << newLength << endl;	

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	nums.push_back(2);
	nums.push_back(3);
	nums.push_back(3);
	nums.push_back(4);
	nums.push_back(4);
	nums.push_back(5);
	newLength = s.removeDuplicates(nums);
	cout << "Vector:" << print(nums) << " newLength:" << newLength << endl;	
}