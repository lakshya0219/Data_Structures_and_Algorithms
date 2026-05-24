import java.util.*;
class Solution {

    // Function to return length of longest subsequence of consecutive integers.
    public int longestConsecutive(int[] arr) {
        HashSet<Integer> st = new HashSet<>();
        for(int num:arr){
            st.add(num);
        }
        int longeststk=0;
        for(int i=0; i<arr.length; i++){
            int num = arr[i];
            if(!st.contains(num-1)){
                int currstk=1;
                int currnum=num;
                while(st.contains(currnum+1)){
                    currstk++;
                    currnum++;
                }
                longeststk = Math.max(longeststk,currstk);
            }
        }
        return longeststk;
    }
}