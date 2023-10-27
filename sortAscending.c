#include <stdio.h>

/* This program shows how I used printArray(), findSmallest(), swap() and sortAscending() to complete the requirements
   of the assignment; I have also given a quick snippet of the code (which is commented) to show how I used these methods
   without any parameters of the assignment*/

void printArray(int[], int, int); // using this function to print the array 
void findSmallest(int[], int, int); // using this function to find the smallest value in an array
void swap(int[], int, int); // using this function to swap the element with each other of the array
void sortAscending(int[], int); // using this method to print the array in an ascending list

int main(int argc, char** argv){
    int array[] = {5, 8, 7, 2, 1, 4, 6, 3, 10, 9}; // Making an array with 10 elements
    int size = sizeof(array) / sizeof(int); // making a variable sizeof(array)/sizeof(int) for easy use instead of typing the whole thing
    int marker = 0; // using a marker an initializing it to 0 (more information will be given regarding this in printArray())
    printArray(array, size, marker); // calling the printArray() method to print all the arrays
    findSmallest(array, size, marker); // calling the method which finds the smallest element in the array (it also prints the number which is smallest on the right side of the marker)
    printf("Array after swapping:\n");// message that the swapping of the marker's elment and smallest elment is being displayed
    swap(array, size, marker); // calling the method
    printArray(array, size, marker); // printing the array (where the marker and the smallest element numbers are swapped)
    sortAscending(array, size); //calling upon the sortAscending() which ascends the marker and also displays the array in an ascending way
    marker = size - 1;  // setting the marker the element before it
    printf("\nArray in ascending order with marker at the end:"); // message which notifies one that the arrays anticipated will be displayed in an ascending form
    printArray(array, size, marker); // printing the array and does the 6th requirement of the assignment
    return 0;
}

void printArray(int array[], int size, int marker){ // prints the array elements
// this method does the 1st and 2nd requirement of the assignment
// It places the marker at the first element of the array
// It also stops the marker once it reaches the last element
    printf("\nArray Elements: "); // message 
    for (int i = 0; i < size; i++) { // using for loop to go through the elements of the array
        if (i == marker) { // if the index (which the program is on), is the marker then nothing could be printed (or one can add [MARKER], to see where the marker is)
            printf(""); // empty string
        }
        printf("%d ", array[i]); // printing the array elements
    }
    if (marker == size) { // if the marker is at the end of the array (marker value is same as the size)
        printf("[Marker] "); // then the '[Marker]' will be printed
        return; // using return to stop the movement of the marker (one can also use exit(), but I chose return)
    }
}


void findSmallest(int array[], int size, int marker){ // method to find the smallest element to the right side of the marker
// this method does the 3rd requiremnt of the assignment
// it finds the smallest element to the right hand side of the marker's element and also displays it
	int smallestRight = array[marker]; // intializing the variable 'smallestRight' to the element value of the marker
    for(int i = marker + 1; i < size; i++){ // using loop to go through the elements of the right hand side of the array
        if(array[i] < smallestRight){ // if the value of the current looped-value is less than the marker's element value
            smallestRight = array[i]; // change the smallest right value to that element number
        }
    }
    printf("\nSmallest element to the right of the marker is: %d", smallestRight); // prints the message that and displays the smallest element 
}

void swap(int array[], int size, int marker){ // method which swaps the markers array with the smallest element
// this method does the 4th requirement of the assignment
// it replaces the smaller element with the marker element (swaps it) and displays it in the main method (once called)
    int smallestElement = marker; // initializing the marker with 'smallestElement'
    int markedElement = array[marker]; // initializing the 'markedElement' with the value of marker's index
    for(int i = marker + 1; i < size; i++){ // loop which is from the markers position to the end of the array
        if (array[i] < markedElement){ // if the element is smaller than 'markedElement'
            markedElement = array[i]; // it changes the value of 'markedElement' with the smallest element value
            smallestElement = i; // and this changes the value of 'smallestElement' value to the marked variable value
        }
    }
    int temp = array[marker]; // temporary variable is created to equate it to the value of marker's element
    array[marker] = markedElement; // value of marker element is replaced with the smallest element
    array[smallestElement] = temp; // value of the smallest element is replaced with the marker element
}	

void sortAscending(int array[], int size) { // method which advances the marker and also arranges the elements in an ascending order
// this method does the 5th requirement of the assignment
// the array elements are displayed in ascending order    
	for (int i = 0; i < size - 1; i++) { // loop to pass through the array
        for (int j = 0; j < size - i - 1; j++) { // loop to compare elements with each other (array elements)
            if (array[j] > array[j + 1]) { // if the element which is currently used greater than the next element
                int temp = array[j]; // temporary variable which is equated to the current element
                array[j] = array[j + 1]; // replaces the current element with next element (j+1)
                array[j + 1] = temp; // replaces the next element (j+1) with temporary variable
            }
        }
    }
}

/*----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

/* This program is just to show the use of printArray(), findSmallest(), swap() and sortAscending() functionality
   It also shows the user the ability of my program to use such methods without the parameters of sortAscending algorithims (from the assignment)
   to see the function, uncomment this code and comment the previous code*/
/*
void printArray(int[], int, int); // using this function to print the array 
void findSmallest(int[], int, int); // using this function to find the smallest value in an array
void swap(int[], int); // using this function to swap the element with each other of the array
void sortAscending(int[], int); // using this method to print the array in an ascending list

int main(int argc, char** argv){
	int array[] = {5,8,7,2,1,4,6,3,10,9}; // Making an array with 10 elements
	int size = sizeof(array)/sizeof(int); // making a variable sizeof(array)/sizeof(int) for easy use instead of typing the whole thing
	printf("Original Array: ");  // printing the original array
	printArray(array, size, 0); // calling the printArray() method to print all the arrays
	findSmallest(array, size, 0); // calling the method which finds the smallest element in the array (it also prints the number which is smallest)
	swap(array,size); // calling the swap method which swaps each element with another to show the functionality of swap method
	printArray(array,size, 0); // printing the swap()
	sortAscending(array, size); // calling the sortAscending() which prints the array in an ascending form
    printf("\nArray in ascending order: "); 
    printArray(array, size, 0); // calling printArray() to print the array which is in an ascending form now
	return 0;
}

void printArray(int array[], int size, int index){ // method which prints the array 
	if(index < size){ // if the elements are in the same array as them
		printf("%d ", array[index]); // prints the element
		printArray(array, size, index + 1); // calls the next elements and prints it (index + 1)
	}
}

void findSmallest(int array[], int size, int index){ // method which finds the lowest value in the array 
	int minimum = array[0]; // initializing minimum variable to the first element (temporarily)
	for(index = 1; index < size; index++){ // using a for loop so that I can go over the entire array's element to find the smallest number
		if(array[index] < minimum){ // this if statement verfies if the element is smaller than the elements of the array
			minimum = array[index]; // if it is then the 'minimum' is changed/updated
		}
	}
	printf("\nSmallest element present in the entire array: %d\n", minimum); // this is a message which is displayed in the main method and it displays the minimum value
}

void swap(int array[], int size){ // method which swaps each value of the array with another
	for(int i = 0; i < size - 1; i = i+2){ // used for loop in order for the program to swap them
     	int temp = array[i]; // swapping of each element with the next element, using the temp variable to equate it to the element of the array
        array[i] = array[i + 1]; // moving the temp variable and swapping it in the position of the old element
        array[i + 1] = temp; // moving the old element to be swapped with the temp element's position
    }
    printf("Swapped all elements of the array with each other: "); // printing the entire array (in the main method, this is just a message)
}

void sortAscending(int array[], int size) { // method which prints all the elements in the array in an ascending way
    for (int i = 0; i < size - 1; i++) { // I used the bubbleSort.c program to get an idea on how to this
        for (int z = 0; z < size - i - 1; z++) { // I put the entire set in a loop (in order to print the while array) 
            if (array[z] > array[z + 1]) { // compared the values of each element to see which one is bigger
                int pos = array[z];
                array[z] = array[z + 1];
                array[z + 1] = pos; //changed their position accordingly so that they could be in an ordered form
            }
        }
    }
}
*/


