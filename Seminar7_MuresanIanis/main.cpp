#include <QApplication>
#include <QPushButton>
#include "ChatSession.h"
#include "ChatWindow.h"


int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    ChatSession session;
    ChatWindow* user1 = new ChatWindow(session, "Iuliana");
    ChatWindow* user2 = new ChatWindow(session,"Ianis");

    user1->show();
    user2->show();

    return a.exec();

   /* QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();
    return QApplication::exec();*/
}