#include <stdio.h>

void MultipleMissing(int* arr)
{
    int diff = arr[0];
    int i;
    for (i = 0; i < 10; i++)
    {
        if (arr[i] - i != diff)
        {
            while (diff < arr[i] - i)
            {
                printf("Element is missing --> %d | index --> %d \n", i + diff, i);
                diff++;
            }
        }
    }
}

void MultipleMissingOpti(int* arr)
{
    int i;
    int hashmap[13] = {0};
    for (i = 0; i < 10; i++)
        hashmap[arr[i]]++;
    for (i = 1; i <= 13; i++)
    {
        if (hashmap[i] == 0)
            printf("element is missing --> %d\n", i);
    }
}

int main()
{
    int arr[] = { 3,7,4,9,12,6,1,11,2,10 };
    MultipleMissingOpti(arr);
    return 0;
}
