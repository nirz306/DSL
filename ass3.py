# Subject:Data structure Lab
# Batch:F1
# Practical no:03-Matrix Operations
# Roll no:21141
# Started on:Mon,28/08/2023
# Completed on:Wed,30/08/2023
mtx1=[[1,2,3],[4,5,6],[7,8,9]]
mtx2=[[1,4,7],[2,5,8],[3,6,9]]
mtx3=[[0,0,0],[0,0,0],[0,0,0]]
print("------First Matrix-------")
for i in range(0,3):
    print(mtx1[i],"")

print("------Second Matrix-------")
for i in range(0,3):
    print(mtx2[i],"")

def Addition(a,b,c):
    for i in range(0,3):          #rows
        for j in range(0, 3):     #columns
            mtx3[i][j]=mtx1[i][j]+mtx2[i][j]
    print("------------Addition of matrix is -------------------")
    for i in range(0,3):
        print(mtx3[i],"")

def Subtraction(mtx3,mtx1,mtx2):
    for i in range(0,3):          #rows
        for j in range(0, 3):     #columns
            mtx3[i][j]=mtx1[i][j]-mtx2[i][j]
    print("------------Difference of matrix is -------------------")
    for i in range(0,3):
        print(mtx3[i],"")

def Product(mtx1,mtx2):
    print("---------Product of matrix--------")
    mtx3=[[0,0,0],[0,0,0],[0,0,0]]
    for i in range(0,3):          #rows
        for j in range(0, 3):     #columns
            for k in range(0,3):
                mtx3[i][j]=  mtx3[i][j]+(mtx1[i][k] * mtx2[k][j])

    for i in range(0, 3):
        print(mtx3[i], "")

def transpose1(mtx1):
    print("----------Transpose of first Matrix------")
    mtx3 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range(0,3):          #rows
        for j in range(0, 3):     #columns
             mtx3[i][j]=mtx1[j][i]
    for i in range(0, 3):
            print(mtx3[i], "")


def transpose2(mtx1):
    print("----------Transpose of second Matrix------")
    mtx3 = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range(0,3):          #rows
        for j in range(0, 3):     #columns
             mtx3[i][j]=mtx2[j][i]
    for i in range(0, 3):
            print(mtx3[i], "")

transpose1(mtx1)
transpose2(mtx2)
Addition(mtx3,mtx1,mtx2)
Subtraction(mtx3,mtx1,mtx2)
Product(mtx1,mtx2)