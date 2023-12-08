SetU = [1,2,3,4,5,6,7,8,9,10,11,12]
sizeU = len(SetU)
print("\n Set U =",SetU)
print(" Size",sizeU)

cricket = []
n1 = int(input("Enter the number of students playing cricket: "))
i = 0

while i < n1:
    ele = int(input("Enter roll number: "))
    if ele not in cricket:
        cricket.append(ele)
        i += 1
    else:
        print("Roll number already in the list. Enter a unique roll number.")
        i+=0

print("Cricket: ", cricket)

badminton = []
n2 = int(input("Enter the number of students playing badminton: "))
i = 0

while i < n2:
    ele = int(input("Enter roll number: "))
    if ele not in badminton:
        badminton.append(ele)
        i += 1
    else:
        print("Roll number already in the list. Enter a unique roll number.")
        i+=0

print("Badminton: ", badminton)

football = []
n3 = int(input("Enter the number of students playing football: "))
i = 0

while i < n3:
    ele = int(input("Enter roll number: "))
    if ele not in football:
        football.append(ele)
        i += 1
    else:
        print("Roll number already in the list. Enter a unique roll number.")
        i+=0

print("Football: ", football)

cricket=[1,2,3,11,12]
badminton=[3,4,5,6,7,12]
football = [6,7,8,9,10,11,12]

def intersection(list1,list2):
    intersect=[]
    for x in list1:
        flag = 0
        for y in list2:
            if(x == y):
                flag = 1
                break
        if (flag == 1):
            intersect+=[x]
    return intersect

def minus(list1,list2):
    minus=[]
    for x in list1:
        flag = 1                 #intially the flag is up
        for y in list2:
            if(x == y):
                flag = 0
                break
        if(flag == 1):
            minus+=[x]
    return minus

def union(list1,list2):
    union = list1
    for x in list2:
        flag = 1
        for y in list1:
            if(x == y):
                flag = 0
                break
        if(flag == 1):
            union+=[x]
    return union

print("Students playing cricket and badminton are: ",intersection(cricket,badminton))
print("Students playing either cricket or badminton but not both are: ",union(minus(cricket,badminton),minus(badminton,cricket)))
print("Students playing neither cricket or badminton: ",intersection(minus(football,cricket),minus(football,badminton)))
print("Students playing cricket and football but not badminton are: ",union(minus(cricket,badminton),minus(football,badminton)))

    
