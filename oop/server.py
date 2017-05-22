import socket
import signal
import threading


class server:
    end = False

    class deamon_thread(threading.Thread):
        def __init__(self):
            threading.Thread.__init__(self)

        def run(self):
            sig = signal.sigwait()
            if sig == signal.SIGINT:
                server.end = True
            elif sig == signal.SIGPIPE:
                print("Receive SIGPIPE!")

    def __init__(self, port=0):
        singal.siginterrupt(signal.SIGINT, True)
        signal.pthread_sigmask(
            signal.SIG_BLOCK, {signal.SIGINT, signal.SIGPIPE})

        if port == 0:
            port = int(input('Please enter the port number'))
        s = socket.socket()
        s.setsockopt()
        s.bind(('127.0.0.1', port))

    def run(self):
