// MinMaxOneScan.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>

void MinMax(int* arr, size_t taille);

int main()
{
    int arr[] = { 5,6,10,20,1,2,3,16 };
    size_t taille = sizeof(arr) / sizeof(arr[0]);
    MinMax(arr, taille);
    return 0;
}


void MinMax(int* arr, size_t taille)
{
    int min = arr[0];
    int max = arr[0];
    for (int i = 0; i < taille; i++)
    {
        if (min < arr[i])
            min = arr[i];
        else if (max > arr[i])
            max = arr[i];
    }
    printf("min --> %d | max --> %d\n", min, max);
}