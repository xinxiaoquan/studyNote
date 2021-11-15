
str="5268437"
array=[int(num) for num in str]

def sort(start, end):
    if end<=start:
        return
    pos=findPos(start, end)
    sort(start, pos-1)
    sort(pos+1, end)

def findPos(start, end):
    val=array[start]
    while start<end:
        while array[end]>=val and start<end:
            end-=1
        array[start]=array[end]
        while array[start]<=val and start<end:
            start+=1
        array[end]=array[start]
    array[start]=val
    return start

"""
我的版本
def findPos(start, end):
    if end<=start:
        return
    val=array[start]
    hanle="end"
    while True:
        if start==end:
            array[start]=val
            break
        if hanle=="end":
            if array[end]>=val:
                end-=1
            else:
                array[start]=array[end]
                start+=1
                hanle="start"
            continue
        if hanle=="start":
            if array[start]<=val:
                start+=1
            else:
                array[end]=array[start]
                end-=1
                hanle="end"
            continue
    return start
"""
sort(0, len(array)-1)
print(array)









