class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ranges;
        stringstream ss; 
        int start = nums[0], end = nums[0], prev = nums[0];
        for(int i=0; i<nums.size(); i++){
            if(nums[i] ==  (prev +1)){
                end = nums[i];
            }else{
                ss.str("");
                ss << start << "->" << end;
                ranges.push_back(ss.str());
                
                start= nums[i];
                prev = start;
                
            }
        }
        
    }
};