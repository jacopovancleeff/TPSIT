import threading as thr
import time 
import random

s = thr.Lock()

biglietti = 100
contatore = 0

def cassa():

    global biglietti
    global contatore

    rdm = random.randint(1, 10)
    s.acquire()

    contatore +=1
    
    print(f"Sono il cliente {contatore} e voglio acquistare {rdm} biglietti \n")

    if(biglietti == 0):
        print("Biglietti acquistati 0\n")
    elif (biglietti>0 and rdm<=biglietti):
        print(f"Biglietti acquistati {rdm}\n")
        biglietti -= rdm
    elif (biglietti>0 and rdm>=biglietti):
        print(f"Biglietti acquistati {biglietti}\n")
        biglietti = 0

    print(f"Biglietti disponibili {biglietti} \n")

    s.release()

def Main():

    t = [10]

    for i in range(0,3):
        print("Apertura cassa tra ...",i)
        time.sleep(1)

    t = [thr.Thread(target=cassa) for i in range(0,10)]

    for i in t:
        i.start()

    for i in t:
        i.join()

if __name__ == '__main__': 

    Main() 