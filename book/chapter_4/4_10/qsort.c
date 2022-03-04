#include <stdio.h>

/*
 * qsort: sort v[left] ... v[right] into increasing order
 */

void qsort(int v[], int left, int right) {
	int i, last;
	void swap(int v[], int i, int j);
	if (left >= right)	// do nothing if array contains fewer than two elements
		return;
	swap(v , left , (left + right) / 2);	// move partition elem to v[0]
	last = left;
	for (i = left + 1; i <= right; i++)
		if (v[i] < v[left])
			swap(v, ++last, i);
	swap(v, left, last);
	qsort(v, left, last-1);
	qsort(v, last+1, right);
}

/*
 * swap: interchage v[i] and v[j]
 */
void swap(int v[], int i, int j)
{
	int temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void main(){
	int v[10] = {9, 8,7,6,5,4,3,2,1,0};
	int left = 0;
	int right = 9;
	qsort(v, left, right);
	for (int i = 0; i < 10; i++) {
		printf("%d ", v[i]);
	}
}
