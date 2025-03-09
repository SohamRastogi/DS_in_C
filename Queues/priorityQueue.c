#include<stdio.h>

#define N 10
int arr[N];
int priority[N];
int front = 0;
int rear = -1;



void enqueue(int data, int weight)
{
    if(rear == N-1) printf("overflow");
    rear++;
    arr[rear] = data;
    priority[rear] = weight;
    return ;
}

void dequeue()
{
    if(rear < 0) printf("empty");
    printf("the deleted element is : %d\n",arr[rear]);
    
    if(rear == 0) rear = -1;
    else rear --;

    return  ;
}

// void sort(int* ptr , int n){

//     for(int i = 0 ; i < n-1 ; i++){
//         for(int j = 0 ; j < n-1 ; j ++){
//             if(ptr[j] > ptr[j+1]){
//                 int temp ;
//                 temp = ptr[j];
//                 ptr[j] = ptr[j+1];
//                 ptr[j+1] = temp;
//             }
//         }
//     }
    
//     return ;
// }

void display()
{
    // empty check
    for(int i = rear ; i >=front ; i--){
        printf("%d ",arr[i]);
    }
    return ;
}


int main()
{

    // enqueue(value , priority)

    enqueue(10,5);
    enqueue(5,10);
    enqueue(20,6);
    enqueue(30,4);

    // dequeue();
 
    // arr[0] = 10;  priority[0] = 5;
    // arr[1] = 5;   priority[1] = 10;
    // arr[2] = 20;  priority[2] = 6;
    // arr[3] = 30;  priority[3] = 4;

    for(int i = 0 ; i < 3 ; i ++){
        for(int j = 0 ; j < 3 ; j++){
            if(priority[j] > priority[j+1]){
                int temp;
                temp = priority[j];
                priority[j] = priority[j+1];
                priority[j+1] = temp;
                int temp2;
                temp2 = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp2;
            }
        }
    }

    // for(int i = 0 ; i < 4 ; i ++){
    //     printf("%d ",priority[i]);
    // }
    // printf("\n");
    // for(int i = 0 ; i < 4 ; i ++){
    //     printf("%d ",arr[i]);
    // }

    dequeue();
    display();

    return 0 ;

}