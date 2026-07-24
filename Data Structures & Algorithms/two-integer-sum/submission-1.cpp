
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tracker;
        for (int i = 0; i< nums.size(); i++){
            int complement = target - nums[i];

            if (tracker.find(complement) != tracker.end()){
                return {tracker[complement], i };
            }

            tracker[nums[i]] = i;
        }

    }
};
