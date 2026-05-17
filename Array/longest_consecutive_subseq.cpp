 int longestConsecutive(vector<int>& arr) {
        // Your code here
        unordered_set<int> st(arr.begin(),arr.end());
        int lngsub=0;
        for(int i=0; i<arr.size(); i++){
            int num=arr[i];
            if(st.find(num-1)==st.end()){
                int currnum=num;
                int currstk=1;
                while(st.find(currnum+1)!=st.end()){
                    currnum++;
                    currstk++;
                }
                lngsub=max(lngsub,currstk);
            }
        }
        return lngsub;
    }