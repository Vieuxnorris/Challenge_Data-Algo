// FindingDuplicatesUnsorted.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

#include <stdio.h>
#include <malloc.h>

void findingDuplicateUnsorted(int *arr, size_t taille);
void findingDuplicateUnsortedHashing(int* arr, size_t taille);
size_t Max(int* arr, size_t taille);

int main()
{
	int arr[] = { 8,3,6,4,6,5,6,8,2,7 };
	size_t taille = sizeof(arr) / sizeof(arr[0]);
	findingDuplicateUnsortedHashing(arr, taille);
	return 0;
}

void findingDuplicateUnsorted(int *arr, size_t taille)
{
	size_t i, j;
	i = j = 0;
	for (i = 0; i < taille - 1; i++)
	{
		size_t count = 1;
		if (arr[i] != -1)
		{
			for (j = i + 1; j < taille; j++)
			{
				if (arr[i] == arr[j])
				{
					count++;
					arr[j] = -1;
				}
			}
			if (count > 1)
				printf("%d %d\n", arr[i], count);
		}
	}
}

void findingDuplicateUnsortedHashing(int *arr, size_t taille)
{
	size_t max = Max(arr, taille);
	static int* hashingTable = (int*)malloc((max + 1) * sizeof(int));
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

size_t Max(int *arr,size_t taille)
{
	size_t max = 0;
	for (size_t i = 0; i < taille; i++)
	{
		if ((size_t)arr[i] > max)
			max = arr[i];
	}
	return max;
}