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
    for (int i = 1; i < arrayLength; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
                swap(a, j, j - 1);
        }

        cout << "Step " << i << "  ";
        for (int k = 0; k < arrayLength; k++)
        {
            cout << a[k] << " ";
            if (k == i)
                cout << " | ";
        }
        cout << endl;
    }

    cout << "--- After Insertion Sort ---" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << a[i] << " -> ";
    }
    return 0;
}
