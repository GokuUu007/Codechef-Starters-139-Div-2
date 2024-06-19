/* 

    ॐ हौं जूं सः ॐ भूर्भुवः स्वः 
    ॐ त्र्यम्बकं यजामहे सुगन्धिं पुष्टिवर्धनम् उर्वारुकमिव बन्धनान्मृत्योर्मुक्षीय मामृतात् 
    ॐ स्वः भुवः भूः ॐ सः जूं हौं ॐ

   @Author  : Akshat Madhavan
   @Country : INDIA 
   
*/

#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#ifdef AKSHAT
#include "debug.h"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define deb(x...)
#endif


template<class T>void output (vector<T> &a) {for (auto &x : a) {cout << x << ' ';}cout << '\n';}
template<typename T> void chmin (T &a, T b) {if (a > b) swap(a, b);}
template<typename T> void chmax (T &a, T b) {if (a < b) swap(a, b);}


void solve() {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &x : a)
        cin >> x;

    auto good = [&] (int k) {
        ll now = 0;
        for (auto &x : a) {
            if (now > x) {
                if (x + k < now)
                    return 0;
                now = x + k;
            } else {
                now = x;
            }
        }
        return 1;
    };

    int x = 0, now = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < now) {
            x = max(x, now - a[i]);
            now = a[i];
        } else {
            now = a[i];
        }
    }

    int low = x, high = n, r = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (good(mid))
            low = mid + 1, r = mid;
        else
            high = mid - 1;
    }
    
    cout << max(0LL, r * 1LL * (r + 1) / 2 - x * 1LL * (x - 1) / 2) << '\n';
} 


int32_t main() {
    
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);

    #ifdef AKSHAT   
        freopen("error.txt", "w", stderr);  
    #endif  

    int tc = 1;
    cin >> tc;
    for (int cases = 1; cases <= tc; ++cases) {
        solve();
        // cout << (solve() ? "YES\n" : "NO\n");
        // cout << "Case # " << cases;
    } 

    #ifdef AKSHAT
        double timeTaken = 1000.0 * clock() / CLOCKS_PER_SEC;
        cout << "\n[Finished in " << timeTaken << "ms]";
        cerr << "\n[Finished in " << timeTaken << "ms]";
    #endif

    return 0;
}

//JAI SHREE RAM !!!!
