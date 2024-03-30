def decompo_niv(M):
    n=len(M)
    niv=[None]*n
    nbpred=[None]*n
    File=[]
    for i in range(n):
        nbpred[i]=Nb_pred(M,i)
        if nbpred[i]==0:
            File.append(i)
            niv[i]=0
    while File!=[]:
        som=File.pop(0)
        for succ in list_succ(M,som):
            nbpred[succ]-=1
            if nbpred[succ]==0:
                File.append(succ)
                niv[succ]=niv[som]+1
    return niv
def list_succ(M,som):
    n=len(M)
    succ=[]
    for i in range(n):
        if M[som][i]==1:
            succ.append(i)
    return succ
def Nb_pred(M,som):
    n=len(M)
    nb=0
    for i in range(n):
        if M[i][som]==1:
            nb+=1
    return nb

matrice=[[0,1,0,0,0,0],
            [0,0,1,0,0,0],
            [0,0,0,1,0,0],
            [0,0,0,0,1,0],
            [0,0,0,0,0,1],
            [0,0,0,0,0,0]]
print(decompo_niv(matrice))






def decompo_largeur(M,s):
    n=len(M)
    vu=[False]*n
    pred=[None]*n
    file=[s]
    vu[s]=True
    while file!=[]:
        som=file.pop(0)
        for succ in list_succ(M,som):
            if vu[succ] == False:
                vu[succ]=True
                pred[succ]=som
                file.append(succ)
    return pred
