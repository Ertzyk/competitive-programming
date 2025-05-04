#include <iostream>
#include <algorithm>
#include <random>
#include <vector>
#include <queue>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> poss_nums(pow(2, n));
        for(int i = 0; i < pow(2, n); i++) poss_nums[i] = i + 1;
        random_device rd;
        mt19937 gen(rd());
        shuffle(poss_nums.begin(), poss_nums.end(), gen);
        queue<int> q;
        for(int x: poss_nums) q.push(x);
        while(true){
            int contestant1 = q.front();
            q.pop();
            if(q.empty()){
                cout << "! " << contestant1 << '\n';
                cout.flush();
                break;
            }
            int contestant2 = q.front();
            q.pop();
            cout << "? " << contestant1 << ' ' << contestant2 << '\n';
            cout.flush();
            int response;
            cin >> response;
            if(response == 1) q.push(contestant1);
            else if(response == 2) q.push(contestant2);
        }
    }
    return 0;
}