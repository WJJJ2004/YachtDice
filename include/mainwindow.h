#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
// #include "YachtCombination.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void init_checkbox();

    void indicate_box();

    void over_roll();

    void p1_scoreboard_init();

    void p2_scoreboard_init();

    void p1_scoreboard_manage(bool do_activate);

    void p2_scoreboard_manage(bool do_activate);

    void init_dice_image(bool is_p1);

    void end_game();

private slots:
    void on_p1ones_clicked();

    void on_Rolldice_clicked();

    // void on__dice_1_pressed();


    // void on__dice_1_released();

    // void on__dice_1_toggled(bool checked);

    void on__dice_1_toggled(bool checked);

    void on__dice_2_toggled(bool checked);

    void on__dice_3_toggled(bool checked);

    void on__dice_4_toggled(bool checked);

    void on__dice_5_toggled(bool checked);

    void on_p1twos_clicked();

    void on_p1threes_clicked();

    void on_p1fours_clicked();

    void on_p1fives_clicked();

    void on_p1sixes_clicked();

    void on_p1toak_clicked();

    void on_p1foak_clicked();

    void on_p1fullhouse_clicked();

    void on_p1smallstraight_clicked();

    void on_p1largestraight_clicked();

    void on_p1chance_clicked();

    void on_p1yahtzee_clicked();

    void on_p2ones_clicked();

    void on_p2twos_clicked();

    void on_p2threes_clicked();

    void on_p2fours_clicked();

    void on_p2fives_clicked();

    void on_p2sixes_clicked();

    void on_p2toak_clicked();

    void on_p2foak_clicked();

    void on_p2fullhouse_clicked();

    void on_p2smallstraight_clicked();

    void on_p2largestraight_clicked();

    void on_p2chance_clicked();

    void on_p2yahtzee_clicked();

private:
    Ui::MainWindow *ui;


};

#endif // MAINWINDOW_H
