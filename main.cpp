//
//  main.cpp
//  cs201hw2
//
//  Created by Isil Unveren on 18.11.2024.
//

#include <random>
#include <ctime>
#include <cstdlib>
#include <iostream>
using namespace std;

//functions to be used for algorithms and driving

//linear search function
int linearSearch (int* array, int arrSize, int key);
//recursive linear search function
int recursiveLinearSearch (int* array, int arrSize, int key);
//binary search function
int binarySearch (int* array, int arrSize, int key);
//jump search function
int jumpSearch (int* array, int arrSize, int key);
//random search function
int randomSearch (int* array, int arrSize, int key);
//function to create a random array to test
int* randomSortedArrayCreator(int size);
//function that finds minimum of two values
int findMin(int first, int second);

int main(int argc, const char * argv[]) {
    
    int size = 10;
    int* testArray;
    int key1beginning;
    int key2end;
    int key3middle;
    int key4notExist;
    int firstIndex;
    int secondIndex;
    int thirdIndex;
    int fourthIndex;
    int indexBeginning = 2;
    //Store the starting time
    double duration;
    clock_t startTime;
    
    for (int j = 1; j <= 10; j++){
        
        //creating the array to be used in determined size
        testArray = randomSortedArrayCreator(size);
        
        //deciding indices of keys
        key1beginning = testArray[indexBeginning];
        key2end = testArray[size - indexBeginning];
        key3middle = testArray[(size/2)];
        key4notExist = size * 10 + 5;
        
        //test starts for the dtermined array size

        cout << "Linear search (algorithm 1), array size: "<< size << endl;
        startTime = clock();
        for(int i = 0; i < 500; i++){
            firstIndex = linearSearch(testArray, size, key1beginning);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the beginning." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            thirdIndex = linearSearch(testArray, size, key3middle);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is in the middle." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        startTime = clock();
        for(int i = 0; i < 500; i++){
            secondIndex = linearSearch(testArray, size, key2end);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the end." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
            
        startTime = clock();
        for(int i = 0; i < 500; i++){
            fourthIndex = linearSearch(testArray, size, key4notExist);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key does not exist." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl << endl;
        
        
        cout << "Recursive linear search (algorithm 2), array size: "<< size << endl;
        startTime = clock();
        for(int i = 0; i < 500; i++){
            firstIndex = recursiveLinearSearch(testArray, size, key1beginning);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the beginning." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        startTime = clock();
        for(int i = 0; i < 500; i++){
            thirdIndex = recursiveLinearSearch(testArray, size, key3middle);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is in the middle." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            secondIndex = recursiveLinearSearch(testArray, size, key2end);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the end." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        

        startTime = clock();
        for(int i = 0; i < 500; i++){
            fourthIndex = recursiveLinearSearch(testArray, size, key4notExist);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key does not exist." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl << endl;
        
        cout << "Binary search (algorithm 3), array size: "<< size << endl;
        startTime = clock();
        for(int i = 0; i < 500; i++){
            firstIndex = binarySearch(testArray, size, key1beginning);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the beginning." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            thirdIndex = binarySearch(testArray, size, key3middle);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is in the middle." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        startTime = clock();
        for(int i = 0; i < 500; i++){
            secondIndex = binarySearch(testArray, size, key2end);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the end." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
            
        startTime = clock();
        for(int i = 0; i < 500; i++){
            fourthIndex = binarySearch(testArray, size, key4notExist);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key does not exist." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl << endl;
        
        
        cout << "Jump search (algorithm 4), array size: "<< size << endl;
        startTime = clock();
        for(int i = 0; i < 500; i++){
            firstIndex = jumpSearch(testArray, size, key1beginning);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the beginning." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl ;
        

        startTime = clock();
        for(int i = 0; i < 500; i++){
            thirdIndex = jumpSearch(testArray, size, key3middle);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is in the middle." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            secondIndex = jumpSearch(testArray, size, key2end);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the end." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            fourthIndex = jumpSearch(testArray, size, key4notExist);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key does not exist." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl << endl;

        
        cout << "Random search (algorithm 5), array size: "<< size << endl;
        startTime = clock();
        for(int i = 0; i < 500; i++){
            firstIndex = randomSearch(testArray, size, key1beginning);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the beginning." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        
        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            thirdIndex = randomSearch(testArray, size, key3middle);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is in the middle." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;

        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            secondIndex = randomSearch(testArray, size, key2end);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key is at the end." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl;
        
        
        startTime = clock();
        for(int i = 0; i < 500; i++){
            fourthIndex = randomSearch(testArray, size, key4notExist);
        }
        
        //Compute the number of seconds that passed since the starting time
        duration = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        cout << "Key does not exist." << endl;
        cout << "Execution took " << duration/500 << " milliseconds." << endl << endl;
        
        
        //increase the size linearly
        size += 2000;
        //arrange key index according to increasing array size
        indexBeginning += 10;
        
        delete[] testArray;
    }

    return 0;
}

//this algorithm makes linear search for the key
int linearSearch (int* array, int arrSize, int key){
    
    for (int i = 0; i < arrSize; i++){
        if (array[i] == key){
            return i;
        }
    }
    return -1;
}

//this algorithm makes recursive linear search
int recursiveLinearSearch (int* array, int arrSize, int key){
    
    if (arrSize == 0){
        return -1;
    }
    else if (array[arrSize -1] == key){
        
        return arrSize - 1;
    }
    return recursiveLinearSearch(array, arrSize - 1, key);
}

//this algorithm makes binary search
int binarySearch (int* array, int arrSize, int key){
    
    int low = 0;
    int high = arrSize - 1;
    
    while (low <= high){
        
        int mid = (low + high)/2;
        if(key < array[mid]) {
            high = mid - 1;
        }
        else if (key > array[mid]){
            low = mid + 1;
        }
        else{
            return mid;
        }
    }
    return -1;
    
}

 //this algorithm makes jump search
int jumpSearch (int* array, int arrSize, int key){
    
    //taking jump block as square root of array size
    int jump = sqrt(arrSize);
    int blockIndex = 0;
    
    
    //looking for the interval that may contain key since array is sorted
    while (array[findMin(jump, arrSize) - 1] < key){
        blockIndex = jump;
        jump += jump;
        
        if (blockIndex >= arrSize ){
            return -1;
        }
    }
    
    //looking at interval found in previous loop to find key
    for (; array[blockIndex] < key; blockIndex++){
        
        //key couldn't be found, it is larger than all elements in that block
        if (blockIndex == findMin(jump, arrSize)){
            return -1;
        }
    }
    
    //if it is found, return value of the blockIndex
    if (array[blockIndex] == key){
        return blockIndex;
    }
    
    return -1;
    
}

//this algorithm makes random search
int randomSearch (int* array, int arrSize, int key){
    int randomIndexes[arrSize];
    
    //create an index array to search
    for (int i = 0; i < arrSize; i++){
        randomIndexes[i] = i;
    }
    
    //shuffle index array
    srand(static_cast<unsigned int>(time(0)));
    
    for (int i = 0; i < arrSize; i++){
        int randomIndex = rand() % (arrSize);
        
        int temp = randomIndexes[i];
        randomIndexes[i] = randomIndexes[randomIndex];
        randomIndexes[randomIndex] = temp;
        
    }
    
    //looking at key
    for (int i = 0; i < arrSize; i++){
        if(array[randomIndexes[i]] == key){
            return randomIndexes[i];
        }
    }
    return -1;
}

int* randomSortedArrayCreator(int size){
    int* arrayWithRandomNumbers = new int[size];
    
    //create random numbers [0 - (10 * size)] and put them into created new array
    for (int i = 0; i < size; ++i) {
        arrayWithRandomNumbers[i] = 0 + rand() % ((10*size) + 1);
    }
    
    //sort that arrray
    for (int i = 0; i < size - 1; ++i) {
        
        for (int j = 0; j < size - i - 1; ++j) {
            
            if (arrayWithRandomNumbers[j] > arrayWithRandomNumbers[j + 1]) {
                int temp = arrayWithRandomNumbers[j];
                arrayWithRandomNumbers[j] = arrayWithRandomNumbers[j + 1];
                arrayWithRandomNumbers[j + 1] = temp;
            }
        }
    }
    
    return arrayWithRandomNumbers;
}

//this method is created to be used in jump search
int findMin (int first, int second){
    if(first <= second){
        return first;
    }
    else{
        return second;
    }
}
