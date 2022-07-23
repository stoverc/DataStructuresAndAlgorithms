from cmath import inf
import random

def SelectionSort(l:list,cnt=False) -> list:
    count = 0

    for i in range(0,len(l)):
        min = inf
        min_index = inf

        k = l[i]

        for j in range(i,len(l)):
            if l[j]<min:
                min = l[j]
                min_index = j
                count += 1

        l[i] = min
        l[min_index] = k

    if cnt:
        return [l,count]
    else: return l

def SelectionSortAnalysis() -> None:
    n = int(str.strip(input("How big do you want your test array? ")))
    ll = random.sample(range(-10000,10000),n)
    ll2 = random.sample(range(-10000,10000),2*n)

    #print(f"The original list is {ll}.")

    [sort,count] = SelectionSort(ll,True)
    [sort2,count2] = SelectionSort(ll2,True)

    print(f"Sorting a list of size {n} took {count} steps.")
    print(f"Sorting a list of size {2*n} took {count2} steps.")
    print("That means that doubling the size of the list required " + str(float(count2)/float(count)) + " times longer.")
    

if __name__ == '__main__': 
    print(SelectionSort([64,25,12,22,11]))

    SelectionSortAnalysis()