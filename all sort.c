#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void BubbleSort(int a[], int n);
void InsertionSort(int a[], int n);
void SelectionSort(int a[], int n);
void MergeSort(int a[], int low, int high);
void Merge(int a[], int low, int mid, int high);
void QuickSort(int a[],int low,int high);
int partition(int a[],int low,int high);
void HeapSort(int a[],int n);
void BuildMaxHeap(int a[],int n);
void Heapify(int a[],int n,int i);



int main() {
    int n, a[20], choice;

    printf("Enter the size of the array: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    while (1) {
        printf("\nSelect a sorting method:\n");
        printf("1. Bubble Sort\n2. Insertion Sort\n3. Selection Sort\n4. Merge Sort\n5.Heap Sort \n6.Quick Sort\n7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); // Input choice before the switch

        switch (choice) {
            case 1:
                BubbleSort(a, n);
                printf("Bubble Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

            case 2:
                InsertionSort(a, n);
                printf("Insertion Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

            case 3:
                SelectionSort(a, n);
                printf("Selection Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

            case 4:
                MergeSort(a, 0, n - 1);
                printf("Merge Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

                 case 5:
                HeapSort(a, n);
                printf("Heap Sort Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

                 case 6:
                QuickSort(a, 0, n - 1);
                printf("Quick Sort: Sorted array:\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t", a[i]);
                }
                printf("\n");
                break;

            case 7:
                printf("Exiting the program.\n");
                exit(0);

            default:
                printf("Invalid choice! Please select a valid option.\n");
                break;
        }
    }

    return 0;
}

// Bubble Sort Function
void BubbleSort(int a[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (a[j] > a[j + 1]) {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

// Insertion Sort Function
void InsertionSort(int a[], int n) {
    for (int i = 1; i < n; i++) {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// Selection Sort Function
void SelectionSort(int a[], int n) {
    int i,j,temp;
   
        for(i=0;i<=n-1;i++){
            for(j=i+1;j<n;j++){
                if(a[i]>a[j]){
                temp=a[i];
                a[i]=a[j];
                a[j]=temp;
                }
              
            }
        }
}

// Merge Sort Function
void MergeSort(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(a, low, mid);
        MergeSort(a, mid + 1, high);
        Merge(a, low, mid, high);
    }
}

// Merge Function
void Merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int b[20]; // Temporary array

    // Merging the two halves
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copying remaining elements from left half
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copying remaining elements from right half
    while (j <= high) {
        b[k++] = a[j++];
    }

    // Copying the merged elements back into the original array
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

//heapsort
void HeapSort(int a[],int n){
    int i;
    BuildMaxHeap(a,n);
    for(i=n-1;i>=0;i--){
        int temp=a[0];
        a[0]=a[i];
        a[i]=temp;
        Heapify(a,i,0);
    }
}

void BuildMaxHeap(int a[],int n){
    for(int i=n/2-1;i>=0;i--){
        Heapify(a,n,i);
    }
}
void Heapify(int a[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && a[left]>a[largest])
        largest=left;
    if(right<n && a[right]>a[largest])
        largest=right;
    if(largest!=i){
        int temp=a[i];
        a[i]=a[largest];
        a[largest]=temp;
        Heapify(a,n,largest);
    }
}


//quicksort
   
void QuickSort(int a[],int low,int high){
  
    if(low<high){
          int j=partition(a,low,high);
    QuickSort(a,low,j);
    QuickSort(a,j+1,high);
    }  
}
int partition(int a[],int low,int high){
    int temp;
   int i=low;
   int j=high;
   int p=low;
   while(i<j){
    while(a[i]<=a[p])
        i++;
    while(a[j]>a[p])
        j--;
     if(i<j){
        temp=a[i];
        a[i]=a[j];
        a[j]=temp;
        }
    
   }
   temp=a[j];
   a[j]=a[p];
   a[p]=temp;
   return j;
}