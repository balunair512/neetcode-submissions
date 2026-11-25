class Solution {
public:
    /*bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        return s==t;
    }*/
    
    // two hashmap solution
    bool isAnagram(string s, string t) {
        if(s.length() != t.length())
            return false;
        
        unordered_map <char, int> chars_s;
        unordered_map <char, int> chars_t;

        // the strings are equal in length
        for (int i=0; i < s.length(); i++) {
            chars_s[s[i]]++;
            chars_t[t[i]]++;
        }

        return chars_s == chars_t;

    }
};
