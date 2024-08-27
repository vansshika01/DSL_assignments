from datetime import datetime
def bubble_sort(arr):
    swaping=False
    count=0
    comp=0
    for x in range (len(arr)-1):
        for y in range (len(arr)-1-x):
            comp+=1
            if(arr[y]>arr[y+1]):
                arr[y],arr[y+1]=arr[y+1],arr[y]
                count+=1
                swapping=True
        if(not swapping): break
        # print(arr)
    print("No of comparisons:%d \nNo. of swaps:%d "%(comp,count))
    return arr

def selection_sort(arr):
    count1=0
    count2=0
    for x in range (len(arr)):
        mins=x
        for y in range (x+1,len(arr)):
            count1+=1
            if(arr[y]<arr[mins]):
                count2+=1
                mins=y
        if mins!=x:
            arr[x],arr[mins]=arr[mins],arr[x]
            # print (arr)

    print("No of comparisons:%d \nNo. of change:%d "%(count1,count2))
    return arr

def shellSort(arr2, n):
    g=n//2
    while g>0:
        j=g
        while j<n:
            i=j-g
            while i>=0:
                if arr2[i+g]>arr2[i]:
                    break
                else:
                    arr2[i+g],arr2[i]=arr2[i],arr2[i+g]
                i=i-g
            j+=1
        g=g//2
    return arr2
    


n=int(input("Enter the number of elements in list: "))
l=eval(input("Enter the list of numbers:"))
l2=l.copy()
l3=l.copy()
print(" ")
print("Bubble Sort: ")
# start=datetime.now()
print (bubble_sort(l),"\n")
# end=datetime.now()
# print ("Time: ",end.timestamp()*1000-sta6rt.timestamp()*1000," sec")
# print(" ")
print ("Selection Sort: ")
# start2=datetime.now()
print (selection_sort(l2),"\n")
# # end2=datetime.now()
# print ("Time: ",end2.timestamp()*1000-start2.timestamp()*1000," sec")
# print(" ")
print("Shell Sort:")
print (shellSort(l3,len(l3)),"\n")
