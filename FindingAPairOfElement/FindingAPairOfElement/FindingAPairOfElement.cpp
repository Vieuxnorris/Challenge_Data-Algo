// FindingAPairOfElement.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <malloc.h>

void FindingPairElement(int* arr, size_t taille, int sum);
void FindingPairElementHashing(int* arr, size_t taille, int sum);
size_t Max(int* arr, size_t taille);

int main()
{
    int arr[] = { 6,3,8,10,16,7,5,2,9,14 };
    size_t taille = sizeof(arr) / sizeof(arr[0]);
    FindingPairElementHashing(arr, taille, 10);
}

void FindingPairElement(int* arr, size_t taille, int sum)
{
    for (size_t i = 0; i < taille - 1; i++)
    {
        for (size_t j = i + 1; j < taille; j++)
        {
            if (arr[i] + arr[j] == sum)
                printf("%d + %d = %d\n", arr[i], arr[j], sum);
        }
    }
}

void FindingPairElementHashing(int* arr, size_t taille, int sum)
{
    size_t max = Max(arr, taille);
    static int *hashingTable = (int*)malloc((max + 1) * sizeof(int));
    for (size_t i = 0; i <= max; i++)
        hashingTable[i] = 0;
    for (size_t i = 0; i < taille; i++)
        hashingTable[arr[i]]++;
    for (size_t i = 0; i < taille; i++)
    {
        if (hashingTable[sum - arr[i]] != 0)
            printf("%d + %d = %d\n", arr[i], sum - arr[i], sum);
    }
}

size_t Max(int* arr, size_t taille)
{
    size_t max = 0;
    for (size_t i = 0; i < taille; i++)
    {
        if ((size_t)arr[i] > max)
            max = arr[i];
    }
    return max;
}
