#include<stdio.h>
#include<stdlib.h>
#define MAX 100

int main(){
    int arr[MAX], i, num, pos, value, r, s, count=0;
    printf("\nEnter size of array: ");
    scanf("%d", &num);
 
    printf("\nEnter %d elements in the array: ", num);
    for(i=0;i<num;i++){
        scanf("%d", &arr[i]);
    }

    printf("\nInitial array: ");
    for(i=0;i<num;i++){
        printf("%d  ", arr[i]);
    }

    int choice;
    while(1){
        printf("\n\n1 --> Insert an element at the any position of the array");
        printf("\n2 --> Delete an element from a given position of the array");
        printf("\n3 --> Replace the element of a given position with another number");
        printf("\n4 --> Search if an element exists in the list");
        printf("\n5 --> Display the aarray elements");
        printf("\n6 --> Exit");
        
        printf("\nEnter your choice(1 to 6): ");
        scanf("%d", &choice);

        switch(choice){
            case 1: printf("\nEnter the position where you want to insert: ");
                    scanf("%d", &pos);
                    
                    printf("\nEnter the value into that position: ");
                    scanf("%d", &value);
                    for(i=num-1;i>=pos-1;i--)
                        arr[i+1]=arr[i];
                        arr[pos-1]=value;
                        num=num+1;
                        printf("\n %d inserted in array", value);
                    break;

            case 2: printf("\nEnter the position to delete element: ");
                    scanf("%d", &pos);
                    for(i = pos - 1; i < num; i++)
                        arr[i] = arr[i+1];
                        num = num - 1;
                        printf("\n Position %d deleted in array", pos);
                    break;

            case 3: printf("\nEnter which new element you want to insert: ");
                    scanf("%d",&value);
                    
                    printf("\nEnter the position to insert new element: ");
                    scanf("%d",&pos);
                    
                    arr[pos-1]=value;
                    printf("\n %d replaced at position %d in array", value, pos);
                    break;
            
            case 4: printf("\nEnter the number to search: ");
                    scanf("%d",&s);

                    for ( r = 0 ; r < num ; r++ ){
                        if ( arr[r] == s ){
                            printf("\n %d is present at location %d.", s, r+1);
                            count++;
                        }
                    }
                    if ( count == 0 ){
                        printf("\n %d is not present in array.", s);
                    }
                    else{
                        printf("\n %d is present %d times in array.", s, count);
                    }
                    break;
            
            case 5: printf("\nFinal array elements: ");
                    for(i=0;i<num;i++){
                        printf("%d  ", arr[i]);
                    }
                    break;

            case 6: exit(0);

            default:printf("\n\nWorng choice!! Please enter valid choice(1-6)? ");
        }
    }
}