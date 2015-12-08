#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <random>
#include <ctime>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
    	int n = nums.size();
        if(n == 0) { return 0; }
        int numOccurences = 0;
        int firstIndex = 0;
        int i = 0;
        for(;i<nums.size(); i++){
        	if(nums[i] == val){
        		firstIndex = i;
        		numOccurences++;
        	}
        }
        i = 0;
        int j = n-1; 
        while(i<n-numOccurences){
        	if(nums[i] == val){
        		if(nums[j] != val){
        			nums[i] = nums[i] + nums[j];
        			nums[j] = nums[i] - nums[j];
        			nums[i] = nums[i] - nums[j];
        			
        		}
        		j--;
        	}else{
        		i++;
        	}
        }
        return n-numOccurences;
    }
};
string print(vector<int>& nums){
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

	srand(time(0));
	vector<int> nums = {};
	int val = 0;
	int newLength = s.removeElement(nums, val);
	cout << "Array: size: " << nums.size() << " :" << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

	nums.clear();
	for(int i=0; i<15; i++){
		nums.push_back(rand()%10+ 0);
	}
	val = 0;
	newLength = s.removeElement(nums,val);
	cout << "Array: size: " << nums.size() << " :" << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

	val = 13;
	newLength = s.removeElement(nums,val);
	cout << "Array: size: " << nums.size() << " :"  << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

	nums.clear();
	nums.push_back(1);
	val = 1;
	newLength = s.removeElement(nums,val);
	cout << "Array: size: " << nums.size() << " :"  << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

	nums.clear();
	for(int i=0; i<10; i++){
		nums.push_back(1);
	}
	val = 1;
	newLength = s.removeElement(nums,val);
	cout << "Array: size: " << nums.size() << " :"  << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

	nums.clear();
	nums.push_back(4); nums.push_back(5);
	val = 4;

	newLength = s.removeElement(nums,val);
	cout << "Array: size: " << nums.size() << " :"  << print(nums) << " Val to remove:" << val << " NewLength:" << newLength << endl;

}