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
    for (int k = 1; k < arrayLength; k++)
    {
        cout << a[k] << " ";
    }
    cout << endl;
}

void Heapify(int *a, int parentIndex, int lastIndex)
{
    // lastIndex記錄總共幾個node
    while (parentIndex <= (lastIndex - 1) / 2)
    {
        int leftChildIndex = parentIndex * 2;
        int rightChildIndex = parentIndex * 2 + 1;
        int bigChildIndex = a[leftChildIndex] > a[rightChildIndex] ? leftChildIndex : rightChildIndex;

        if (a[parentIndex] < a[bigChildIndex])
        {
            swap(a, parentIndex, bigChildIndex);
            parentIndex = bigChildIndex;
        }
        else
        {
            break;
        }
    }
    return;
}
void BuildMaxHeap(int *a, int arrayLength)
{
    for (int i = (arrayLength - 1) / 2; i > 0; i--)
    {
        Heapify(a, i, arrayLength);
    }
}
int main()
{
    int a[] = {-1, 10, 7, 5, 3, 8, 6, 1, 2, 9, 4, 11, 13, 12};
    int b[] = {-1, 10, 7, 5, 3, 8, 6, 1, 2, 9, 4, 11, 13, 12};
    int arrayLength = sizeof(a) / sizeof(*a);

    BuildMaxHeap(a, arrayLength);
    ;

    for (int i = arrayLength - 1; i > 0; i--)
    {
        swap(a, 1, i);
        Heapify(a, 1, i - 1);
    }
    cout << "--- After Heap Sort ---" << endl;
    printa(a, arrayLength);
    return 0;
}
