#ifndef GameBoard_H
#define GameBoard_H

#include <QMainWindow>
#include "Player.h"
#include <memory>
#include <QPushButton>

QT_BEGIN_NAMESPACE
namespace Ui { class GameBoard; }
QT_END_NAMESPACE

class GameBoard : public QMainWindow
{
    Q_OBJECT

public:
    GameBoard(QWidget *parent = nullptr);
    ~GameBoard();

    void setLabel();
    void swapPlayer();

    bool checkWinner() const;
    bool checkDraw() const;
    bool gameOver() const;

    void aiMove();
    int minimax(int depth, int alpha, int beta, bool isMaximizing);

private slots:
    void reset();
    void mainMenu();
    void singlePlayer();
    void multiPlayer();
    void setValue();

private:
    Ui::GameBoard *ui;
    std::shared_ptr<Player> p1;
    std::shared_ptr<Player> p2;
    std::shared_ptr<Player> current;
    QPushButton* buttons[9];
    static int x;




};

#endif // GameBoard_H
