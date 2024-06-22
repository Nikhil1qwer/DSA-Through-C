   /*Nikhil Codes*/
#include <bits/stdc++.h>
using namespace std;

#define MOD (1e9 + 7)
#define PI M_PI // acos(-1.0);
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define setpoint(x) fixed << setprecision(x)

typedef long long ll;
typedef vector<int> vii;
typedef vector<ll> vll;

#define forI(n) for(int i = 0; i < (n); i++)
#define forJ(n) for(int j = 0; j < (n); j++)
#define rofI(n) for(int i = (n) - 1; i >= 0; i--)
#define forIJ(n) for(int j = i; j < (n); j++)

static const auto _ = [] {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

/*
-----Global Variables
*/
long long len;                          
/*                                                 
-----Global Variables
*/

template<typename T>
void getval(T& var) {
    cin >> var;
}

template<typename T>
T gcd(T a, T b) {
    return b == 0? a : gcd(b, a % b);
}

template<typename T>
T setBits(T var) {
    return __builtin_popcount(var);
}

template<typename T>
vector<T> scan(ll var) {
    vector<T> arr(var);
    forI(var) {
        cin >> arr[i];
    }
    return arr;
}

template<typename T>
void peek(const vector<T>& var) {
    for (const auto& elem : var) {
        cout << elem << " ";
    }
    cout << endl;
}

template<typename T>
void peek(T var) {
    cout << var << endl;
}

template<typename type, typename V>
void fillV(type& arr, const V& val) {
    fill(all(arr), val);
}

int todigit(char c) {
    return c & 15;
}

bool isvowel(char ch) {
    ch = tolower(ch);
    return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
}

void InfiniteVoid() {
    // DATTEBAYO!
    cin >> len;
    vll nums = scan<ll>(len);
    sort(all(nums));
    nums.erase(unique(all(nums)), nums.end());
    peek(nums.size());
}

int main() {
    InfiniteVoid();
    return 0;
}