import java.util.*;
class Solution {
    int maxProduct(int[] arr) {
        // code here
        int pre=1;
        int suff=1;
        int ans = Integer.MIN_VALUE;
        int n = arr.length;
        for(int i=0; i<n; i++){
            if(pre==0)
            pre=1;
            if(suff==0)
            suff=1;
            pre=pre*arr[i];
            suff=suff*arr[n-1-i];
            ans=Math.max(ans,Math.max(pre,suff));
        }
        return ans;
    }
}