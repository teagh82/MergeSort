#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 9999  

static void merge(int list[], int left, int mid, int right) { 
    int i, j, k = left, l;
    static int sorted[MAX_SIZE];

	printf("\n");
	//printf("[MERGE]   LEFT: %d     RIGHT: %d", list[left], list[right]);  
	printf("[MERGE]   LEFT: ");
	for(int x = left; x <= mid; x++)
		printf("%2d ", list[x]);
	printf("	  RIGHT: ");
	for(int y = mid+1; y <= right; y++)
		printf("%2d ", list[y]);
	printf("\n\n");

    for( i=left, j=mid+1 ; i<=mid && j<=right ; ) 
		sorted[k++] = (list[i]<=list[j]) ? list[i++] : list[j++];
    if( i > mid )
		for( l=j ; l<=right ; l++, k++ )
			sorted[k] = list[l];
    else
		for( l=i ; l<=mid ; l++, k++ )
			sorted[k] = list[l];
	for( l=left ; l<=right ; l++ ) 
		list[l] = sorted[l];
}   

void merge_sort ( int list[], int left, int right ) { 
	printf("[DIVIDE] left=%d, right=%d : ", left, right);
	for( int i=left ; i<=right ; i++ )
		printf("%3d", list[i]);
	printf("\n");
	
	if( left<right ) {
		int mid = (left+right)/2;	
		merge_sort(list, left, mid);
		merge_sort(list, mid+1, right);
		merge(list, left, mid, right);
	}
}

// �迭�� ȭ�鿡 ���� ���� ����ϴ� �Լ�. ����Ʈ �Ű����� ���
static void printArray( int arr[], int n, char *str="Array" )
{
    printf("%s = ", str);
    for( int i=0 ; i<n ; i++ )
       printf("%3d", arr[i]);
    printf("\n");
}

void main()
{
	int list[8] = { 27, 10, 12, 20, 25, 13, 15, 22 };
	printArray( list, 8, "Original" );	// ���� �� �迭 ��� 
	merge_sort( list, 0, 7); 		// ��� ���� ���� 
	printArray( list, 8, "Merge Sorting" );	// ���� �� �迭 ��� 

	system("pause");
}