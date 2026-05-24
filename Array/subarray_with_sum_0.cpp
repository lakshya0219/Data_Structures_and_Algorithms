class Solution {
  public:
    int findSubarray(vector<int> &arr) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int count=0, prefixsum=0;
        for(int i=0; i<arr.size(); i++){
            prefixsum+= arr[i];
            if(mp.find(prefixsum)!=mp.end()){
                count+= mp[prefixsum];
            }
            mp[prefixsum]++;
        }
        return count;
    }
};