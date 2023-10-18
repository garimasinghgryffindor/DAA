bool searchPattern(string str, string pat)
{
    string newString = pat + '$' + str;
    int n = newString.length();
    vector<int>z(n, 0);
    
    int L = 0, R = 0;
    
    for(int i = 1; i < n; i++) {
        if(i > R) {
            L = R = i;
            while(R < n && newString[R-L] == newString[R]) {
                R++;
            }
            z[i] = R-L;
            R--;
        } else {
            int k = i-L;
            if(z[k] < R-i+1) {
                z[i] = z[k];
            } else {
                L = i;
                while(R < n && newString[R-L] == newString[R]) {
                    R++;
                }
                z[i] = R-L;
                R--;
            }
        }
        
        if(z[i] == pat.length()) return true;
    }
    return false;
}




