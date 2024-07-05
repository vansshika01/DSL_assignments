import statistics

def avg(student_list,n):
    print("Avg",sum(student_list)/n)

def highest_lowest(student_list):
    lowest=min(student_list)
    highest=max(student_list)
    print ("Highest: ", highest)
    print("LOwest: ", lowest)

def absent(student_list):
    result =0
    for x in student_list:
        if(x<0):
            result+=1
        else: continue
    print("No. of absent students: ", result)

def pass_fail(student_list, n):
    passed=0
    for x in student_list:
        if (x>=23):
            passed+=1
    print("Percentage passed: ", (passed*100/n))
    print("Percentage failed: ", ((n-passed)*100/n))

def high_frequency(student_list):
    dict={}
    for x in student_list:
        if dict.get(x) in dict.values():
            dict[x]+=1
        else:
            dict[x]=1

    highest_f =max(dict.values())
    key_list=list(dict.keys())
    value_list=list(dict.values())
    print("highest frequency is:")
    for x in range (len(value_list)):
        if(value_list[x]==highest_f):
            print(key_list[x])
    

n=int(input("Total no. of students:"))
student_list=list()

for x in range (0, n):
    marks=int(input("Enter marks of roll no %d: "%(x+1)))
    student_list.append(marks)

avg(student_list,n)
highest_lowest(student_list)
absent(student_list)
pass_fail(student_list, n)
high_frequency(student_list)
