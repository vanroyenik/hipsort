#include <stdlib.h>
#include <stdio.h>


void swap( int* a, int i, int j ) {
	a[i] = a[i] ^ a[j];
	a[j] = a[i] ^ a[j];
	a[i] = a[i] ^ a[j];
}

void siftDown( int* a, int n, int k ) {
	int leftIndex = 2 * k + 1;
	int rightIndex = 2 * k + 2;

	if( leftIndex >= n ) {
		return;
	}
	if( rightIndex >= n ) {
		if( a[k] > a[leftIndex] ) {
			swap( a, k, leftIndex );
			siftDown( a, n, leftIndex );
		}

		return;
	}

	if( a[k] <= min( a[leftIndex], a[rightIndex] ) ) {
		return;
	}


	if( a[leftIndex] < a[rightIndex] ) {
		swap( a, k, leftIndex );
		siftDown( a, n, leftIndex );
	} else {
		swap( a, k, rightIndex );
		siftDown( a, n, rightIndex );
	}
}

void heapSort( int* a, int n ) {
	int i;
	int itemsLeft = n;

	for( i = n - 1; i >= 0; i-- ) {
		siftDown( a, n, i );
	}
	while( itemsLeft > 1 ) {
		swap( a, 0, itemsLeft - 1 );
		itemsLeft--;
		siftDown( a, itemsLeft, 0 );
	}
	for( i = 0; i < n / 2; i++ ) {
		swap( a, i, n - i - 1 );
	}
}

int main() {
	int n = 10; // У нас в массиве будет 10 элементов
	int* a;
	int i;
	a = malloc( n * sizeof( int ) );
	for( i = 0; i < n; i++ ) {
		a[i] = rand() % 1000;
		printf( "%d ", a[i] );
	}
	printf( "\n" );
	heapSort( a, n );
	for( i = 0; i < n; i++ ) {
		printf( "%d ", a[i] );
	}
	printf( "\n" );
	free( a );
	return 0;
}
