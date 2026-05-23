int longestUniqueSubstr(string &s) {
        unordered_map<char, int> mp;
    int l = 0, r = 0;
    int longstr = 0;
    int n = s.length();
    
    while (r < n) {
        char current = s[r];
        
        if (mp.find(current) != mp.end() && mp[current] >= l) {
            l = mp[current] + 1;
        }
        
        mp[current] = r;
        longstr = max(longstr, r - l + 1);
        r++;
    }
        return longstr;
    }