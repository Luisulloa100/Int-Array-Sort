/******************************
This program will implement six sorting algorithms on an array of randomly generated number 
 ******************************/
#include <iostream>
#include <cstdlib>
using namespace std;

//prototypes
void initArray(int A[], int len);
void selectionSort(int A[], int len);
void bubbleSort(int A[], int len);
void insertionSort(int A [], int len);
void quickSort(int A[],int len);
void quickSortFunc(int A[], int low, int high);
void mergeSort(int A[],int len);
void heapSort(int A[], int len);
void printArray(int A[], int len);
void swap(int &x, int &y);
void mergeSort(int A[], int len);
void mergeSortFunc(int A[], int l, int r);
void merge(int A[], int l, int m, int r);
int partition(int A[], int low, int high);
void heapify(int A[], int n, int i);

/******************************
Main function will create an array of integers and call all six sorting algorithms
 ******************************/
int main()
{
  int size = 10;//set the size of the array
  int array[size];//initialize the array

  initArray(array,size);//initialize the array before every sorting algorithm
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size);

  selectionSort(array,size);
  cout<<"\tSelection Sort:"<<endl;
  printArray(array,size);

  initArray(array,size);
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size);

  bubbleSort(array,size);
  cout<<"\tBubble Sort:"<<endl;
  printArray(array,size);

  initArray(array,size);
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size);

  insertionSort(array,size);
  cout<<"\tInsertion Sort:"<<endl;
  printArray(array,size);

  initArray(array,size);
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size); 

  quickSort(array,size);
  cout<<"\tQuick Sort:"<<endl;
  printArray(array,size);

  initArray(array,size);
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size); 
  
  mergeSort(array,size);
  cout<<"\tMerge Sort:"<<endl;
  printArray(array,size);

  initArray(array,size);
  cout<<"\n\tOriginal Array:"<<endl;
  printArray(array,size); 

  heapSort(array,size);
  cout<<"\tHeap Sort:"<<endl;
  printArray(array,size);
}

/******************************
This function will initialize the array storing random numbers into it
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void initArray(int A[], int len)
{
  srand(time(0));//rand seed time
  int s = 0;//count
  for(s;s < len;s++)//create array sized len of random numbers
    {
      int num = rand()%100+1;
      A[s] = num;
    }
}

/******************************
This function will implement the selection sort algorithm
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void selectionSort(int A[], int len)
{
  int f,n,min;

  for(f=0;f<len-1;f++)//loop through the array
    {
      min = f;//set first value to smallest value
      for(n = f+1; n < len; n++)//loop through array length - 1
	if(A[n] < A[min])//if value is smaller than the one in min then that value beecomes min
	   min = n;
      swap(A[min], A[f]);//swap the two values
    }
}

/******************************
This function will implement the bubble sort algorithm
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void bubbleSort(int A[], int len)
{
  int f,n;

  for(f = 0; f < len-1; f++)//loop through the array
    for(n = 0;n<len-1;n++)//loop through array length - 1
      if(A[n] > A[n+1])//if value is greater than the one we are currently at then "bubble it to the top"
	swap(A[n], A[n+1]);//swap those two values
}

/******************************
This function will implement the insertion sort algorithm 
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void insertionSort(int A [], int len)
{
  int f,n,key;

  for(f = 1;f<len;f++)//loop through array
    {
      key = A[f];//current num is our key
      n = f - 1;
      while(n >= 0 && A[n] > key)//while value is greater than 0 and greater than our key
	{
	  A[n+1] = A[n];
	  n = n - 1;
	}
      A[n + 1] = key;//set key to next value
    }
}

/******************************
This function will implement the quick sort algorithm
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void quickSort(int A[], int len)
{//Inorder to call quickSort with only two parameters, we have to set the initial low and high
  quickSortFunc(A,0,len-1);//call quicksort
}

/******************************
This function will implement quickSort recursivley
Parameters: int A[] - main array, int low - low limit, int high - high limit
Return: void 
******************************/
void quickSortFunc(int A[], int low, int high)
{
  if(low >= high)//base case
    return;
  else
    {
      int temp = partition(A,low,high);//get pivot by calling partition
      quickSortFunc(A,low,high-1);//quicksort left subarray
      quickSortFunc(A,low+1,high);//quicksort right subarray
    }
}

/******************************
This function will implement the merge sort algorithm
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void mergeSort(int A[], int len)
{//To call mergeSort with 2 parameters, set the initial limits
  mergeSortFunc(A,0,len-1);
}

/******************************
This function will implement the mergeSort recursivley
Parameters: Int A[] -  main array, int l - left index, int r - right index
Return: void
 ******************************/
void mergeSortFunc(int A[], int l, int r)
{
  if(l < r)//while index's havnt crossed
    {
      int m = l + (r - l)/2;//middle point
      mergeSortFunc(A,l,m);//mergesort the left subarray
      mergeSortFunc(A,m+1,r);//mergesort the right subarray

      merge(A,l,m,r);//merge the two subarrays
    }
}

/******************************
This function will implement the heap sort algorithm
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void heapSort(int A[], int len)
{
  //build heap
  for(int i = len/2-1; i>=0;i--)
    heapify(A,len,i);

  //take an element from heap one by one
  for(int i = len - 1; i>=0; i--)
    { 
      swap(A[0],A[i]);//swap current value to end
      
      heapify(A, i, 0);//min heap
    }
}

/******************************
This function will print the array in order
Parameters: int A[] - the array , int len - the size of the array
Return: void
 ******************************/
void printArray(int A[], int len)
{
  int s = 0;

  for(s;s<len;s++)//loop through array
    cout<<A[s]<<" ";//print out value 
  cout<<endl<<endl;
}

/******************************
This function will swap two values within the array
Parameters: int &x - address of first value, int &y - address of second value
Return: void
 ******************************/
 void swap(int &x, int &y)
 {
   int temp = x;//place first value into temporary int
   x = y;//place y into x
   y = temp;//make y the valu in temporary holder
 }

/******************************
This function will merge the two subarrays created by mergeSort
Parameters: int A[] - main array, int l - left index, int m - middle index, int r - right index
Return: void
 ******************************/
void merge(int A[], int l, int m, int r)
{
int x,y,z;
 int sub1 = m - l + 1;//size of left subarray
 int sub2 = r - m;//size of right subarray

 int leftA[sub1], rightA[sub2];//create two temporary arrays
 //copy the two subarrays into the temporarys
 for(x = 0;x < sub1; x++)
   leftA[x] = A[l + x];
 for(y = 0; y < sub2; y++)
   rightA[y] = A[m + 1 + y];
 //indexes of the arrays
 x = 0;
 y = 0;
 z = l;
 
 while(x < sub1 && y < sub2)//go through the two subarrays and copy into the maina array
   {
     if(leftA[x] <= rightA[y])
       {
	 A[z] = leftA[x];
	 x++;
       }
     else
       {
	 A[z] = rightA[y];
	 y++;
       }
     z++;
   }

 while(x  < sub1)//if theres any values left on left side
   {
     A[z] = leftA[x];
  x++;
 z++;
   }
 while(y < sub2)//if theres any values left on right side
   {
     A[z] = rightA[y];
     y++;
     z++;
   }
}

/******************************
This function partitions the main array into sorted sub arrays
Parameters: int A[] - main array, int low - low limit, int high - high limit
Return: pivot
 ******************************/
int partition(int A[], int low, int high)
{
  int pivot = A[low];//pivot point
  int temp;
  int k = temp = low + 1;//smaller element
  
  while(k <= high)//while havnt reached limit of subarray
    {
      if(A[k] <= pivot)//if current value is less than equal to our pivot then swap them
	swap(A[temp++],A[k]);
      k++;
    }
  swap(A[low],A[temp-1]);//swap low with pivot
  return temp-1;//return pivot
}

/******************************
This function will create a heap recursivley given an array 
Parameters: int A[] -  main array, int n - size, int i - current value
 ******************************/
void heapify(int A[], int n, int i)
{
  int largest = i;//largest value is begining
  int l = i * 2 + 1;//left side
  int r = i * 2 + 2;//right side

  if(l<n && A[l] > A[largest])//left child is greater than root
    largest = l;

  if(r<n && A[r]>A[largest])//right child is greater than root
    largest = r;

  if(largest != i)//if root isnt largest
    {
      swap(A[i], A[largest]);//swap it with largest
      
      heapify(A, n, largest);//recursive build heap of subtree
    }
}
