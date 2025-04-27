class Solution {
    public:
        vector<vector<int>> ans;
        void func(int i, vector<int>& nums, vector<int> temp, int target){
            if(i==nums.size() || target<0) return;
            if(target<=0){
                ans.push_back(temp);
                return;
            }
            temp.push_back(nums[i]);
            func(i,nums,temp,target-nums[i]);
            temp.pop_back();
            func(i+1,nums,temp,target);
            return;
    
        }
        vector<vector<int>> combinationSum(vector<int>& nums, int target) {
            vector<int> temp;
            func(0,nums,temp,target);
            return ans;
        }
    };