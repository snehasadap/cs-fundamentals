class Solution {
public:
    int numberOfSubstrings(string s) {
        //we need to find the first occurrence of abc. then, after this, it is safe to assume that there is going to be a repeat for one of these three characters.
        //once we find first occurence of abc, that will count as our first string
        //we need to count the window as a whole, and count the windows inside
        //so for example, in abcabc
        //include a hashMap to check for repetitions
        //abc, abca, (abca, bca) abcab (abcab, bcab, cab)
        //abbbaaaaaccc
            //outside, initialize left ptr to 0 again after window has been iterated through
        //abcababab
        //we might not need sliding window, just two pointers

       int c[3] ={};
       int ans=0;
       int i=0;
       int j=0;
        int n = s.length();
        for(;j<n;j++) 
        {
            c[s[j] - 'a']++; //increase a, b, or c by ASCII character
            /*
            f s[j] is 'a', s[j] - 'a' is 0 (since 97 - 97 = 0).
            If s[j] is 'b', s[j] - 'a' is 1 (since 98 - 97 = 1).
            If s[j] is 'c', s[j] - 'a' is 2 (since 99 - 97 = 2).
            */
            while (c[0] && c[1] && c[2])
            c[s[i++] - 'a']--; //shrink window left and increment left ptr
            ans+=i;
        }
        return ans;
        
    }
};

//time complexity O(n)
