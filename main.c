#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int getInput(int * n, int * k)
{

	printf("Pocet sirek:\n");
	if ((scanf("%d", n) != 1) || ( *n < 1) ) {
		return 0;
	}

	printf("Velikost skoku:\n");
	if ((scanf("%d", k) != 1) || ( *k < 0)) {
		return 0;
	}
	return 1;
}

void fillArr(int arr[], int n)
{
	//fills array with ones (match);
	for (int i = 0; i < n; i++)
		arr[i] = 1;
}

int * createArr(int n)
{
	int * arr = (int *) malloc (n * sizeof(int));
	return arr;
}

void printArr(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

int checkArr(int arr[], int n)
{
	//checks if arr is full of zeros or 2's, if true -> returns 1
	for (int i = 0; i < n; i++) {
		if (arr[i] == 1)
			return 0;
	}
	return 1;
}

int possibleMove(int arr[], int n, int k)
{
	//checks if another move is possible, if not returns 0

	for (int i = 0; i < n; i++) {
		int count = 0;
		if (arr[i] == 1){				//check if i is match
			for (int j = i + 1; j < n; j++) {		//check right side
				if (count == k && arr[j] == 1) {
					return 1;
				}
				count += arr[j];
			}
			count = 0;
			for (int j = i - 1; j >= 0; j--) {                //check left side
				if (count == k && arr[j] == 1) {
					return 1;
				}
				count += arr[j];
			}
		}
	}
	// no possible move
	return 0;
}


void makeMove(int arr[], int n, int k, int move, int arrSolution[], int * layer)
{
	arrSolution[*layer] = move;
	*layer = *layer + 1;
	if (move >= 0) {
		int count = 0;
		for (int i = move + 1; i < n; i++) {
			if (count == k && arr[i] == 1) {			// second condition maybe unnecessary
				arr[i] = 2;
				arr[move] = 0;
			}
			count += arr[i];
		}
	}

	else {
		int count = 0;
		for (int i = abs(move) - 1; i >= 0; i--) {
			if (count == k && arr[i] == 1) {			// second condition maybe unnecessary
				arr[i] = 2;
				arr[abs(move)] = 0;
			}
			count += arr[i];
		}
	}
	//printf("moved: ");
	//printArr(arr, n);
	//printf("\n");
}

void matches(int arr[], int n, int k, int move, int arrSolution[], int * layer, int * countSol);



void findAllCombinations(int arr[], int n, int k, int arrSolution[], int * layer, int * countSol)
{
	//finds all combinations, for each combination calls -matches- function

	for (int i = 0; i < n; i++) {
		int count = 0;
		if (arr[i] == 1) {				//check if i is match
			for (int j = i + 1; j < n; j++) {		//check right side
				if (count == k && arr[j] == 1) {
					matches(arr, n, k, i, arrSolution, layer, countSol);
				}
				count += arr[j];
			}
			count = 0;
			for (int j = i - 1; j >= 0; j--) {                //check left side
				if (count == k && arr[j] == 1) {
					matches(arr, n, k, -i, arrSolution, layer, countSol);
				}
				count += arr[j];
			}
		}
	}
}


void undoMove(int arr[], int n, int k, int move, int *layer)
{
	*layer = *layer - 1;
	if (move >= 0) {
		int count = 0;
		for (int i = move + 1; i < n; i++) {
			if (count == k && arr[i] == 2) {
				arr[i] = 1;
				arr[move] = 1;
			}
			count += arr[i];
		}
	}

	else {
		int count = 0;
		for (int i = abs(move) - 1; i >= 0; i--) {
			if (count == k && arr[i] == 2) {
				arr[i] = 1;
				arr[abs(move)] = 1;
			}
			count += arr[i];
		}
	}

}

void printSolution(int arrSolution[], int layer, int countSol)
{
	for (int i = 0; i < layer; i++) {
		if (arrSolution[i] < 0) {
			if (i == layer - 1)
				printf("%dL\n", abs(arrSolution[i]));
			else
				printf("%dL,", abs(arrSolution[i]));
		}
		else {
			if (i == layer - 1)
				printf("%dR\n", arrSolution[i]);
			else
				printf("%dR,", arrSolution[i]);
		}
	}
}




int main() {
	int n = 0, k = 0, layer = 0, countSol = 0;		//layer of moves
	int * arr;
	int * arrSolution;
	if (getInput(&n, &k) == 0) {
		printf("Nespravny vstup.\n");
		return 1;
	}

	arr = createArr(n);
	fillArr(arr, n);
	arrSolution = createArr(( n / 2 ) + 1);

	findAllCombinations(arr, n, k, arrSolution, &layer, &countSol);
	printf("Celkem reseni: %d\n", countSol);
	free(arr);
	free(arrSolution);
	return 0;
}

void matches(int arr[], int n, int k, int move, int arrSolution[], int * layer, int * countSol)
{
	makeMove(arr, n, k, move, arrSolution, layer);
	if (possibleMove(arr, n, k) == 0) {
		if (checkArr(arr, n) == 1) {
			*countSol = *countSol + 1;
			printSolution(arrSolution, *layer, *countSol);
		}
		//else
			//printf("Spatne\n");
	}
	findAllCombinations(arr, n, k, arrSolution, layer, countSol);

	undoMove(arr, n, k, move, layer);


}
