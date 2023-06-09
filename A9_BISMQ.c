#include<stdio.h>
#include<stdlib.h>

int arr[50], num;

void bsort();
void isort();
void ssort();
void msort();
void qusort();

int main(){ 
    int choice;
    
    while(1){
        printf("\n\n1 --> Bubble Sort");
        printf("\n2 --> Insertion Sort");
        printf("\n3 --> Selection Sort");
        printf("\n4 --> Merge Sort");
        printf("\n5 --> Quick Sort");
        printf("\n6 --> Exit");

        printf("\n\nEnter Choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: bsort();
                    break;
            
            case 2: isort();
                    break;
            
            case 3: ssort();
                    break;

            case 4: msort();
                    break;
            
            case 5: qusort();
                    break;

            case 6: exit(0);

            default: printf("\n\nWorng choice!! Please enter valid choice?\n");
        }
    }

    return 0;
}

void bsort(){
    int i, c, d, temp;

    printf("\nEnter size of array: ");
    scanf("%d", &num);
 
    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }

    for (c = 0; c < num - 1; c++){
        for (d = 0; d < num - c - 1; d++){
            if (arr[d] > arr[d + 1]){
                temp = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = temp;
            }
        }
    }

    printf("\n\nSorted order: ");
    for (c = 0; c < num; c++){
        printf("%d ", arr[c]);
    }
}

void isort(){   
    int i, c, d, temp;

    printf("\nEnter size of array: ");
    scanf("%d", &num);
 
    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }

    for(c = 1; c < num; c++){
        temp = arr[c];
        d = c - 1;
        while((temp < arr[d]) && (d >= 0)){
            arr[d + 1] = arr[d];
            d = d - 1;
        }
        arr[d + 1] = temp;
    }

    printf("\n\nSorted order: ");
    for(c = 0; c < num; c++){
        printf("%d ", arr[c]);
    }
}

void ssort(){
    int i, c, d, temp;

    printf("\nEnter number of elements: ");
    scanf("%d", &num);

    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }
    
    for(c = 0; c < num - 1; c++){
        i = c;
        for(d = c + 1; d < num; d++){
            if(arr[i] > arr[d]){
                i = d;
            }
        } 
        if(i != c){
            temp = arr[c];
            arr[c] = arr[i];
            arr[i] = temp;
        }
    }

    printf("\n\nSorted order: ");
    for(c = 0; c < num; c++){
        printf("%d ", arr[c]);
    }
}

void msort(){
    void merge(int arr[], int left, int mid, int right){ 
        int i, j, k; 
        int n1 = mid - left + 1; 
        int n2 = right - mid; 
        
        int L[n1], R[n2]; 

        for(i = 0; i < n1; i++) 
            L[i] = arr[left + i]; 

        for(j = 0; j < n2; j++) 
            R[j] = arr[mid + 1 + j];

        i = 0; 
        j = 0; 
        k = left;

        while(i < n1 && j < n2){ 
            if(L[i] <= R[j]){ 
                arr[k] = L[i]; 
                i++; 
            } 
            else{ 
                arr[k] = R[j]; 
                j++; 
            } 
            k++; 
        }

        while(i < n1){ 
            arr[k] = L[i]; 
            i++; 
            k++; 
        }

        while(j < n2){ 
            arr[k] = R[j]; 
            j++; 
            k++; 
        }
    } 

    void mergeSort(int arr[], int left, int right){ 
        if(left < right){
            int mid = left + (right - left) / 2; 

            mergeSort(arr, left, mid); 
            mergeSort(arr, mid + 1, right); 
            merge(arr, left, mid, right); 
        } 
    }

    int i, c;

    printf("\nEnter size of array: ");
    scanf("%d", &num);
    
    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }

    mergeSort(arr, 0, num - 1);
        
    printf("\n\nSorted order: ");
    for(c = 0; c < num; c++){
        printf("%d ", arr[c]);
    }
}

void qusort(){
    int partition(int arr[], int start, int end){
        //select the rightmost element as pivot  
        int pivot = arr[end];  
        //pointer for greater element
        int i = (start - 1);  

        //traverse each element & compare them with the pivot    
        for(int j = start; j <= end - 1; j++){  
            if(arr[j] < pivot){
                //if  element smaller than pivot is present
                //swap it with the greater element pointed by i
                i++;  
                int t = arr[i];  
                arr[i] = arr[j];  
                arr[j] = t;  
            }
        }

        //swap the pivot element with the greater element at i
        int t = arr[i+1];  
        arr[i+1] = arr[end];  
        arr[end] = t;  
        
        //partition point
        return (i + 1);  
    }  
    
    void quick(int arr[], int start, int end){  
        if(start < end){  
            int p = partition(arr, start, end);
            //smaller than pivot are on left of pivot  
            quick(arr, start, p - 1);  
            //greater than pivot are on right of pivot
            quick(arr, p + 1, end);
        }  
    }

    int i, c;
  
    printf("\nEnter size of array: ");
    scanf("%d", &num);
    
    printf("\nEnter %d elements in the array: ", num);
    for(i = 0; i < num; i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i = 0; i < num; i++){
        printf("%d  ", arr[i]);
    }

    quick(arr, 0, num - 1);  

    printf("\n\nSorted order: ");
    for(c = 0; c < num; c++){
        printf("%d ", arr[c]);
    }
}