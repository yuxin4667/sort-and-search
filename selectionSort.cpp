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
    int max = 0;
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        max = 0;
        for (int j = 0; j <= i; j++)
        {
            if (a[j] > a[max])
                max = j;
        }
        swap(a, i, max);
        cout << "Step " << 10 - i << "  ";
        for (int i = 0; i < arrayLength; i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;
    }

    cout << "--- After Selection Sort ---" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << a[i] << " -> ";
    }
    return 0;
}
