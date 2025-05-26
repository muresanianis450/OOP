//
// Created by mures on 5/26/2025.
//

#ifndef CHATWINDOW_H
#define CHATWINDOW_H
#include <QWidget>
#include <QListWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QString>
#include "Observer.h"
#include "ChatSession.h"

class ChatWindow : public QWidget, public Observer {
Q_OBJECT

private:
  ChatSession& session;
  std::string username;

  QListWidget* messageList;
  QLineEdit* messageInput;
  QPushButton* sendButton;
public:
  ChatWindow(ChatSession& session, const std::string& username, QWidget* parent = nullptr);
  void update() override;

  private slots:
    void sendMessage();
};



#endif //CHATWINDOW_H
