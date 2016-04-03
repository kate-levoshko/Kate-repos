#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main (int argc, char **argv){
    QApplication app(argc, argv);
    QLabel lbl("<h2><font color = red>Добро пожаловать\nв самый полезный каталог косметики\n\t'Fore care'<h2><\font");
    lbl.show();
    return app.exec();
}
