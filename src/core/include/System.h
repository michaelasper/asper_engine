#include "Message.h";

class System {
public:
  void handleMessage(Message *message) {}

private:
  MessageBus *messageBus;
}