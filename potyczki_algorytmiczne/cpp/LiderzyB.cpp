#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n), freq(n + 1);
    for(int &x: a) cin >> x;
    unordered_set<int> unique(a.begin(), a.end());
    for(int x: unique){
        freq[count(a.begin(), a.end(), x)]++;
    }
    int l = 0, r = n, result = 0;
    while(l <= r){
        while(freq[r] == 0 && l <= r) r--;
        freq[r]--;
        while(freq[l] == 0 && l <= r) l++;
        int deleted = 0;
        while(deleted != r - 1 && l <= r){
            while(freq[l]*l <= r - 1 - deleted && l <= r){
                deleted += freq[l]*l;
                freq[l] = 0;
                while(freq[l] == 0 && l <= r) l++;
            }
            if(l > r) break;
            freq[l] -= (r - 1 - deleted)/l;
            deleted += (r - 1 - deleted)/l*l;
            if(r - 1 - deleted){
                freq[l]--;
                freq[l - (r - 1 - deleted)]++;
                l -= r - 1 - deleted;
                deleted = r - 1;
            }
        }
        result++;
    }
    cout << result;
    return 0;
}