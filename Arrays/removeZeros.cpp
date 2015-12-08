#include <vector>
#include <string>
#include <sstream>
#include <iostream>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        if(n == 0) { return;}
        int numOccurences = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == 0){
                numOccurences++;
            }
        }
        //idea: 
        //traverse array from left to right
        // everytime, you see a nonzero element, 
        // insert it into counter of the array
        // increment counter
        int counter = 0, i=0;
        while(i <n && counter < n-numOccurences){
            if(nums[i] != 0){
                nums[counter] = nums[i];
                counter++;
            }
            i++;
        }
        while(counter < n){
            nums[counter] = 0;
            counter++;
        }
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
    cout << "Original Array: " << print(nums) << endl;
    s.moveZeroes(nums);
    cout << "Array:" << print(nums) << endl;
    cout << "------------------------------" << endl;

    nums.clear();
    for(int i=0; i<15; i++){
        nums.push_back(rand()%10+ 0);
    }
    cout << "Original Array: " << print(nums) << endl;
    s.moveZeroes(nums);
    cout << "Array:" << print(nums) << endl;
    cout << "------------------------------" << endl;
    
    nums.clear();
    nums.push_back(1);
    cout << "Original Array: " << print(nums) << endl;
    s.moveZeroes(nums);
    cout << "Array:" << print(nums) << endl;
    cout << "------------------------------" << endl;

    nums.clear();
    for(int i=0; i<5; i++){
        nums.push_back(0);
    }
    for(int i=0; i<5; i++){
        nums.push_back(12);
    }
    cout << "Original Array: " << print(nums) << endl;
    s.moveZeroes(nums);
    cout << "Array:" << print(nums) << endl;
    cout << "------------------------------" << endl;

    nums.clear();
    nums.push_back(4); nums.push_back(5); nums.push_back(0); nums.push_back(0); nums.push_back(4); nums.push_back(5);
    cout << "Original Array: " << print(nums) << endl;
    s.moveZeroes(nums);
    cout << "Array:" << print(nums) << endl;
    cout << "------------------------------" << endl;
}