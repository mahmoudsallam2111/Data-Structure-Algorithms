#include <iostream>

using namespace std;

void Swap( int *first,int *second)     /// fn to swap
{
    int temp  = *first;
    *first = *second;
    *second = temp;

}

void Bubblesort(int *arr, int size)
{
    int flag = 0;   ///flag to control no of iteration;
    for (int i=0 ; i<size-1 && flag==0 ; i++)   /// because if i arrange 5 item , the 6th by default will be sorted
    {
        flag=1;   /// to stop fn if its sorted

        for(int index = 0 ; index <size -1-i ; index++)
        {
            if(arr[index]>arr[index+1])
            {
                Swap(&arr[index],&arr[index + 1] );
                flag = 0;
            }

        }

    }


}


void selectionsort(int *arr,int size)
{
    for(int counter = 0 ; counter<size-1 ; counter++)
    {
        int miniIndex = counter;

        for(int index = 1+counter ; index<size ; index++)
        {
            if(arr[index]<arr[miniIndex])
                miniIndex = index;
        }

        Swap(&arr[counter],&arr[miniIndex]);

    }


}


void insertionsort(int *arr, int size)
{
    for (int counter = 1 ; counter<size ; counter++ )
    {
        int key = arr[counter];
        int index = counter-1;
        while( index >=0 && arr[index]>key)
        {
            arr[index+1] = arr[index];
            index--;
        }
        arr[index+1]=key;   /// is important;

    }
}


int BinarySearch(int *arr , int size , int data)
{
    int minIndex = 0;
     int maxIndex = size - 1;
     int midIndex;

    while(minIndex <= maxIndex)
    {
        midIndex = (minIndex + maxIndex)/2;

        if(data == arr[midIndex])
        {
            return midIndex;
        }else if(data>arr[midIndex])
        {
            minIndex = midIndex+1;
        }else
        {
            maxIndex = midIndex-1;
        }
    }

    return -1;
}


void display(int *arr,int size )
{
    for(int index  = 0 ; index <size; index++)
    {
        cout<<arr[index]<<endl;
    }
}

int main()
{
    int arr[]= {60, 65, 80, 90,100, 120};
    display(arr,6);
    cout<<"============="<<endl;

    ///  Bubblesort(arr,6);
    /// selectionsort(arr,6);
    /// insertionsort(arr,6);
   /// display(arr,6);

/*
int num;
cout<<"enter num u want to search :"<<endl;
cin>>num;
*/

   cout << "the index of the num is : " <<BinarySearch(arr,6,100)<<endl;

    return 0;
}
