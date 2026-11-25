class Solution {
public:
    // use a hash set
    bool hasDuplicate(vector<int>& nums) {
        unordered_set <int> seen;

        for (int n: nums) {
            
            if (seen.contains(n)) {
                return true;
            }

            // insert the value into the set
            seen.insert(n);
        }

        return false;
    }
};