#include <iostream>
using namespace std;
void swap(int a[], int index1, int index2)
{
    int temp = a[index1];
    a[index1] = a[index2];
    a[index2] = temp;
}
void printa(int a[], int arrayLength)
{
    for (int k = 0; k < arrayLength; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;
}
int main()
{
    int a[10] = {5, 7, 2, 3, 8, 6, 1, 9, 4, 10};
    int arrayLength = sizeof(a) / sizeof(*a);
    int step = 1;
    for (int i = 1; i < arrayLength; i++)
    {
        int key = a[i], j = i - 1;
        while (j >= 0 && key < a[j])
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = key;
        cout << "Step " << i << "  ";
        printa(a, arrayLength);
    }

    cout << "--- After Insertion Sort ---" << endl;
    for (int i = 0; i < arrayLength; i++)
    {
        cout << a[i] << " -> ";
    }
    return 0;
}
