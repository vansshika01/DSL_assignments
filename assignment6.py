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

def selection_sort(arr):
    count1=0
    count2=0
    for x in range (len(arr)):
        min=x
        for y in range (x+1,len(arr)):
            count1+=1
            if(arr[y]<arr[x]):
                count2+=1
                min=y
        arr[x],arr[min]=arr[min],arr[x]

    print("No of comparisons:%d \nNo. of change:%d \n"%(count1,count2))
    return arr
    



l=eval(input("Enter the list of numbers:"))
l2=l.copy()
print(" ")
print ("Sorted List:\n")
start=datetime.now()
print (bubble_sort(l),"\n")
end=datetime.now()
print ("Time: ",end.timestamp()*1000-start.timestamp()*1000," sec")
print(" ")
print ("Sorted List:\n")
start2=datetime.now()
print (selection_sort(l2),"\n")
end2=datetime.now()
print ("Time: ",end2.timestamp()*1000-start2.timestamp()*1000," sec")
