#include <bits/stdc++.h>
using namespace std;

void tower_of_hanoi(int n, string src, string dest, string helper) {
    if(n == 1) {
        cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
        return;
    }
    tower_of_hanoi(n - 1, src, helper, dest);
    cout << "Transfer disk " << n << " from " << src << " to " << dest << endl;
    tower_of_hanoi(n - 1, helper, dest, src);
}

int main() {
    int n;
    cout << "Enter the no. of disks : ";
    cin >> n;
    cout << "Below steps need to be followed : \n";
    tower_of_hanoi(n, "Source", "Destination", "Helper");
    return 0;
}
