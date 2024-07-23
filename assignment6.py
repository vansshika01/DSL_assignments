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
    print("No of comparisons:%d \nNo. of swaps:%d \n"%(comp,count))
    return arr


l=eval(input("Enter the list of numbers:"))
print(" ")
print ("Sorted List:\n")
start=datetime.now()
print (bubble_sort(l),"\n")
end=datetime.now()
print ("Time: ",end.timestamp()*1000-start.timestamp()*1000," sec")