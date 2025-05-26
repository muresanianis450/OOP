#pragma once
#include <vector>
#include <string>
#include "Subject.h"

class ChatSession : public Subject {
private:
    std::vector<std::string> messages;

public:
    void addMessage(const std::string& message);
    const std::vector<std::string>& getMessages() const;
};
