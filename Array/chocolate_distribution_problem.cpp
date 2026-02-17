int findMinDiff(vector<int>& arr, int m) {
        // code here
        sort(arr.begin(),arr.end());
        int l=0,r=m-1,minmax=INT_MAX;
        while(r<arr.size())
        {
            int diff = arr[r]-arr[l];
            minmax=min(minmax,diff);
            r++;
            l++;
        }
        return minmax;
    }
    //TC = O(n logn)
    //SC= O(1)