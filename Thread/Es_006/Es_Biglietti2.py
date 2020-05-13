import threading as thr
import time 
import random
import logging

filaA = 10
filaB = 6

biglietti = 100

def bloccoA():

    if(filaA > 0):
        s.release()
    else:
        s1.release()

def bloccoB():

    if(filaB > 0):
        s1.release()
    else:
        s.release()

sblocco = {
    0 : bloccoA,
    1 : bloccoB 
}

def cassa0(i):

    s.acquire()

    global filaA
    global biglietti

    filaA -= 1

    rdm = random.randint(0,10)

    print(f"Sono il cliente {i} alla cassa 1 e voglio acquistare {rdm} biglietti")

    if(biglietti == 0):
        print("Biglietti acquistati 0\n")
    elif (biglietti>0 and rdm<=biglietti):
        print(f"Biglietti acquistati {rdm}\n")
        biglietti -= rdm
    elif (biglietti>0 and rdm>=biglietti):
        print(f"Biglietti acquistati {biglietti}\n")
        biglietti = 0

    print(f"Biglietti disponibili {biglietti} \n")

    rdm2 = random.randint(0,1)

    sblocco[rdm2]()

def cassa1(i):

    s1.acquire()

    global filaB
    global biglietti

    filaB -= 1

    rdm = random.randint(0,10)

    print(f"Sono il cliente {i} alla cassa 2 e voglio acquistare {rdm} biglietti")

    if(biglietti == 0):
        print("Biglietti acquistati 0\n")
    elif (biglietti>0 and rdm<=biglietti):
        print(f"Biglietti acquistati {rdm}\n")
        biglietti -= rdm
    elif (biglietti>0 and rdm>=biglietti):
        print(f"Biglietti acquistati {biglietti}\n")
        biglietti = 0

    print(f"Biglietti disponibili {biglietti} \n")

    rdm2 = random.randint(0,1)

    sblocco[rdm2]()

def Main():

    t  = [10]
    t1 = [6]

    for i in range(0,3):
        logging.info("Apertura casse in %d \n",i)
        time.sleep(1)

    t  = [thr.Thread(target=cassa0, args=(i+1,)) for i in range(0,10)]
    t1 = [thr.Thread(target=cassa1, args=(i+1,)) for i in range(0,6)]

    for i in t:
        i.start()

    for i in t1:
        i.start()

    for i in t:
        i.join()
    
    for i in t1:
        i.join()

if __name__ == '__main__': 

    format= " %(asctime)s : %(message)s "
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    s = thr.Lock()
    s1 = thr.Lock()

    s1.acquire()

    Main() 