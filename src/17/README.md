## 17/socket.c

This is a hard-coded implementation of a GET request to `example.com`.

Lets write about it starting with the `main` method, to explain the steps that are taken here.

```
  int socket_desc = getTcpSocket();

  char *hostname="example.com";
  char ip[100]; // buffer IPv4
  resolveIP(hostname, ip);

  connectIP(ip, 80, socket_desc);

  getIndex(socket_desc);

  receiveResp(socket_desc);

  close(socket_desc);
```

First it is getting a socket for TCP IP v4. 
Then it is looking-up the hostname to an IP v4 address.
Next is connecting to port 80 on that IP v4 address.

Now it is calling `GET / HTTP/1.1` and getting the index page. 

And the socket is closed.

See the source for the individual methods.


## Creating a server...

Server code is not supplied here. But this is also working with ports, but then 
it needs to listen to them. A simple server would only serve one client.

If the server needs to serve multiple clients, then the server creates a
new thread for every request. Then every thread can take its own time
to get the data and send that back to the client.

See 18 for threads.


---
|[TOC](../../README.md) | [Prev](../16/README.md) |[Next](../18/README.md)|