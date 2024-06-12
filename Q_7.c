//Q7 Write a program in C to find the missing number in a given array. There are no duplicates in the list

// C program to remove duplicates 
#include <stdio.h> 

// Function to remove duplicate 
// elements This function returns 
// new size of modified array. 
int removeDuplicates(int arr[], int n) 
{ 
	// Return, if array is empty or 
	// contains a single element 
	if (n == 0 || n == 1) 
		return n; 

	int temp[n]; 

	// Start traversing elements 
	int j = 0; 

	// If current element is not equal 
	// to next element then store that 
	// current element 
	for (int i = 0; i < n - 1; i++) 
		if (arr[i] != arr[i + 1]) 
			temp[j++] = arr[i]; 

	// Store the last element as whether 
	// it is unique or repeated, it hasn't 
	// stored previously 
	temp[j++] = arr[n - 1]; 

	// Modify original array 
	for (int i = 0; i < j; i++) 
		arr[i] = temp[i]; 

	return j; 
} 


// Function to find the missing number in an array
int pickMissNumber(int *arr1, int ar_size) {    int i, sum = 0, n = ar_size + 1; 
   // Calculating the sum of all elements in the array    
for (i = 0; i < ar_size; i++) 
{        sum = sum + arr1[i];    } 
   // Calculating the missing number using the sum of the first 'n' natural numbers formula  

  return (n * (n + 1)) / 2 - sum;}

// Driver code 
int main() 
{       

    int arr[] = {1, 2, 2, 3, 4,4, 4, 5, 5};     
    int n = sizeof(arr) / sizeof(arr[0]);      
    // removeDuplicates() returns new     
    // size of array.     
    n = removeDuplicates(arr, n);      
    // Print updated array     
    for (int i = 0; i < n; i++)         
    printf("%d ", arr[i]);


    int i;  
    int arr1[] = {1, 3, 4, 2, 5, 6, 9, 8};   
    int ctr = sizeof(arr1) / sizeof(arr1[0]);
    // Displaying the given array  
    printf("The given array is :  ");    
    for (i = 0; i < ctr; i++) {
            printf("%d  ", arr1[i]);    } 
    printf("\n");  
    // Finding and displaying the missing number    
    printf("The missing number is : %d \n", pickMissNumber(arr1, ctr));    
    return 0;
    
} 
