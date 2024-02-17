d1={0:[0,1,2],1:[0,1,2],2:[1,2,3],3:[2,3]}
def reflexd(dic):
    for i in dic.keys():
        if dic[i]==dic.values(): 
            return False
    return True
print(reflexd(d1))