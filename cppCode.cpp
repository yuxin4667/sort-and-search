#include <iostream>
using namespace std;
void swap(int a[], int index1, int index2)
{
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}
int main()
{
    int a[10] = {5, 7, 2, 3, 8, 6, 1, 9, 4, 10};
    int arrayLength = sizeof(a) / sizeof(*a);
    int step = 1;
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (a[j] > a[i])
            {
                swap(a, i, j);
            }

            cout << "Step " << 10 - i << "-" << j << "  ";
            for (int i = 0; i < arrayLength; i++)
            {
                cout << a[i] << " ";
            }
            cout << endl;
        }
    }

    cout << "--- After Bubble Sort ---" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << a[i] << " -> ";
    }
    return 0;
}
