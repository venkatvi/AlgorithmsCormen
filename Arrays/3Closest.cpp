class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
    	map<int, vector<vector<int>>> twoSums;
        for(int i=0; i<nums.size(); i++){
        	for(j=i+1; j < nums.size(); j++){
        		int twoSum = nums[i] + nums[j];
        		vector<int> tuple = {nums[i], nums[j]};
        		if(twoSums.find(twoSum) != twoSums.end()){
        			vector<vector<int>> tuples; 
        			tuples.push_back(tuple);
        			twoSums.insert({twoSum, tuples});
        		}else{
        			twoSums[twoSum].push_back(tuple);
        		}
        	}
        }
    }
};