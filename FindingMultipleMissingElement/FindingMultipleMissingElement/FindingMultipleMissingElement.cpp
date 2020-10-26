#include <stdio.h>
#include <malloc.h>

void MultipleMissing(int* arr);
int Max(int* arr, int taille);
void MultipleMissingOpti(int* arr, int taille);

int main()
{
    int arr[] = { 3,7,4,9,12,6,1,11,2,10 };
    int taille = sizeof(arr) / sizeof(arr[0]);
    MultipleMissingOpti(arr, taille);
    return 0;
}

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

int Max(int* arr, int taille)
{
    int max = arr[0];
    for (int i = 0; i < taille; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

void MultipleMissingOpti(int* arr, int taille)
{
    int i;
    int max = Max(arr, taille);
    static int* hashmap = (int*)malloc((max+1) * sizeof(int));
    for (i = 0; i < taille; i++)
        hashmap[arr[i]] = 1;
    for (i = 1; i <= max; i++)
    {
        if (hashmap[i] != 1)
            printf("element is missing --> %d\n", i);
    }
}