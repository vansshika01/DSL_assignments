#A intersection B
def intersection(a,b):
    c=[]
    for x in a:
        if (x in b):
            c.append(x)
    return c

#A union B
def union(a,b):
    d=a.copy()
    for x in b:
        if (x not in a):
            d.append(x)
    return d

#A-B
def diff(a,b):
    e=[]
    for x in a:
        if (x not in b):
            e.append(x)
    return e

t=eval(input("Total number of students:"))
a=eval(input("List of stuednts who play cricket:"))
b=eval(input("List of stuednts who play badminton:"))
c=eval(input("List of stuednts who play football:"))
print("")
print("List of students who play cricket and badminton:", intersection(a,b))
print("List of stuents who play cricket or badminton but not both",diff(union(a,b),intersection(a,b)))
print(union(a,b),"   ",intersection(a,b))
print("Number of students who play neither cricket nor badminton:",t-len(union(a,b)))
print("Number of students who play cricket and football but not badminton:",len(intersection(a,c))-len(intersection(intersection(a,b),c)))
print ("Number of students who dont play any game:",t-len(union(union(a,b),c)))
print("List of students who play atleast one game:",union(union(a,b),c))
print ("List of students who play all the games:",intersection(intersection(a,b),c))
