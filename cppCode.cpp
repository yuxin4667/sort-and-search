#include <iostream>
using namespace std;
int main()
{
    int a[10] = { 5, 7, 2, 3, 8, 6, 1, 9, 4, 10};
    int arrayLength = sizeof(a) / sizeof(*a);
    int step = 1;
    for (int i = arrayLength - 1; i >= 0; i--) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i]) {
                int temp = a[j];
                a[j] = a[i];
                a[i] = temp;
            }

            cout << "Step " << 10-i <<"-" <<j<< "  ";
            for (int i = 0; i < arrayLength; i++) {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    cout << "--- After Bubble Sort ---"<< endl;
    for (int i = 0; i < arrayLength; i++) {
        cout << a[i] << " -> ";
    }
    return 0;
}

