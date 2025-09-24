#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Card{
    int w, h, idx;
    bool operator<(const Card& other) const {
        return w < other.w;
    }
};

int main(){
    ios::sync_with_stdio(false);
    int n, w, h;
    cin >> n >> w >> h;
    vector<Card> cards;
    cards.reserve(n);
    for(int i = 0; i < n; i++){
        Card c;
        c.idx = i + 1;
        cin >> c.w >> c.h;
        if(c.w > w && c.h > h) cards.push_back(c);
    }
    if(cards.empty()){
        cout << "0\n";
        return 0;
    }
    sort(cards.begin(), cards.end());
    vector<int> dp(cards.size(), 1), parent(cards.size(), -1), result;
    result.reserve(n);
    int max_val = 1, max_idx = 0;
    for(int i = 0; i < cards.size(); i++){
        for(int j = i - 1; j >= 0; j--){
            if(cards[i].w > cards[j].w && cards[i].h > cards[j].h && dp[i] < dp[j] + 1){
                dp[i] = dp[j] + 1;
                parent[i] = j;
                if(dp[i] > max_val){
                    max_val = dp[i];
                    max_idx = i;
                }
            }
        }
    }
    while(max_idx != -1){
        result.push_back(cards[max_idx].idx);
        max_idx = parent[max_idx];
    }
    reverse(result.begin(), result.end());
    cout << result.size() << '\n';
    for(int x: result) cout << x << ' ';
    cout << '\n';
    return 0;
}