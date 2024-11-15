#include <iostream>
#include <vector>
#include <algorithm>
#define all(x) (x.begin()), (x.end())
using namespace std;
int binarySearch(vector<int> &v, int high, int low, int target){
    int mid = low + (high - low)/2;
    if(target == v[mid]) return mid;
    else if(target > v[mid]) return binarySearch(v, high, mid + 1, target);
    else if(target < v[mid]) return binarySearch(v, mid - 1, low, target);
    else return -1;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int n; cin >> n;
    vector<int> v(n);
    for(int &i : v) cin >> i;
    sort(all(v));
    int target; cin >> target;
    int high = n - 1, low = 0;
    int ans = binarySearch(v, high, low, target);
    if(ans != -1) cout << target << " is present at " << ans << "\n";
    else cout << target << " is not in the array\n";
    return 0;
}