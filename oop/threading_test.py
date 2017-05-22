import threading


gg = 0
b = threading.Barrier(10)
m = threading.Lock()


def increment():
    global gg
    b.wait()
    with m:
        gg = gg + 1
        print('current thread: ', threading.current_thread())
        print(gg)


class race_condition(threading.Thread):
    def __init__(self):
        threading.Thread.__init__(self)

    def run(self):
        increment()


threads = []
for i in range(10):
    threads.append(race_condition())
    threads[i].start()
for i in threads:
    i.join()
