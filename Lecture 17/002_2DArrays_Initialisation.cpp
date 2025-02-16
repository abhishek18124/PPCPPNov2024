#include<iostream>

using namespace std;

int main() {

    int arr[3][4] = {
        {10, 15, 20, 25},
        {30, 35, 40, 45},
        {50, 55, 60, 65}
    };

    int m = 3; // no. of rows
    int n = 4; // no. of cols

    for (int i = 0; i < m; i++) { // iterating over the rows

        // print the ith row

        for (int j = 0; j < n; j++) {

            cout << arr[i][j] << " ";

        }

        cout << endl;

    }

    cout << endl;

    cout << arr[0][0] << " ";
    cout << arr[0][1] << " ";
    cout << arr[0][2] << " ";
    cout << arr[0][3] << endl;

    cout << arr[1][0] << " ";
    cout << arr[1][1] << " ";
    cout << arr[1][2] << " ";
    cout << arr[1][3] << endl;

    cout << arr[2][0] << " ";
    cout << arr[2][1] << " ";
    cout << arr[2][2] << " ";
    cout << arr[2][3] << endl;

    return 0;
}