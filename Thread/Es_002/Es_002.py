import threading as thr
import time 
import logging

def fn_thread(val):

    logging.info("Thread %s : inizio",val)
    time.sleep(2)
    logging.info("Thread %s : fine",val)

def Main():

    logging.info("PADRE : creo un thread")

    threads = list()

    for i in range(5):
        logging.info("PADRE : creo ed avvio thread %d.",i)
        t = thr.Thread(target=fn_thread, args=(i,))
        threads.append(t)
        t.start()

    for i,th in enumerate(threads):
        logging.info("PADRE : prma dell'attesa del thread %d",i)

        th.join()

        logging.info("PADRE : thread %d terminato",i)
   
    logging.info("PADRE : aspetto la terminazione del thread creato")
    
    t.join()

    logging.info("PADRE : fine")

if __name__ == '__main__': 

    format= " %(asctime)s : %(message)s "

    logging.basicConfig(format=format, level=logging.INFO, datefmt="%H:%M:%S")

    Main() 