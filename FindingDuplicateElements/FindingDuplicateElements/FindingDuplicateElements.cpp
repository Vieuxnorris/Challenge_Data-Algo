// FindingDuplicateElements.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <stdlib.h>

void FindingDuplicate(int* arr, size_t taille);
void FindingDuplicate2(int* arr, size_t taille);
void FindingDuplicateHashing(int* arr, size_t taille);
size_t Max(const int arr[], size_t taille);

int main()
{
    int arr[] = { 3,6,8,8,10,12,15,15,15,20 };
    size_t taille_arr = sizeof(arr) / sizeof(arr[0]);
    FindingDuplicateHashing(arr,taille_arr);
    return 0;
}

void FindingDuplicate(int* arr, size_t taille)
{
    int lastDuplicate = 0;

    for (size_t i = 0; i < taille; i++)
    {
        if (arr[i] == arr[i + 1] && arr[i] != lastDuplicate)
        {
            printf("%d\n", arr[i]);
            lastDuplicate = arr[i];
        }
    }
}

void FindingDuplicate2(int* arr, size_t taille)
{
    int j = 0;
    for (size_t i = 0; i < taille; i++)
    {
        if (arr[i] == arr[i + 1])
        {
            j += i;
            while (arr[j] == arr[i])
                j++;
            printf("%d is appearing %d times", arr[i], j - i);
            i = j - 1;
        }
    }
}

void FindingDuplicateHashing(int* arr, size_t taille)
{
    size_t max = Max(arr, taille);
    static int* hashingTable = (int*)malloc((max+1) * sizeof(int)); // 0-->20 pour les 20 éléments d'ou le max+1
    for (size_t i = 0; i <= max; i++)
        hashingTable[i] = 0;
    for (size_t i = 0; i < taille; i++)
        hashingTable[arr[i]]++;
    for (size_t i = 0; i <= max; i++)
    {
        if (hashingTable[i] > 1)
            printf("%d --> %d\n", i, hashingTable[i]);
    }
}

size_t Max(const int arr[], size_t taille)
{
    size_t max = 0;
    for (size_t i = 0; i < taille; i++)
    {
        if (arr[i] > (int)max)
            max = arr[i];
    }
    return max;
}
