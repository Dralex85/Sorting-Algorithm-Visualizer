# Sorting Algorithm Visualizer

<br/>

This project is based on SFML library to visualy represent sorting algorithm

<br/>

<br/>

# Summary
* **[Summary](#summary)**
* **[Launching](#launching)**
* **[Algorithm](#algorithm)**

<br/>

<br/>

# Launching

Obviously, you'll need to install SFML library.

Then, a simple `make` will create the launchable.

After there you'll have the choice of which algorithm you want to see.

To do so, use `./app` followed with the short name of the algorithm you want (They are listed here **[Algorithm](#algorithm)**).

You can also choose the number of element to be sorted and the time between to frame (which is required if you put a big number of element): `./app 'algorithm' 'Number_Of_Element' 'Time'`

You can change the number of element without specifying a time.

Also, you can see all the algorithm when using `all` at the place of `algorithm`

<br/>

<br/>

# Algorithm

* InsertionSort  
     Called with `insertion`  
     Check for each element if any previous element on the array is smaller,  
     if so, swap them and continue to the next

* SelectionSort  
     Called with `selection`  
     At each element, look a all the next element of the array  
     Swap the element with the smaller element contain in the rest of the list

* QuickSort  
     Called with `quick`

* BubbleSort  
     Called with `bubble`

* CombSort  
     Called with `comb`

* MergeSort  
     Called with `merge`  
     Recursivly break the array in multiple array of size 1  
     Then, combine all the formed array into larger one, sorting them at each fusion  
     The final array is the size of the original and is sorted

* HeapSort  
     Called with `heap`  
     Sort the array in the form of a max-heap tree  
          Each element is the 'parent' of the next two element, 1 parent of 2 & 3, 2 parent of 4 & 5 etc...  
          A parent is bigger than it's childs, which are not sorted  
          Using this, we know the bigest element is the root of the tree  
     After the max-heapify of the array, we switch the first and the last non-sorted element  
     And re-apply the max-heapify to the non-sorted array to get the next bigest element to the root  

<br/>
