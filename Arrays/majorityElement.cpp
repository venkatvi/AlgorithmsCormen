#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) {
    	if(nums.size() == 0){return -1;}  
    	map<int, int> counter;
    	int maxOccurences = 0;
    	int median = nums[0];
    	for(auto x : nums){
    		if (counter.find(x) != counter.end()){
    			counter[x]++;
    		}else{
    			counter.insert({x, 1});
    		}
    		if(maxOccurences < counter[x]){
    			maxOccurences = counter[x];
    			median = x;
    		}
    	}
    	return median;
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
	vector<int> nums = { 1, 2, 2,2,2,2,2,2,2,2,2,2,2,2,2,2,23, 2};
	int median = s.majorityElement(nums);
	cout << "Vector:" << print(nums) << " majorityElement:" << median << endl;

	nums.clear();
	nums.push_back(1);
	median = s.majorityElement(nums);
	cout << "Vector:" << print(nums) << " majorityElement:" << median << endl;	

	nums.clear();
	nums.push_back(1);
	nums.push_back(2);
	median = s.majorityElement(nums);
	cout << "Vector:" << print(nums) << " majorityElement:" << median << endl;	

	nums.clear();
	median = s.majorityElement(nums);
	cout << "Vector:" << print(nums) << " majorityElement:" << median << endl;	


}