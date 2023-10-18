bool searchPattern(string str, string pat)
{
    // RABIN-KARP ROLLING HASH
    int i = 0, j = 0;
    int n = str.length(), m = pat.length();
    int d = 31; // prime number to reduce the chances of collision
    
    // using Rabin Karp algorithm
    // calculating hash value of the pattern
    int hash = 0, currHash = 0;
    for(int i = 0; i < m; i++) {
        hash = (hash*d + (pat[i]-'a'))%INT_MAX;
        currHash = (currHash*d + (str[i]-'a'))%INT_MAX;
    }
    
    if(currHash == hash) {
        bool flag = true;
        for(int i = 0; i < m; i++) {
            if(str[i] != pat[i]) {
                flag = false;
                break;
            }
        }
        if(flag) return true;
    }
    
    int msb = 1;
    for(int i = 0; i < m-1; i++) {
        msb = msb*d;
    }
    
    for(int i = m; i < n; i++) {
        currHash = (currHash - (str[i-m]-'a')*msb)%INT_MAX;
        currHash = (currHash*d)%INT_MAX;
        currHash += (str[i]-'a');
        currHash = currHash%INT_MAX;
        
        if(currHash == hash) {
            bool flag = true;
            for(int j = 0 ; j < m; j++) {
                if(pat[j] != str[i-m+1+j]) {
                    flag = false;
                    break;
                }
            }
            if(flag) return true;
        }
    }
    
    return false;
}




