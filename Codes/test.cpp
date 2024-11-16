#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;
void bubbleSort(vi &v){
    int n = v.size();
    for(int i = n - 1; i > -1; i--){
        for(int j = 0; j < i + 1; j++){
            if(v[j] > v[j + 1]) swap(v[j], v[j + 1]);
        }
    }
}
void insertionSort(vi &v){
    int n = v.size();
    for(int i = 0; i < n; i++){
        int j = i;
        while(j > 0 && v[j] < v[j - 1]) {
            swap(v[j], v[j - 1]);
            j--;
        }
    }
}
void selectionSort(vi &v){
    int n = v.size();
    for(int i = 0; i < n - 1; i++){
        int minId = i;
        for(int j = i; j < n; j++){
            if(v[j] < v[minId]) minId = j;
        }
        swap(v[i], v[minId]);
    }
}
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
    while(right <= high) {
        temp.push_back(v[right]);
        right++;
    }
    for(int i = low; i < high + 1; i++) v[i] = temp[i - low];
}
void ms(vi &v, int low, int high){
    if(low == high) return;
    int mid = (low + high)/2;
    ms(v, low, mid);
    ms(v, mid + 1, high);
    merge(v, low, mid, high);
}
int partition(vi &v, int low, int high){
    int i = low, j = high;
    int piv = v[i];
    while(i < j){
        while(v[i] <= piv && i < high) i++;
        while(v[j] > piv && j > low) j--;
        if(i < j) swap(v[i], v[j]);
    }
    swap(v[low], v[j]);
    return j;
}
void qs(vi &v, int low, int high){
    if(low < high){
        int pi = partition(v, low, high);
        qs(v, low, pi - 1);
        qs(v, pi + 1, high);
    }
}
void print(vi &v){
    for(const auto &i : v) cout << i << " ";
    cout << "\n";
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
    qs(v, 0, n - 1);
    print(v);
    return 0;
}