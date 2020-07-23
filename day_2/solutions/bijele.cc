#include<iostream>
#include<vector>
using namespace std;

int main() {
    int pieces[6];
    int correct[] = {1, 1, 2, 2, 2, 8};

    for(int i = 0; i < 6; i++) {
        cin >> pieces[i];   
    }
    
    for(int i = 0; i < 6; i++) {
        cout << correct[i] - pieces[i] << " ";
    }
    cout << endl;
    
    return 0;
}
