#include <iostream>
using namespace std;
void TOH(int n, char source, char aux, char destination){
    if(n == 1){
        cout << "Move disk 1 from " << source << " to " << destination << "\n";
        return; 
    }
    TOH(n - 1, source, destination, aux);
    cout << "Move disk " << n << " from " << source << " to " << destination << "\n";
    TOH(n - 1, aux, source, destination);
}
int main(){
    cout << "Enter the number of disks: ";
    int n; cin >> n;
    TOH(n, 'A', 'B', 'C');
    return 0;
}