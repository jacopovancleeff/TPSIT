import socket as sck
import threading as thr

ip   = '192.168.43.80'
port = 8888

si  = thr.Lock()

t = {}

# funzione che ascolta se ci vuole essere una nuova connessione

def Listen(s):

    global t

    while True:

        indice = 1

        s.listen()

        si.acquire()
        
        connection , address = s.accept()

        print(address)

        # controllo che nel dizionario non ci sia già l'indirizzo ip salvato e in caso aggiungerlo

        for i in t:
            if ((str)(address[0]) + "_" + (str)(address[1])) in t:
                indice = i
                break
              
        if(indice == 1):
            indice = (str)(address[0]) + "_" + (str)(address[1])
            t[indice] = connection
        
        gestione = thr.Thread(target=Receive,args=(connection,indice))
        gestione.start()

        si.release()
               
def Send(message):

    global t 
    
    for i in t:
        t[i].sendall(message)

# funzione che gestisce la ricezione dei dati

def Receive(c,i):

    while True:

        global t
        
        data = c.recv(4096)

        if data.decode() == "/close" :
            t.pop(i)
        else:
            Send(data)
            
def Main():

    # inzializzazione variabili ecc per il funzionamento

        # creo il socket

    sock = sck.socket(sck.AF_INET, sck.SOCK_STREAM)
    sock.bind((ip,port))

    print(f'Server creato \n ip : {ip} \n porta : {port}')

    # avvio il programma

    arrivo = thr.Thread(target=Listen,args=(sock,))
    arrivo.start()
    arrivo.join()

if __name__ == '__main__': 
    Main() 