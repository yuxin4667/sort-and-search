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

int main()
{
    int a[10] = {5, 7, 10, 3, 8, 6, 1, 2, 4, 9};
    int arrayLength = sizeof(a) / sizeof(*a);
    int count = 1, n = 1;
    for (int step = floor(arrayLength / 2); step > 1; step = floor(step / 2))
    {
        cout << "gap " << step << endl;
        for (int index = 0; index < step; index++)
        {
            for (int i = index + step; i < arrayLength; i += step)
            {
                for (int j = i; j - step >= 0; j -= step)
                {
                    cout << j << " " << j - step << "    ";
                    printa(a, arrayLength);
                    if (a[j] < a[j - step])
                        swap(a, j, j - step);
                }
            }
        }
    }
    for (int i = 1; i < arrayLength; i++)
    {
        for (int j = i; j > 0; j--)
        {
            if (a[j] < a[j - 1])
                swap(a, j, j - 1);
        }
    }
    cout << "--- After Shell Sort ---" << endl;
    printa(a, arrayLength);
    return 0;
}
