import random as r

nbrAlea = r.randint(26, 6000)


def encrypt(message):

    messageEncrypted = ""
    encryptedValue = ""
    for i in message:
        nbrAlea = r.randint(26, 6000)
        encryptedValue = ord(i) + nbrAlea  # probleme ici jsp pk
        messageEncrypted += chr(encryptedValue)
    return messageEncrypted


messageAencrypt = ""
messageAencrypt = input("Quel est le message que vous voulez encrypter ? \n")
print("Voici votre message encrypté")
messageEncrypte = encrypt(messageAencrypt)
print(messageEncrypte)
# probleme ligne 11 jsp pk qui renvoie a la ligne 5


def decode(message):
    messageDecrypted = ""
    decryptedValue = ""
    for i in message:
        decryptedValue = ord(i) - nbrAlea
        messageDecrypted += chr(decryptedValue)
    return messageDecrypted


reponse = str(
    input("Voulez-vous décrypter le message tout juste encrypter ? (oui / non) \n")
)
match reponse:
    case "oui":
        decode(messageEncrypte)
    case "non":
        print("D'accord, bonne journée !")
