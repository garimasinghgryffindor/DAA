#include <iostream>
#include <vector>
//#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

#define NEAKT 5000000

struct Contestant {
  int rank1;
  int rank2;
  int rank3;
  bool operator<(const Contestant &x) const {
    return (rank1 < x.rank1);
  }
};

int segTree[5000000];
int n;
Contestant contestants[1000000];

int queryMin(int idx, int l, int r, int pos) {
    //// NO OVERLAP
    //if(l > r || ql > r || qr < l) return 5000000;
    
    //// COMPLETE OVERLAP
    //if(ql <= l && qr >= r) return segTree[idx];

    //// PARTIAL OVERLAP
    //int mid = l + (r-l)/2;
    //int left = queryMin(2*idx+1, l, mid, ql, qr);
    //int right = queryMin(2*idx+2, mid+1, r, ql, qr);
    //return min(left, right);

    int h = l + (r-l) / 2;
    if (l == r)
        return segTree[idx];
    if (pos <= h)
        return queryMin(2 * idx + 1, l, h, pos);
    else
        return min(segTree[2 * idx + 1], queryMin(2 * idx + 2, h + 1, r, pos));
}

void updateMin(int idx, int l, int r, int pos, int val) {
    //// NO OVERLAP
    //if(pos > r || pos < l) return;

    //// COMPLETE OVERLAP
    //if(l == r && pos == l) {
    //    segTree[idx] = val;
    //    return;
    //}

    //// PARTIAL OVERLAP
    //int mid = l + (r-l)/2;
    //updateMin(2*idx+1, l, mid, pos, val);
    //updateMin(2*idx+2, mid+1, r, pos, val);
    //segTree[idx] = min(segTree[2*idx+1], segTree[2*idx+2]);

    int h = l + (r - l) / 2;
    if (val < segTree[idx])
        segTree[idx] = val;
    if (l == r)
        return;
    else if (pos <= h)
        updateMin(2 * idx + 1, l, h, pos, val);
    else
        updateMin(2 * idx + 2, h + 1, r, pos, val);
}

int main()
{
    int t;
    cin>>t;

    while(t--) {
        cin>>n;
        int ans = 0;

        for (int i = 0; i < 4 * n; i++)
            segTree[i] = NEAKT;

        for(int i = 0; i < n; i++) {
            cin>>contestants[i].rank1>>contestants[i].rank2>>contestants[i].rank3;
        }

        // first level of sorting
        // I am obviously better than all those whose rank1 is below me
        sort(contestants, contestants+n);

        // here we are testing all those who are better than me in rank1

        // idx in tree[idx] represents rank2 of all rank1s better than me,
        // and tree[idx] represents rank3 value of those better than me so far
        // if i am better than those in at rank3s -> i am excellent

        for(int i = 0; i < n; i++) {
            int minimest = queryMin(0, 0, n-1, contestants[i].rank2-1);     // (Yes, I believe it must be declared as a meaningful word officially!!)
            if(minimest > contestants[i].rank3) {
                ans++;
            }
            
            updateMin(0, 0, n-1, contestants[i].rank2 - 1, contestants[i].rank3);
        }

        cout<<ans<<endl;
    }

    return 0;
}