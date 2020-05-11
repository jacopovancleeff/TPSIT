import threading as thr
import time 
import logging

MAXINTER = 10

def Pong():

    i=0

    while(i<MAXINTER):

        i= i + 1
        s.acquire()
        print("Pong")
        s1.release()
        time.sleep(1)

def Ping():

    i=0

    while(i<MAXINTER):
        
        i= i + 1
        s.acquire()
        print("Ping")
        s1.release
        time.sleep(1)
       
def Main():

    t = []

    t = thr.Thread(target=Ping)
    t1 = thr.Thread(target=Pong)

    t.start()
    t1.start()

    t.join()
    t1.join()

if __name__ == '__main__': 

    format= " %(asctime)s : %(message)s "
    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    s = thr.Lock()
    s1 = thr.Lock()

    s1.acquire()

    Main() 