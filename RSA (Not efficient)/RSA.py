from math import gcd, sqrt
import collections
from math import floor, log2
import random
import math
import string


prime = collections.deque()
leftRange=[0 for i in range(100)]
rightRange=[0 for i in range(100)]



###########################
### CheckDigit Function ###
###########################
def checkDigit(n):
    bits=0
    while n>0:
        n/=10
        n=int (n)
        bits+=1
    return bits

######################
### Sieve Function ###
######################
def Sieve(n):
    num = [False for i in range(n + 1)]
    num[1] = True
    i = 4
    while i <= n:
        num[i] = True
        i += 2
    i = 3
    while i <= int(sqrt(n)):
        if num[i] == False:
            j = i*i
            while j <= n:
                num[j]=True
                j+=2*i
        i+=2  
    prime.append(2)
    i=3
    while i<=n:
        if not num[i]:
            prime.append(i)
        i+=2
    left=0
    right=0
    bit=1
    for i in range(0,len(prime)):
        digitNo=checkDigit(prime[i])
        if digitNo>bit:
            left=right
            bit=digitNo 
    
        leftRange[bit]=left
        rightRange[bit]=right
        right+=1
 

###############################
### Prime Generate Function ###
###############################
def primeGenerate(n):
    count=0
    left = leftRange[n]
    right = rightRange[n]
    index= random.randint(left,right)
    return prime[index]
   

##########################
### Decripted Function ###
##########################
def DecryptedKeyFunction(phi):
    decryptedKey=2
    while math.gcd(decryptedKey,phi)!= 1:
           decryptedKey+=1
    return decryptedKey

##########################
### Encripted Function ###
##########################
def EncryptedKeyFunction(phi,d):
    encryptedKey = 2
    while((encryptedKey*d)%phi)!=1:
        encryptedKey+=1
        if encryptedKey>=phi:
            print("Invalid Input")
            return -1
    return encryptedKey



#############################
##### Letter Initialize #####
#############################
letter=[]
indxNo=11

for i in string.ascii_lowercase:
    letter.append({i,indxNo})
    indxNo+=1
for i in string.ascii_uppercase:
    letter.append({i,indxNo})
    indxNo+=1
for i in range (0,9):
    letter.append({str(i),indxNo})
    indxNo+=1
letter.append({" ",indxNo})
indxNo+=1
letter.append({"/",indxNo})
indxNo+=1
letter.append({"!",indxNo})
indxNo+=1
letter.append({".",indxNo})
indxNo+=1
letter.append({",",indxNo})
indxNo+=1
letter.append({"#",indxNo})
indxNo+=1
letter.append({"+",indxNo})
indxNo+=1
letter.append({"=",indxNo})
indxNo+=1
letter.append({"-",indxNo})
indxNo+=1
letter.append({"_",indxNo})
indxNo+=1
letter.append({"%",indxNo})
indxNo+=1
letter.append({"*",indxNo})
indxNo+=1



##################################
##### Find Digit From letter #####
##################################
def findDigit(char):
    for x,y in letter:
        if str(x)==char:
            return str(y)
        elif str(y)==char:
            return str(x)


##################################
##### Find Letter From Digit #####
##################################
def findLetter(n):
    for x,y in letter:
        if(type(x)!=str and x==n):
            return y
        elif (type(y)!=str and y==n):
            return x
            


#####################
### Main Function ###
#####################

print("Enter text to convert it in Plaintext: ")
text= input()

    
############### Plaintext Generate ############
plaintext=""
for i in range(0,len(text)):
    plaintext+=str(findDigit(text[i]))
plaintext = int(plaintext)


print("Enter number of bits for the two prime numbers P and Q: ")
n = input().split()
p= int(n[0])
q= int(n[1])
print("Please wait . Processing ........")

############## Bits generate ###########
p= pow(2,p)
q= pow(2,q)
pBits=0
qBits=0
pBits=checkDigit(p)
qBits=checkDigit(q)

check1=""
check2=""
for i in range(0,pBits):
    check1+='9'

for i in range(0,qBits):
    check2+='9'
multiply= int(check1)* int(check2)
if(multiply<plaintext):
    print("Invalid Bits input")
    quit()

Sieve(1000000)

#Prime Number generate
pPrime=0
qPrime=0
while pPrime*qPrime<= plaintext or pPrime==qPrime:
    pPrime=primeGenerate(pBits)
    qPrime=primeGenerate(qBits)


publicKey = pPrime*qPrime
phi =(pPrime - 1)*(qPrime - 1)

decryptedKey = DecryptedKeyFunction(phi)
encryptedKey = EncryptedKeyFunction(phi,decryptedKey)

if encryptedKey==-1:
    quit()

Encryption= (pow(plaintext,encryptedKey))%publicKey
Decryption= (pow(Encryption,decryptedKey))%publicKey


##############  print  #################
print("The Plaintext is : ",plaintext)
print("The two Prime numbers are : P -",pPrime,"  Q -",qPrime)
print("Public Key  :  (",encryptedKey,",",publicKey,")")
print("Private Key  :  (",decryptedKey,",",publicKey,")")
print("The Cypher text is : ", Encryption)
print("The decrypt text is : ", Decryption)

if(Decryption==plaintext):
    orginalLetter=""
    char=""
    plaintext=str(plaintext)
    for i in range (0,len(plaintext)):
        if i%2!=0:
            char=plaintext[i-1]+plaintext[i]
            number=int(char)
            orginalLetter+=findLetter(number)
            char=""
    print("Original message is (Verification) : ",orginalLetter)
else:
    print("Not Verified")