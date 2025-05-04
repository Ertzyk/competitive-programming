#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k, t, result = -1;
    cin >> n >> k >> t;
    vector<char> a(n);
    for(char &x: a) cin >> x;
    vector<int> precal_meetings(n), precal_remote_meetings(n + 1);
    int meetings = 0, remote_meetings = 0;
    for(int i = 0; i < n; i++){
        precal_remote_meetings[i] = remote_meetings;
        if(a[i] == '1') meetings++;
        else if(a[i] == '2'){
            meetings++;
            remote_meetings++;
        }
        precal_meetings[i] = meetings;
    }
    precal_remote_meetings[n] = remote_meetings;
    k = max(meetings - k, 0);
    if(remote_meetings >= k){
        cout << n - k;
        return 0;
    }
    for(int l = t; l <= n - t - 1; l++){
        for(int r = l; r <= n - t - 1; r++){
            meetings = precal_meetings[r] - precal_meetings[l - 1];
            if(meetings >= k) result = max(result, n - (r - l + 1) - 2*t);
            else {
                int extra_meetings = precal_remote_meetings[l - t] + remote_meetings - precal_remote_meetings[r + t + 1];
                if(meetings + extra_meetings >= k) result = max(result, n - (r - l + 1) - 2*t - (k - meetings));
            }
        }
    }
    cout << result;
    return 0;
}