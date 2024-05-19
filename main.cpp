//name: luis rodriguez
//Date: 03/12/2023
//class: cs311

#include <iostream>
using namespace std;

int partition(int arr[],int start,int end);
void bubbleSort(int A[],int len);
void display(int A[],int size);
void selectionSort(int A[],int n);
void insertionSort(int A[],int n);
void quickSort(int array[],int start,int end);
void merge(int A[], int q, int p, int r);
void mergeSort(int A[],int p, int r);

int main() {
int size = 0;
int input = 0;
int choice = 0;
cout << "Please input size of array" << endl;
cin >> size;
int array[size];
cout << "Please input values for the array! " << endl;
for (int i = 0; i < size; i++)
  {
    cin >> input;
    array[i] = input;
  }
  cout << "Your array is " << endl;
  display(array, size);
  cout << endl;
  
  cout << "Which sort would you like to use!?" << endl;
  cout << "1: bubble sort! 2: selection sort! 3: insertion sort! 4: quick sort! 5: merge sort" << endl;
  cin >> choice;
  if (choice == 1)
  {
    cout << "Now running Bubble Sort!" << endl;
    bubbleSort(array, 5);
    display(array,5);
    cout << endl;
  }
  else if(choice == 2)
  {
    cout << "Now running Selection Sort!" << endl;
    selectionSort(array,5);
    display(array, 5);
  }
  else if(choice == 3)
  {
      cout << "Now running Insertion Sort!" << endl;
      insertionSort(array,5);
      display(array, 5);
  }
  else if(choice == 4)
  {
      cout << "Now running quick sort!" << endl;
      quickSort(array, 0, 4);
      display(array, 5);
  }
  else if(choice == 5)
  {
      cout << "Now running Merge sort! " << endl;
      mergeSort(array, 0, 4);
      display(array,5);
  }
    else 
    {
      cout << "invalid input! try again!" << endl;
    }
}
void selectionSort(int A[],int n){
  int min_index;
for (int i = 0; i< n -1; i++)
  {
    min_index = i;
    for (int j = i + 1; j < n; j++)
      {
          if(A[j] < A[min_index])
          {
            min_index = j;
          }
        
      }
      if (min_index != i)
      {
        swap(A[i],A[min_index]);
      }

    
  }

  
}
void bubbleSort(int A[],int n){

for (int i = 0; i < n; i++)
  {
    bool flag = false;
    for (int j = 0; j < n-i -1; j++)
      {
        if(A[j] > A[j+1])
        {
          swap(A[j],A[j+1]);
        }
        else
        flag = true;
      }

  }
}
void insertionSort(int A[],int n){
  
  for (int i = 1; i < n; i++)
  {
    int index = A[i];
    int j = i - 1;

    while(j >= 0 && A[j] > index)
      {
        A[j+1] = A[j];
        --j;
      }
    
    A[j+1] = index;
    
  }
}

int partition(int A[],int start,int end){
  
  int pivot = A[end];
  int pivotindex = start;

  
  for (int i = start; i < end; i++)
    {
        if(A[i] <= pivot)
        {
          swap(A[i], A[pivotindex]);
          pivotindex++;
        }
        
    }
    swap(A[end],A[pivotindex]);
    

  return pivotindex;
  
}
void quickSort(int array[],int start,int end){
  int p;
  
  if (start >= end)
  {
    return;
  }
  
  p = partition(array, start, end);


  quickSort(array, start, p-1);
  quickSort(array, p+1, end);
}
void display(int A[],int size){
  
    for(int i = 0; i < size; i++)
      {
        cout << A[i] << " ";
      }
  }


void mergeSort(int A[],int p, int r){

  if(p == r) { return; }

  int q = (p+r) / 2;

  mergeSort(A, p, q);
  mergeSort(A, q+1,r);
  merge(A,q,p,r);
}
void merge(int A[], int q, int p, int r){
int i = p;
int k = 0;
int j = q+1;

int size = r - p + 1;
int b[size];
  
  while (i <= q && j <= r)
    {
      if(A[i] <= A[j])
      {
        b[k++] = A[i++];
      }
      else
      {
        b[k++] = A[j++];
      }
    }
  
      while(i<=q)
        {
          b[k++] = A[i++];
        }
      while(j <= r)
        {
          b[k++] = A[j++];
        }
  
         
        for (int i = p; i <= r; i++)
          {
           
            A[i] = b[i-p];
          }
      
    
  
}