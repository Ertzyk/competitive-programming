#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Segment{
    int l, r, idx, rank;
};

struct FenwickTree{
    int n;
    vector<int> bit;
    FenwickTree(int n) : n(n), bit(n + 1, 0) {}
    int sum(int i){
        int result = 0;
        while(i > 0){
            result += bit[i];
            i -= (i&-i);
        }
        return result;
    }
    void add(int i, int delta){
        while(i <= n){
            bit[i] += delta;
            i += (i&-i);
        }
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<Segment> segments(n);
    for(int i = 0; i < n; i++){
        cin >> segments[i].l >> segments[i].r;
        segments[i].idx = i;
    }
    sort(segments.begin(), segments.end(), [](Segment a, Segment b){
        return a.r < b.r;
    });
    for(int i = 0; i < n; i++) segments[i].rank = i + 1;
    sort(segments.begin(), segments.end(), [](Segment a, Segment b){
        return a.l > b.l;
    });
    vector<int> result(n, 0);
    FenwickTree ft(n);
    for(Segment seg: segments){
        result[seg.idx] = ft.sum(seg.rank);
        ft.add(seg.rank, 1);
    }
    for(int x: result) cout << x << '\n';
    return 0;
}