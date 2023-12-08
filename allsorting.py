#bubble sort
def bubble_sort(arr):
    n =len(arr)
    for i in range(0,n):
        swapped = False
        for j in range(0,n-i-1):  #swap if j+1 th element is greater than j th element
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1] = arr[j+1],arr[j]
                swapped = True
        if(swapped == False):
            break
arr=[64,63,62,61,89,12]
print(arr)
# bubble_sort(arr)
# print(arr)    

#selection sort
def selection_sort(arr):        #selects the smallest element and swaps to the first ele present
    n=len(arr)
    for i in range(0,n):
        min_indx = i
        for j in range(i+1,n):
            if(arr[min_indx]>arr[j]):
                min_indx = j
        arr[i],arr[min_indx] =arr[min_indx],arr[i]

# selection_sort(arr)
# print(arr)


#insertion sort
def insertion_sort(arr):     #starts from the first index and swaps only if j os greater,equal zero and and is greater than its previous ele 
    n =len(arr)
    for i in range(1,n):
        key = arr[i]
        j = i-1
        while j>=0 and key<arr[j]:
            arr[j+1] = arr[j]
            j-=1
        arr[j+1] = key

insertion_sort(arr)
print(arr)


#shell sort
def shell_sort(arr):  #we create gaps and later gap becomes half of its prev (3x while)
    n = len(arr)
    gap = n//2

    while gap>0:
        j = gap
        while j<n:
            i=j-gap
            while i>=0:
                if(arr[i+gap]>arr[i]):         #compare i+gap and i
                    break
                else:
                    arr[i],arr[i+gap]=arr[i+gap],arr[i]
                i=i-gap                       #check for previous also 
            j+=1
        gap = gap//2


#quick sort
n=len(arr)
def partition(array, low, high):
 
    # Choose the rightmost element as pivot
    pivot = array[high]
 
    # Pointer for greater element
    i = low - 1
 
    # Traverse through all elements
    # compare each element with pivot
    for j in range(low, high):
        if array[j] <= pivot:
 
            # If element smaller than pivot is found
            # swap it with the greater element pointed by i
            i = i + 1
 
            # Swapping element at i with element at j
            (array[i], array[j]) = (array[j], array[i])
 
    # Swap the pivot element with
    # the greater element specified by i
    (array[i + 1], array[high]) = (array[high], array[i + 1])
 
    # Return the position from where partition is done
    return i + 1
 
 
# Function to perform quicksort
def quicksort(array, low, high):
    if low < high:
 
        # Find pivot element such that
        # element smaller than pivot are on the left
        # element greater than pivot are on the right
        pi = partition(array, low, high)
 
        # Recursive call on the left of pivot
        quicksort(array, low, pi - 1)
 
        # Recursive call on the right of pivot
        quicksort(array, pi + 1, high)
 
quicksort(arr,0,n-1)    
                    

    
