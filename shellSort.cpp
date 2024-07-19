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
    // 計算gap，每次砍半
    for (int gap = floor(arrayLength / 2); gap > 1; gap = floor(gap / 2))
    {
        cout << "gap " << gap << endl;
        // 處理第group組的排序(group0 = index[0 2 4 6 8], group1 = index[1 3 5 7 9]...)
        for (int group = 0; group < gap; group++)
        {
            // 對每一組進行插入排序，只是i++改為i+=gap
            for (int i = group + gap; i < arrayLength; i += gap)
            {
                int key = a[i], j = i - gap;
                while (j >= 0 && key < a[j])
                {
                    a[j + gap] = a[j];
                    cout << j << "        move to       " << j + gap << "    ";
                    j -= gap;

                    printa(a, arrayLength);
                }
                a[j + gap] = key;
                cout << key << " insert into index at " << j + gap << "    ";
                printa(a, arrayLength);
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
