class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
     // we take two pointers from left and right,
     vector<int> result(nums.size()); 
     for (int i = 0; i<nums.size(); i++){

        int left = 0;
        int right = nums.size()-1;
        int product = 1;

        while (left < i){
            product = nums[left] * product;
            left ++;
        };

        while (right > i){
            product = nums[right] * product;
            right --;

        };
        result[i] = product;
     };

     return result;
    };
};