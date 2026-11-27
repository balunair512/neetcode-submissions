class Solution {
public:
    
    // min heap
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // iterate through nums with a hashmap
        // num, count
        unordered_map <int, int> counts;

        for (int n: nums) {
            counts[n]++;
        }


        // create a min heap
        // add to the heap counts, num
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

        // iterate through the hash map
        unordered_map <int,int>::iterator it;
        for (it=counts.begin(); it != counts.end(); it++) {
            int num = it->first; int cnt = it->second;
            heap.push({cnt,num});
            // Don't allow the heap to get larger than K
            if(heap.size() > k) {
                heap.pop();
            }
        }

        vector<int> ans{};
        while(!heap.empty()) {
            pair<int,int> i = heap.top();
            ans.push_back(i.second);
            heap.pop();
        }

        return ans;
    }

    /*
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

    }*/
};
