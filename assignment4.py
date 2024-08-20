def getMatrix():
    n=int(input("Enter number of rows:"))
    m=int(input("Enter number of columns:"))
    sparce_matrix=[[n,m,0]]
    for i in range(0,n):
        for j in range (0,m):
            x=int(input("m[%d][%d]:"%(i+1,j+1)))
            if(x!=0):
                temp=[i,j,x]
                sparce_matrix.append(temp)
                sparce_matrix[0][2]+=1
    return sparce_matrix

def add_sparce(m1,m2):
    if(m1[0][0]==m2[0][0] and m1[0][1]==m2[0][1]):
        m=m1[0][0]
        n=m1[0][1]
        result=[[m,n,0]]
        x1=x2=1
        count=0
    while(x1<len(m1) and x2<len(m2)):
        if(m1[x1][0]==m2[x2][0] and m1[x1][1]==m2[x2][1]):
            m1[x1][2]=m1[x1][2]+m2[x2][2]
            result.append(m1[x1])
            count+=1
            x1+=1
            x2+=1
        elif(m1[x1][0]==m2[x2][0]):
            if m1[x1][1]<m2[x2][1]:
                result.append(m1[x1])
                count+=1
                x1+=1
            else:
                result.append(m2[x2])
                count+=1
                x2+=1
        else:
            if(m1[x1][0]>m2[x2][0]):
                result.append(m2[x2])
                count+=1
                x2+=1
            else:
                result.append(m1[x1])
                count+=1
                x1+=1
    while(x1<len(m1)):
        result.append(m1[x1])
        x1+=1
        count+=1
    while(x2<len(m2)):
        result.append(m2[x2])
        x2+=1
        count+=1
    result[0][2]=count
    return result

def simple_transpose(mat):
    transe=[[mat[0][1],mat[0][0],mat[0][2]]]
    for i in range (0,mat[0][1]):
        for j in range (1,mat[0][2]+1):
            if(mat[j][1]==i):
                transe.append([mat[j][1],mat[j][0],mat[j][2]])
    return transe

def fast_transpose(sparse):
    s2 = [[sparse[0][1],sparse[0][0],sparse[0][2]]] + [0]* sparse[0][2]
    freq = [0] * (sparse[0][1]+1)
    for i in sparse[1:]:
        freq[(i[1])+1] += 1
    freq[0]=1
    for i in range(1,len(freq)-1):
        freq[i] = freq[i-1]+freq[i]
    for i in sparse[1:]:
        s2[freq[i[1]]] = [i[1],i[0],i[2]]
        freq[i[1]]+=1
    for i in s2:
        print(i)


# # Addition
# m1=getMatrix()
# m2=getMatrix()
# print(" ")
# print(m1)
# print(" ")
# print(m2)
# print(" ")
# print(add_sparce(m1,m2))

m1=getMatrix()
print("  ")
print(m1)
print(" ")
# Simple_transpose
print("Simple Transpose")
print(simple_transpose(m1))
print(" ")
# Fast_transpose
print("Fast Transpose ")
fast_transpose(m1)
