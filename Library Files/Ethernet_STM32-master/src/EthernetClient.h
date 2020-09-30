#ifndef ETHERNETCLIENT_H
#define ETHERNETCLIENT_H


#include "Dns.h"
#include <Client.h>
#include "socket.h"

class EthernetClient : public Client
{
public:
  EthernetClient();
  EthernetClient(uint8_t sock);

  using Print::print;

  uint8_t status();
  virtual int connect(IPAddress ip, uint16_t port);
  virtual int connect(const char *host, uint16_t port);
  size_t write(const uint8_t *buf, size_t size);
  size_t inline write(const char *buf, size_t size) { return write((const uint8_t *)buf, size); }
  size_t inline write(const char *buf) { return write((const uint8_t *)buf, strlen(buf)); }
  size_t write(uint8_t b) { return write(&b, 1); }
  virtual int available();
  virtual int read();
  virtual int read(uint8_t *buf, size_t size) { return socket.recv(_sock, buf, size); }
  virtual int peek();
  inline void flush() { socket.flush(_sock); }
  virtual void stop();
  virtual uint8_t connected();
  virtual operator bool() { return _sock != MAX_SOCK_NUM; }
  virtual bool operator==(const bool value) { return bool() == value; }
  virtual bool operator!=(const bool value) { return bool() != value; }
  virtual bool operator==(const EthernetClient& rhs)
    { return _sock == rhs._sock && _sock != MAX_SOCK_NUM && rhs._sock != MAX_SOCK_NUM; }
  virtual bool operator!=(const EthernetClient& rhs) { return !this->operator==(rhs); }
  inline uint8_t getSocketNumber() { return _sock; }
  inline void getRemoteIP(uint8_t * remoteIP) { socket.getRemoteIP(_sock, remoteIP); }

  friend class EthernetServer;
  
private:
  static uint16_t _srcport;
  uint8_t _sock;
};

#endif
