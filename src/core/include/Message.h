class Message {
public:
  enum MessageType {
    Input,
    Render,
    Scene,
    Audio,
  };

  Message::Message(MessageType type) : type(type){};
  ~Message(){};

  MessageType type;
};