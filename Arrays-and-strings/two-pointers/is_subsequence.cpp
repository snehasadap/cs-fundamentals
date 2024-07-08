//given two strings s and t, returns True if s is a subsequence of t and False otherwise
//Ex: s = 'ace', t = 'a, b, c, d, e' --> True (it doesn't matter if they aren't consecutive)

bool isSubsequence(string s, string t){
    int i = 0; //string s pointer
    int j = 0; //string t pointer

    while (i < s.size() and j < t.size()){
        if (s[i] == t[j]) { 
            i++; //increment s pointer to move to next char
        }
        else{
            j++; //increment t pointer to search for characters equal to s[i]
        }
    }
    return i == s.size(); //if the length of the substring after loop doesn't equal its original size, that means not all elements were found, so the function will return false. otherwise, it will return true
}

//time complexity: O(1)

