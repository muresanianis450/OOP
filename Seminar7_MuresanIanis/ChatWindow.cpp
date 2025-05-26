//
// Created by mures on 5/26/2025.
//

#include "ChatWindow.h"
#include <QVBoxLayout>
#include <QString>

ChatWindow::ChatWindow(ChatSession& session, const std::string& username, QWidget* parent)
    : QWidget(parent), session(session), username(username){
      session.registerObserver(this);
      QVBoxLayout* layout = new QVBoxLayout(this);
        setWindowTitle(QString::fromStdString("Chat - " + username));

        // Create UI elements
    messageList = new QListWidget(this);
      messageInput = new QLineEdit(this);
      sendButton = new QPushButton("Send",this);

        layout->addWidget(messageList);
        layout->addWidget(messageInput);
        layout->addWidget(sendButton);

        connect(sendButton, &QPushButton::clicked, this, &ChatWindow::sendMessage);
        connect(messageInput, &QLineEdit::returnPressed, this, &ChatWindow::sendMessage);

        update(); // Initialize the message list with existing messages

    }

void ChatWindow::update() {
    messageList->clear(); // Clear the current message list
    for (const auto& message : session.getMessages()) {
        messageList->addItem(QString::fromStdString(message));
    }
}

void ChatWindow::sendMessage(){

  std::string text = messageInput->text().toStdString();
  if(!text.empty()) {
      session.addMessage(username + ": " + text); // Add the message to the session
      messageInput->clear(); // Clear the input field after sending
  }
}