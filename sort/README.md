#Sort Algorithms
are used to rearrange a sequence of numbers in ascending or descending.
###List of algorithms
1. bubble sort
2. heap sort
3. merge sort
4. quick sort
#### 1. Bubble sort
#### 2. Heap sort
#### 3. Merge sort
#### 4. Quick sort
```
function PARTITION(array, lowIndex, highIndex)
    pivot = array[highIndex]
    i = lowIndex - 1
    for j in range(lowIndex, highIndex) do
        if array[j] <= pivot then
            i++
            swap(array[i], array[j])
        end if
    end for
end function
```