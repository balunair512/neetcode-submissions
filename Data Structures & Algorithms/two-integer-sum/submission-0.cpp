class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // storing value, index
        unordered_map <int,int> dic;

        for (int i=0; i < nums.size(); i++) {
            if(dic.contains(target - nums[i])) {
                return {dic[target-nums[i]], i};
            }

            // insert the number into the hashmap with its index
            dic[nums[i]] = i;


        }

        // this shouldnt be possible
        return {-1,-1};
    }
};
