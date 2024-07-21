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
void Merge(int *a, int *tempArray, int lowIndex, int highIndex)
{
    int midIndex = (lowIndex + highIndex) / 2;
    int leftIndex = lowIndex;
    int rightIndex = midIndex + 1;
    int tempIndex = lowIndex;
    while (leftIndex <= midIndex && rightIndex <= highIndex)
    {
        if (a[leftIndex] < a[rightIndex])
        {
            tempArray[tempIndex] = a[leftIndex];
            leftIndex++;
        }
        else if (a[rightIndex] < a[leftIndex])
        {
            tempArray[tempIndex] = a[rightIndex];
            rightIndex++;
        }
        tempIndex++;
    }
    while (rightIndex <= highIndex)
    {
        tempArray[tempIndex] = a[rightIndex];
        rightIndex++;
        tempIndex++;
    }

    while (leftIndex <= midIndex)
    {
        tempArray[tempIndex] = a[leftIndex];
        leftIndex++;
        tempIndex++;
    }

    for (int i = lowIndex; i <= highIndex; i++)
    {
        a[i] = tempArray[i];
    }
    int arrayLength = 14;
    printa(a, arrayLength);
    return;
}
void Divide(int *a, int *tempArray, int low, int high)
{
    int mid = (low + high) / 2;
    if (low < high)
    {
        cout << "Divide " << low << " " << mid << endl;
        Divide(a, tempArray, low, mid);
        cout << "Divide " << mid + 1 << " " << high << endl;
        Divide(a, tempArray, mid + 1, high);
        cout << "Merge " << low << " " << high << endl;
        Merge(a, tempArray, low, high);
    }
    return;
}
int main()
{
    int a[14] = {10, 7, 5, 3, 8, 6, 1, 2, 9, 4, 14, 11, 13, 12};
    int tempArray[14] = {0};
    int leftIndex, rightIndex;
    int arrayLength = sizeof(a) / sizeof(*a);
    Divide(a, tempArray, 0, arrayLength - 1);

    cout << "--- After Merge Sort ---" << endl;
    printa(a, arrayLength);
    return 0;
}
