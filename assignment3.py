def check_triangular(mat):
    for x in range(1,len(mat)):
        for y in range(0,x):
            if(mat[x][y]!=0):
                return False
    return True

def sum_diagonal(mat):
    sum =0
    if len(mat)!=len(mat[0]):
        return "Not exist"
    for x in range(0,len(mat)):
        sum+=mat[x][x]
    return sum

def transpose(mat):
    mat2=[]
    a=len(mat)
    b=len(mat[0])
    for x in range(b):
        l=[]
        for y in range (a):
            l.append(0)
        mat2.append(l)
    
    for x in range(b):
        for y in range (a):
            mat2[x][y]=mat[y][x]
    return mat2

def add(mat1,mat2):
    if (len(mat1)!=len(mat2) or len(mat1[0])!=len(mat2[0])):
        return "Not possible"
    mat3=[]
    a=len(mat1)
    b=len(mat1[0])
    for x in range(a):
        l=[]
        for y in range (b):
            l.append(0)
        mat3.append(l)
    
    for x in range(0,len(mat1)):
        for y in range (0,len(mat1[0])):
            mat3[x][y]=mat1[x][y]+mat2[x][y]
    return mat3

def subtract(mat1,mat2):
    if (len(mat1)!=len(mat2) or len(mat1[0])!=len(mat2[0])):
        return "Not possible"
    mat3=[]
    a=len(mat1)
    b=len(mat1[0])
    for x in range(a):
        l=[]
        for y in range (b):
            l.append(0)
        mat3.append(l)
    for x in range(0,len(mat1)):
        for y in range (0,len(mat1[0])):
            mat3[x][y]=mat1[x][y]-mat2[x][y]
    return mat3

def multiply(mat1,mat2):
    res=list()
    for x in range(0,len(mat1)):
        a=[]
        for y in range (0,len(mat2[0])):
            a.append(0)
        res.append(a)

    for x in range(0,len(mat1)):
        for y in range (0,len(mat2[0])):
            for z in range (0,len(mat2)):
                res[x][y]+=mat1[x][z]*mat2[z][y]
    
    return res

def saddle(mat):
    mat2=transpose(mat)
    for x in range(0,len(mat)):
        minimum=min(mat[x])
        i=mat[x].index(minimum)
        maximum=max(mat2[i])
        if(maximum==minimum):
            return((x+1,i+1))
    return "does not exist"

def saddle_one(mat):
    for x in range(0,len(mat)):
        minimum=min(mat[x])
        i=mat[x].index(minimum)
        l=list()
        for y in range (0,len(mat[0])):
            l.append(mat[y][i])
        maximum=max(l)
        if (maximum==minimum):
            return ((x+1,i+1))
        
def magic_square(mat):
    sum_main=sum(mat[0])
    for x in range (1,len(mat)):
        if (sum(mat[x])!=sum_main):
            return False
    for y in range (0,len(mat[0])):
        sum_local=0
        for x in range (0,len(mat)):
            sum_local+=mat[x][y]
        if (sum_local!=sum_main):
            return False
    sum_local=0
    for x in range (0,len(mat)):
        sum_local+=mat[x][x]
    if (sum_local!=sum_main):
        return False
    sum_local=0
    for x in range (0,len(mat)):
        sum_local+=mat[x][len(mat)-1-x]
    if (sum_local!=sum_main):
        return False
    return True
                                                      


def get_matrix():
    n=int(input("Enter no. of rows:"))
    m=int(input("Enter no. of column:"))
    matrix=[]
    for i in range(0,n):
        x=[]
        for j in range (0,m):
            x.append(int(input("m[%d][%d]:"%(i+1,j+1))))
        matrix.append(x)
    return matrix


# print("Matrix 1:")
# matrix1=get_matrix()
# print("Matrix 2:")
# matrix2=get_matrix()
# print("If given matrix is upper triangular or not?")
# print("Matrix 1:",check_triangular(matrix1))
# print("Matrix 2:",check_triangular(matrix2))
# print(" ")
# print("Sum of diagonal elements:")
# print("Matrix 1:",sum_diagonal(matrix1))
# print("Matrix 2:",sum_diagonal(matrix2))
# print(" ")
# print("Transpose of matrix:")
# print("Matrix 1:",transpose(matrix1))
# print("Matrix 2:",transpose(matrix2))
# print(" ")
# print ("Sum of matrix: ",add(matrix1,matrix2))
# print(" ")
# print ("Difference of matrix: ",subtract(matrix1,matrix2))
# print(" ")
# print ("Multiplication of matrix: ",multiply(matrix1,matrix2))
# print(" ")
# print ("Saddle point of matrix:")
# print("Matrix 1:",saddle(matrix1))
# print("Matrix 2:",saddle(matrix2))
# print ("If magic Square:")
# print("Matrix 1:",magic_square(matrix1))
# print("Matrix 2:",magic_square(matrix2))


print ("Select any of the following operations:")
print("Operation 1: Check whether given matrix is upper triangular or not?")
print("Operation 2: Compute summation of diagonal elements")
print("Operation 3: Computr transpose of matrix")
print ("Operation 4: Add matrix")
print ("Operation 5: Subrtact matrix" )
print ("Operation 6: Multipy matrix" )
print ("Operation 7: Find saddle point")
print ("Operation 8: Check if it is a magic square?")
c=int(input("Enter option number:"))
if(c==1):
    a_matrix=get_matrix()
    print(" ")
    check=check_triangular(a_matrix)
    if(check):
        print("Yes")
    else: 
        print("No")
elif(c==2):
    a_matrix=get_matrix()
    print(" ")
    print(sum_diagonal(a_matrix))
elif(c==3):
    a_matrix=get_matrix()
    print(" ")
    print(transpose(a_matrix))
elif(c==4):
    a_matrix=get_matrix()
    b_matrix=get_matrix()
    print(" ")
    print(add(a_matrix,b_matrix))
elif(c==5):
    a_matrix=get_matrix()
    b_matrix=get_matrix()
    print(" ")
    print(subtract(a_matrix,b_matrix))
elif(c==6):
    a_matrix=get_matrix()
    b_matrix=get_matrix()
    print(" ")
    print(multiply(a_matrix,b_matrix))
elif(c==7):
    a_matrix=get_matrix()
    print(" ")
    print(saddle(a_matrix))
elif(c==8):
    a_matrix=get_matrix()
    print(" ")
    print(magic_square(a_matrix))
