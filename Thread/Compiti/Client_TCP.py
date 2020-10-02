import socket as sck
import threading as thr

ip   = '192.168.43.80'
port = 8888

# funzione che gestisce l'inzio dei dati

def Send(s,name):

    while True:

        # invio dati
        
        message = input("")
        print("\n")

        if message == "/close" :
            s.sendall(message.encode())
            s.close()
            break
        else:
            message = name + ":" + message 
            
            s.sendall(message.encode())
        
# funzione che gestisce la ricezione dei dati

def Receive(s,name):

    while True:

        c = []

        # ricevo dati

        data = s.recv(4096)

        data = data.decode()

        if data == "/close" :
            s.close()
            break
        else:
            c = data.split(":")

            if name != c[0]:
                print(f"{data}\n")
        
def Main():

    # inzializzazione variabili ecc per il funzionamento

        # creo il socket

    sock = sck.socket(sck.AF_INET, sck.SOCK_STREAM)

        # creo i thread

    n = input("Inserire il tuo nome : ")

    t = thr.Thread(target=Send, args=(sock,n,)) 
    c = thr.Thread(target=Receive, args=(sock,n,)) 

    # avvio il programma 

      # connetto il cient al server

    print(f'connessione a : {ip} \n con la porta : {port}')
    sock.connect((ip,port))

        # avvio i due thread

    c.start()
    t.start()

        # gestisco i thread

    t.join()
    c.join()

if __name__ == '__main__': 
    Main() 