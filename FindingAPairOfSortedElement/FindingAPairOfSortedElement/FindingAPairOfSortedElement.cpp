#include <stdio.h>

void FindingOfPair(int* arr, size_t taille, size_t sum);

int main()
{
    int arr[] = { 1,3,4,5,6,8,9,10,12,14 };
    size_t taille = sizeof(arr) / sizeof(arr[0]);
    FindingOfPair(arr, taille, 10);
}

void FindingOfPair(int* arr, size_t taille, size_t sum)
{
    size_t i, j;
    i = 0;
    j = taille - 1;
    while (i < j)
    {
        if ((size_t)(arr[i] + arr[j]) == sum)
        {
            printf("%d + %d = %d\n", arr[i], arr[j], sum);
            i++;
            j++;
        }
        else if ((size_t)(arr[i] + arr[j]) < sum)
        {
            i++;
        }
        else
            j--;
    }
}
