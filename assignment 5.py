
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


def fibonacci_search(arr, x, n): 
    count=0
    fib2 = 0
    fib1 = 1 
    fibM = fib2 + fib1 
     
    while (fibM < n): 
        fib2 = fib1 
        fib1 = fibM 
        fibM = fib2 + fib1 
          
    offset = 0

    while (fibM > 1):  
        count+=1
        i = min(offset+fib2, n-1) 
        if (arr[i] < x): 
            fibM = fib1 
            fib1 = fib2 
            fib2 = fibM - fib1 
            offset = i 

        elif (arr[i] > x): 
            fibM = fib2 
            fib1 = fib1 - fib2 
            fib2 = fibM - fib1 

        else: 
            print("comparison:%d"%(count))
            return ("%d is present at %d"%(x,i+1))
    print("comparison:%d"%(count))
    if(fib1 and offset <n-1 and arr[offset+1] == x): 
        return ("%d is present at %d"%(x,n))

    return ("Not found")



n=eval(input("Enter number of stuents:"))
students=eval(input("Enter the list of students who attended the program:"))
for x in range(0,9):
    k=int(input("Enter the roll number of student to search:"))
    # print("  ")
    # print(linear_search(students,k))
    # print("  ")
    # print(binary_search(students,k))
    # print("  ")
    # print(sentinel_search(students,k))
    # print("  ")
    print(fibonacci_search(students,k,n))
    print(" ")

