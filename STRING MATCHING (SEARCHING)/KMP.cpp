bool searchPattern(string str, string pat)
{
    // KMP
    int n = str.length(), m = pat.length();
    
    
    // lps computation starts here
    vector<int>lps(m,0);
    int len = 0;
    int i = 1, j;
    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            // not a match
            if(len == 0) {
                lps[i] = 0;
                i++;
            } else {
                len = lps[len-1];
            }
        }
    }
    // lps:longest prefix which is also suffix array has been created
    
    
    i = 0, j = 0;
    while((n-i) >= (m-j)) {
        if(str[i] == pat[j]) {
            i++;
            j++;
        }
        if(j == m) return true;
        
        if(str[i] != pat[j]) {
            if(j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return false;
}
