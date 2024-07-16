
def linear_search(stud,k):
    for x in range (0,len(stud)):
        if(stud[x]==k):
            return ("%d is present at %d"%(k,x+1))
    return ("Student was absent")

def binary_search(stud,k):
    start=0
    end=len(stud)-1
    while(start<=end):
        mid=(start+end)//2
        if(stud[mid]==k):
            return ("%d is present at %d"%(k,mid+1))
        elif(stud[mid]>k):
            endn=mid-1
        elif(stud[mid]<k):
            start=mid+1
    return ("Student was absent")
        


students=eval(input("Enter the list of students who attended the program:"))
k=int(input("Enter the roll number of student to search:"))
print("  ")
print(linear_search(students,k))
print("  ")
print(linear_search(students,k))

