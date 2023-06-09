#include<stdio.h>
#include<stdlib.h>

void binarysearch(int a[], int first, int last, int s){
    int mid, count = 0;

    printf("\nEnter value to find: ");
    scanf("%d", &s);

    while(first <= last){
        count++;
        mid = first + (last - first) / 2;
        
        if(a[mid] == s){
            printf("\n%d found at location: %d", s, mid+1);
            printf("\nNo. of search operation: %d\n", count);
            break;
        }
        else if(a[mid] < s){
            first = mid + 1;
        }
        else{
            last = mid - 1;
        }   
    }

    if(first > last){
        printf("\n%d is not found!!!\n", s);
    }
}

void interpolationsearch(int a[], int first, int last, int s){
    int pos, count = 0;
    
    printf("\nEnter value to find: ");
    scanf("%d", &s);

    while(first <= last){
        if(first == last){
            pos = first;
        }
        else{
            pos = first + ((last - first) * ((float)(s - a[first]))  / (a[last] - a[first]));
        }
        
        count++;
        
        if(a[pos] == s){
            printf("\n%d found at location: %d", s, pos+1);
            printf("\nNo. of search operation: %d\n", count);
            break;
        }
        else if(a[pos] < s){
            first = pos + 1;
        }
        else{
            last = pos - 1;
        }
    }
    
    if(first > last){
        printf("\n%d is not found!!!\n", s);
    }
}

int main(){
    int a[50], n, c, s, choice;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("\nEnter %d integers ascending order: ", n);

    for (c = 0; c < n; c++){
        scanf("%d", &a[c]);
    }

    while(1){
        printf("\n1 --> Binary Search");
        printf("\n2 --> Interpolation Search");
        printf("\n3 --> Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1: binarysearch(a, 0, n -1, s);
                    break;
            
            case 2: interpolationsearch(a, 0, n -1, s);
                    break;
            
            case 3: exit(0);

            default: printf("\n\nWorng choice!! Please enter valid choice?\n");
        }
    }

    return 0;
}