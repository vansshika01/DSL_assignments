
def linear_search(stud,k):
    linear_count=0
    for x in range (0,len(stud)):
        linear_count+=1
        if(stud[x]==k):
            print("Linear Count is", linear_count)
            return ("%d is present at %d"%(k,x+1))
    print("Linear Count is", linear_count)
    return ("Student was absent")

def binary_search(stud,k):
    binary_count=0
    start=0
    end=len(stud)-1
    while(start<=end):
        binary_count+=1
        mid=(start+end)//2
        if(stud[mid]==k):
            print("Binary Count is", binary_count)
            return ("%d is present at %d"%(k,mid+1))
        elif(stud[mid]>k):
            end=mid-1
        elif(stud[mid]<k):
            start=mid+1
    print("Binary Count is", binary_count)
    return ("Student was absent")
        
def sentinel_search(stud,k):
    stud.append(k)
    i=0
    while(stud[i]!=k):
        i+=1
    if(i==len(stud)-1):
        return("Not found")
    else:
        return ("%d is present at %d"%(k,i+1))

    


students=eval(input("Enter the list of students who attended the program:"))
for x in range(0,9):
    k=int(input("Enter the roll number of student to search:"))
    print("  ")
    print(linear_search(students,k))
    print("  ")
    print(binary_search(students,k))
    print("  ")
    print(sentinel_search(students,k))
    print("  ")

