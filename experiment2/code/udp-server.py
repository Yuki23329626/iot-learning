# UDP server
# Remember to set your UDP server_ip and server_port
import socket
import sys
import time

#if len(sys.argv) == 3:
#    server_ip = sys.argv[1]
#    server_port = int(sys.argv[2])
#else:
#    print("Usage: python2 server.py <server_ip><server_port>")
#    exit(1)

server_ip = "140.123.230.10"
server_port = 6000

# create an UDP socket
s = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
# bind the socket to the port
server_address = (server_ip, server_port)
s.bind(server_address)


print("===== UDP server start listening =====")
while True:
    payload, address = s.recvfrom(6000)
    data = payload.decode('utf-8')

    t = time.localtime()
    print("===== current time: =====\n", t.tm_hour+8, ":", t.tm_min, ":", t.tm_sec)
    print("===== server received: =====\n", data)
    send_data = "Hello, " + data
    s.sendto(send_data.encode('utf-8'), address)

    print("===== server sent: =====\n", send_data)