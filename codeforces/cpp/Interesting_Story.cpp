#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

struct Word{
    ll a = 0, b = 0, c = 0, d = 0, e = 0;
    ll len(){
        return a + b + c + d + e;
    }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll t;
    cin >> t;
    while(t--){
        ll n, res = 0, cur = 0, cur_sum = 0;
        cin >> n;
        vector<Word> words(n);
        for(ll i = 0; i < n; i++){
            string s;
            cin >> s;
            Word w;
            for(char ch: s){
                if(ch == 'a') w.a++;
                else if(ch == 'b') w.b++;
                else if(ch == 'c') w.c++;
                else if(ch == 'd') w.d++;
                else w.e++;
            }
            words[i] = w;
        }
        sort(words.begin(), words.end(), [](Word a, Word b){
            return 2*a.a - a.len() > 2*b.a - b.len();
        });
        cur_sum += 2*words[cur].a - words[cur].len();
        cur++;
        while(cur_sum > 0 && cur < n){
            cur_sum += 2*words[cur].a - words[cur].len();
            cur++;
        }
        if(cur_sum > 0) cur++;
        res = max(res, cur - 1);
        cur_sum = cur = 0;
        sort(words.begin(), words.end(), [](Word a, Word b){
            return 2*a.b - a.len() > 2*b.b - b.len();
        });
        cur_sum += 2*words[cur].b - words[cur].len();
        cur++;
        while(cur_sum > 0 && cur < n){
            cur_sum += 2*words[cur].b - words[cur].len();
            cur++;
        }
        if(cur_sum > 0) cur++;
        res = max(res, cur - 1);
        cur_sum = cur = 0;
        sort(words.begin(), words.end(), [](Word a, Word b){
            return 2*a.c - a.len() > 2*b.c - b.len();
        });
        cur_sum += 2*words[cur].c - words[cur].len();
        cur++;
        while(cur_sum > 0 && cur < n){
            cur_sum += 2*words[cur].c - words[cur].len();
            cur++;
        }
        if(cur_sum > 0) cur++;
        res = max(res, cur - 1);
        cur_sum = cur = 0;
        sort(words.begin(), words.end(), [](Word a, Word b){
            return 2*a.d - a.len() > 2*b.d - b.len();
        });
        cur_sum += 2*words[cur].d - words[cur].len();
        cur++;
        while(cur_sum > 0 && cur < n){
            cur_sum += 2*words[cur].d - words[cur].len();
            cur++;
        }
        if(cur_sum > 0) cur++;
        res = max(res, cur - 1);
        cur_sum = cur = 0;
        sort(words.begin(), words.end(), [](Word a, Word b){
            return 2*a.e - a.len() > 2*b.e - b.len();
        });
        cur_sum += 2*words[cur].e - words[cur].len();
        cur++;
        while(cur_sum > 0 && cur < n){
            cur_sum += 2*words[cur].e - words[cur].len();
            cur++;
        }
        if(cur_sum > 0) cur++;
        cout << max(res, cur - 1) << '\n';
    }
    return 0;
}