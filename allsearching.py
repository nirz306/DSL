#sentinal search
#binary search
#fibonacci search

def linear_search(arr,key):
    flag =0
    for x in arr:
        if(x == key):
            flag = 1
            print(key," found.")
    if(flag ==0):
        print("Element not found")
# linear_search(arr=[1,7,2,3,8,9,10],key=9)

def binary_search(arr,low,high,key):
    if(low<=high):
        mid =int((low+high)/2)
        if(arr[mid]==key):
            print(key," found at location at ",mid)
            
        elif(key<mid):
            low=low
            high=mid-1
            binary_search(arr,low,high,key)
        else:
            low=mid+1
            high=high
            binary_search(arr,low,high,key)
    else:
         print("Element not found")

arr=[1,2,3,4,5,6,7,8,9]
# binary_search(arr,0,len(arr)-1,10)

def fibonacci_search(arr,key):
    n= len(arr)
    #initialize the fibonaci numbers
    fib1=0
    fib2=1
    fib3=fib1+fib2

    #assign value to fib3
    while(fib3<n):
        fib1,fib2 =  fib2,fib3
        fib3 = fib1+fib2

    #initialize the offset and start
    offset = -1
    while(fib3>1):
        i = min(offset+fib2,n-1)

        if(arr[i]<key):
            fib3=fib2
            fib2=fib1
            fib1=fib3-fib2
            offset = i
        
        elif(arr[i]>key):
            fib3 = fib1
            fib2 =fib2-fib1
            fib1=fib3-fib2
        else:
            return i+1    

    if fib2==1 and arr[offset+1] == key:
        return offset+2
    else:
        return -1

# no =7
# if(fibonacci_search!=1):    #element exists
# )#     print("Element found at location",fibonacci_search(arr,no))
# else:
#     print("Element not found"

def sentinal_search(arr,key):
    n = len(arr)
    arr.append(key)
    i=0
    while arr[i] != key:
        i+=1
    if(i==n):
        print("Not found")
    else:
        print("Found at location ",i)
arr1=[1,2,3,4,5,6,7]
sentinal_search(arr1,8)