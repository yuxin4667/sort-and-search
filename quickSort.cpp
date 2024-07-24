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

// 調整數列，回傳pivotIndex，一般取名partition
int choosePivot(int *a, int lowIndex, int highIndex)
{
    int pivotIndex = lowIndex;
    int arrayLength = 13;
    printa(a, arrayLength);
    while (lowIndex < highIndex)
    {
        while (a[lowIndex] < a[pivotIndex])
        {
            lowIndex++;
        }
        while (a[highIndex] > a[pivotIndex])
        {
            highIndex--;
        }
        swap(a, lowIndex, highIndex);
    }
    pivotIndex = highIndex;
    return pivotIndex;
}
void partition(int *a, int left, int right)
{
    int pivotIndex;
    if (left < right)
    {
        pivotIndex = choosePivot(a, left, right);
        partition(a, left, pivotIndex);
        partition(a, pivotIndex + 1, right);
    }
    return;
}
int main()
{
    int a[13] = {10, 7, 5, 3, 8, 6, 1, 2, 9, 4, 11, 13, 12};
    int leftIndex, rightIndex;
    int arrayLength = sizeof(a) / sizeof(*a);
    partition(a, 0, arrayLength - 1);

    cout << "--- After Quick Sort ---" << endl;
    printa(a, arrayLength);
    return 0;
}
