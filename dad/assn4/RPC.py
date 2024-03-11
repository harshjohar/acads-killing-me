from random import randint

initiator = None


class Process:
    def __init__(self, id):
        self.id = id
        self.coordinator_id = id

    def __str__(self):
        return f"{id}"


def receive(sender_id, receiver_id):
    # randomly deciding if process has crashed or not.
    if randint(0, 3) == 0:
        return False

    print(f"Process-{receiver_id} received message from Process-{sender_id}")
    return True


def send_message(sender, receiver):
    print(f"Process-{sender.id} sends message to Process-{receiver.id}")


def start_election(initiator, processes):
    for process in processes:
        if process.id == initiator.id:
            continue
        print(f"Process-{initiator.id} sends message to Process-{process.id}")

        if not receive(initiator.id, process.id):
            print(f"Process-{initiator.id} got no reply from Process-{process.id}")
        elif process.id > initiator.id:
            print(f"Reciever ID ({process.id}) > Sender ID ({initiator.id})")
            print("\n------ RESTARTING ELECTION ----------\n")
            initiator = processes[initiator.id]
            return None

    return initiator


n = 6
processes = []
for i in range(n):
    processes.append(Process(i))

leader = None
initiator = processes[2]

while leader == None:
    leader = start_election(initiator, processes)
