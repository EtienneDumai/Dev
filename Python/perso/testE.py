import random

joueur1 = []  
joueur2 = []
jdc1 = []


#----------------------------------------------------------------------------
#-------------------------Fonction reste de cartes ?-------------------------
#----------------------------------------------------------------------------


def Cb_reste_il_de_cartes():

    if(len(joueur1)+len(joueur2) != len(jdc1)):
        print("Nombre de cartes restantes : ",  len(joueur1)+len(joueur2))
        print("Oups")

#----------------------------------------------------------------------------
#-------------------------Fonction choix du nombre de cartes-----------------
#----------------------------------------------------------------------------

def Choix_du_nbre(): 
    nbCartes=0
    
    while (nbCartes!=32 and nbCartes!=54):
        nbCartes = int(input("Quel nombre de cartes voulez-vous ? (32 ou 54) "))  
    return nbCartes
    

#----------------------------------------------------------------------------
#-------------------------Fonction céation du jeu----------------------------
#----------------------------------------------------------------------------

def Création_du_jeux(nbcartes):
    _jdc1=[]
    if nbcartes==32:
        for i in range(7, 15):  # definition jeux de 32 cartes
            _jdc1.append((i, 'coeur'))  # definition cartes de coeur
            _jdc1.append((i, 'pique'))  # definition cartes de pique
            _jdc1.append((i, 'trefle'))  # definition cartes de trèfles
            _jdc1.append((i, 'carreau'))  # definition cartes de carreau
    
    elif nbcartes==54:  
        for i in range(1, 15):  # definition jeux de 32 cartes
            _jdc1.append((i, 'coeur'))  # definition cartes de coeur
            _jdc1.append((i, 'pique'))  # definition cartes de pique
            _jdc1.append((i, 'trefle'))  # definition cartes de trèfles
            _jdc1.append((i, 'carreau'))  # definition cartes de carreau
    
    random.shuffle(_jdc1)  # melange des cartes
    return _jdc1
    
#----------------------------------------------------------------------------
#-------------------------Fonction distribution des cartes-------------------
#----------------------------------------------------------------------------
def Distrib_cartes():
    print(len(jdc1))
    for d in range(Nbcartes):
        if d % 2 == 0:
            joueur1.append(jdc1[d])
        else:
            joueur2.append(jdc1[d])
    print("joueur2 : ", joueur2)
    print("joueur1 : ", joueur1)


#----------------------------------------------------------------------------32
#------------------Fonction bataille et comparasion des cartes---------------
#----------------------------------------------------------------------------

def Exe_jeu():
    global nbParties
    while joueur1 != [] and joueur2 != []:
        nbParties +=1 
        print("nombre de partie : ", nbParties)
        print("joueur1 : ", len(joueur1))
        print("joueur2 : ", len(joueur2))

        tg1 = []
        tg2 = []
        tg1.append(joueur1[0])
        tg2.append(joueur2[0])
        del joueur1[0]
        del joueur2[0]

        if tg1[0][0] == tg2[0][0]:  # égalité
            print("égalité")
            # si un joueur à moins de 3 cartes alors le vainqueur est celui
            # qui a le plus de cartes

            # tant qu'il y a bataille :
            while tg1[len(tg1)-1][0] == tg2[len(tg2)-1][0]:
                # bataille
                print("Bataille")
                if len(joueur1) < 3:
                    for cartes_restantes in joueur1:
                        joueur2.append(cartes_restantes)
                    del joueur1[:]
                    for i in range(len(tg1)):
                        joueur2.append(tg1[i])
                        joueur2.append(tg2[i])
                    del tg2[:]
                    del tg1[:] 
                    print("fin de partie j1 est à sec.")   
                    break    
                    #del joueur1
                    
                elif len(joueur2) < 3:
                    for cartes_restantes in joueur2:
                            joueur1.append(cartes_restantes)
                    del joueur2[:]        
                    for i in range(len(tg1)):
                        joueur1.append(tg1[i])
                        joueur1.append(tg2[i])
                        #del joueur2
                    del tg2[:]
                    del tg1[:]
                    print("fin de partie j2 est à sec.")   

                    break

                else:
                    for i in range(0, 2):
                        tg1.append(joueur1[0])
                        tg2.append(joueur2[0])
                        del joueur1[0]
                        del joueur2[0]

                # comparaison de la dernière carte posée
                if tg1[len(tg1)-1][0] > tg2[len(tg2)-1][0]:
                    for i in range(len(tg1)):
                        joueur1.append(tg1[i])
                        joueur1.append(tg2[i])
                    
                elif tg1[len(tg1)-1][0] < tg2[len(tg2)-1][0]:
                    for i in range(len(tg1)):
                        joueur2.append(tg1[i])
                        joueur2.append(tg2[i])

        elif tg1[len(tg1)-1][0] > tg2[len(tg2)-1][0]:  # joueur gagnant 1
            joueur1.append(tg2[0])
            joueur1.append(tg1[0])
            print("Gagnant joueur1.")

        elif tg1[0][0] < tg2[0][0]:  # joueur gagnant 2
            joueur2.append(tg1[0])
            joueur2.append(tg2[0])
            print("Gagnant joueur2.")

        del tg1[:]
        del tg2[:]

#----------------------------------------------------------------------------
#-------------------------Fonction podium------------------------------------
#----------------------------------------------------------------------------
def podium(nbrj1,nbrj2,nbparties):
    if (nbrj1 > nbrj2) :
        print("c'est le joueur 1 qui a gagné la partie.")
    else:
        print("c'est le joueur 2 qui a gagné la partie.")
    print("A gagné(e) la partie après : ",nbparties," nombre de parties.")


#----------------------------------------------------------------------------
#-------------------------Debut du programme---------------------------------
#----------------------------------------------------------------------------

nbParties = 0
Nbcartes=Choix_du_nbre()
jdc1 = Création_du_jeux(Nbcartes)
print(jdc1)

Distrib_cartes()

Exe_jeu()

podium(len(joueur1) , len(joueur2) ,nbParties)