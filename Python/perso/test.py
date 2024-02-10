import random as r
def encrypt(message):
    messageEncrypted=''
    for i in message:
        ord[i]+= r.randint(26,2000)
        messageEncrypted+=i
    return messageEncrypted

messageAencrypt=''
messageAencrypt=input('Quel est le message que vous voulez encrypter ?')
print('Voici votre message encrypté', encrypt(messageAencrypt))
