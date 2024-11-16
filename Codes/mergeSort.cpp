#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
void merge(vi &v, int low, int mid, int high){
    vi temp;
    int left = low;
    int right = mid + 1;
    while(left <= mid && right <= high){
        if(v[left] < v[right]){
            temp.push_back(v[left]);
            left++;
        }
        else{
            temp.push_back(v[right]);
            right++;
        }
    }
    while(left <= mid){
        temp.push_back(v[left]);
        left++;
    }
    while(right <= high){
        temp.push_back(v[right]);
        right++;
    }
    for(int i = low; i <= high; i++) v[i] = temp[i - low];
}
void mergeSort(vi &v, int low, int high){
    if(low == high) return;
    int mid = (low + high)/2;
    mergeSort(v, low, mid);
    mergeSort(v, mid + 1, high);
    merge(v, low, mid, high);
}
void print(vi &v){
    for(const auto &i : v) cout << i << " ";
    cout << endl;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vi v(n);
    for(auto &i : v) cin >> i;
    print(v);
    mergeSort(v, 0, n - 1);
    print(v);
    return 0;
}