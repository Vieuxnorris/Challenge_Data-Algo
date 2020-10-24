#include <stdio.h>

int SingleMissing(int* arr)
{
    int sum,total,i;
    sum = total = i = 0;
    for (i = 0; i < 11; i++)
        sum += arr[i];
    total = arr[i-1] * (arr[i-1] + 1) / 2;
    return total - sum;
}

int SingleMissingOpti(int* arr)
{
    int diff = arr[0];
    int i;
    for (i = 0; i < 11; i++)
    {
        if (arr[i] - i != diff)
            return i+diff;
    }
    return 0;
}

int main()
{
    int result = 0;
    int arr[] = { 6,7,8,9,10,11,13,14,15,16,17 };
    result = SingleMissingOpti(arr);
    printf("element missing in array --> %d", result);
    return 0;
}
