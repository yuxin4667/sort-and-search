#include <iostream>
#include <cmath>
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

void Heapify(int *a, int parentIndex, int lastIndex)
{
    int bigChildIndex = parentIndex * 2 + 1;
    while (bigChildIndex <= lastIndex)
    {
        // int childIndex2 = parentIndex * 2 + 2;
        if (bigChildIndex + 1 <= lastIndex)
        {
            bigChildIndex = a[bigChildIndex] > a[bigChildIndex + 1] ? bigChildIndex : bigChildIndex + 1;
        }

        if (a[parentIndex] < a[bigChildIndex])
        {
            swap(a, parentIndex, bigChildIndex);
            parentIndex = bigChildIndex;
            bigChildIndex = parentIndex * 2 + 1;
        }
        else
        {
            return;
        }
    }
    return;
}
void HeapSort(int *a, int parentIndex, int arrayLength)
{
    // build a max_heap
    for (int i = (arrayLength - 1) / 2; i >= 0; i--)
    {
        Heapify(a, i, arrayLength - 1);
    }
    for (int i = arrayLength - 1; i >= 0; i--)
    {
        swap(a, 0, i);
        printa(a, arrayLength);
        Heapify(a, 0, i - 1);
    }
    return;
}
int main()
{
    int a[13] = {10, 7, 5, 3, 8, 6, 1, 2, 9, 4, 11, 13, 12};
    int arrayLength = sizeof(a) / sizeof(*a);
    // partition(a, 0, arrayLength - 1);
    HeapSort(a, 0, arrayLength);
    cout << "--- After Heap Sort ---" << endl;
    printa(a, arrayLength);
    return 0;
}
