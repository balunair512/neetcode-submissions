class Solution {
public:
    
    // Brute Force
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // iterate through nums with a hashmap
        // num, count
        unordered_map <int, int> counts;

        for (int n: nums) {
            counts[n]++;
        }
        
        vector <int> ans;
        while(k > 0) {
            int max_freq = 0;
            int max_num = 0;
            unordered_map <int, int>::iterator it;
            for (it=counts.begin(); it != counts.end(); it++) {
                int num = it->first; int cnt = it->second;

                if (cnt > max_freq) {
                    max_freq = cnt;
                    max_num = num;
                }
            }

            // we have the max num
            // erase it from the hash map and add it to the ans vector
            counts.erase(max_num);
            ans.push_back(max_num);
            k--;
        }

        return ans;

    }
};
