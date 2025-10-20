#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<pair<int, int>> segments(n);
    for(int i = 0; i < n; i++){
        int x0, y0, x1, y1, x2, y2;
        cin >> x0 >> y0 >> x1 >> y1 >> x2 >> y2;
        segments[i].first = min(min(y0, y1), y2);
        segments[i].second = max(max(y0, y1), y2);
    }
    sort(segments.begin(), segments.end());
    priority_queue<int, vector<int>, greater<int>> min_heap;
    int result = 0;
    for(int i = 0; i < n; i++){
        while(!min_heap.empty() && min_heap.top() < segments[i].first) min_heap.pop();
        min_heap.push(segments[i].second);
        result = max(result, (int)min_heap.size());
    }
    cout << result << '\n';
    return 0;
}