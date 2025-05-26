

#include "ChatSession.h"

void ChatSession::addMessage(const std::string& message) {
    messages.push_back(message);
    notify();  // notify all observers (e.g., ChatWindow)
}

const std::vector<std::string>& ChatSession::getMessages() const {
    return messages;
}
