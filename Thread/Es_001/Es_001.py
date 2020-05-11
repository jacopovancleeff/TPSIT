import threading as thr
import time 
import logging

def fn_thread(val):

    logging.info("Thread %s: inizio",val)
    time.sleep(2)
    logging.info("Thread %s: fine",val)

def Main():

    logging.info("PADRE : creo un thread")

    t = thr.Thread(target=fn_thread,args=(1,))

    logging.info("PADRE : avvio il thread creato")

    t.start()

    logging.info("PADRE : aspetto la terminazione del thread creato")
    
    t.join()

    logging.info("PADRE : fine")

if __name__ == '__main__': 

    format= " %(asctime)s : %(message)s "

    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    Main() 