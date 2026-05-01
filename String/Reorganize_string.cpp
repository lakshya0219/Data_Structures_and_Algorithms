
// https://leetcode.com/problems/reorganize-string/?utm=codolio

class Solution {
public:
    string reorganizeString(string s) {
        if(s.length()==0)
        return "";
        int freq[26]={0};
        for(char ch: s)
        {
            freq[ch-'a']++;
        }
        char MaxChar=' ';
        int maxFreq=0;
        for(int i=0; i<26; i++)
        {
            if(freq[i]>maxFreq)
            {
                maxFreq=freq[i];
                MaxChar='a'+i;
            }
        }
         if (maxFreq > (s.length() + 1) / 2) {
            return "";
        }
        int index=0;
        string res(s.length(),' ');
        while(maxFreq>0)
        {
            res[index]=MaxChar;
            freq[MaxChar - 'a']--;
            index+=2;
            maxFreq--;
        }
         for(int i=0; i<26; i++)
         {
           if(freq[i]<=0)
           continue;
           while(freq[i]>0)
           {
            if(index>=s.length())
            index=1;
             res[index]='a'+i;
             index+=2;
             freq[i]--;
           }
         }
         return res;
    }
};