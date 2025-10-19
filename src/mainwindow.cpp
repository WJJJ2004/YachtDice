#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "YachtCombination.h"
// #include <QMap> // 이미지 초기화 용

Yacht p1;
Yacht p2;

int count_p1_roll = 1,count_p2_roll = 1;  // 1,2,3
int count_turn =1; // 홀수 일떄 >> p1 turn, 짝수 일때 >> p2 turn

int capturevalue =0;
QString output ;

void MainWindow::end_game()
{
    ui->indicatebox->setStyleSheet("background-color: gold; color: white;");

    if(p1.total_points() > p2.total_points())
    {
        output = "player 1 win !!!";
        ui->indicatebox->setText(output);
    }
    else if(p1.total_points() < p2.total_points())
    {
        output = "player 2 win !!!";
        ui->indicatebox->setText(output);
    }
    else
    {
        output = "draw !!!";
        ui->indicatebox->setText(output);
    }
}

void MainWindow::init_checkbox()
{
    ui->_dice_1->setChecked(false);
    ui->_dice_2->setChecked(false);
    ui->_dice_3->setChecked(false);
    ui->_dice_4->setChecked(false);
    ui->_dice_5->setChecked(false);
}

void MainWindow::indicate_box()
{
    ui->indicatebox->setStyleSheet("background-color: green; color: white;");

    if(count_turn%2) //p1's turn
    {
        capturevalue = count_p1_roll;
        output = "Player 1 rolled: " + QString::number(capturevalue);
        ui->indicatebox->setText(output);        
    }
    else
    {
        capturevalue = count_p2_roll;
        output = "Player 2 rolled: " + QString::number(capturevalue);
        ui->indicatebox->setText(output);
    }
}

void MainWindow::over_roll()
{
    ui->indicatebox->setStyleSheet("background-color: red; color: white;");
    output = "you rolled third dice choose the options";
    ui->indicatebox->setText(output);

    ui->Rolldice->setEnabled(false);
}

void MainWindow::p1_scoreboard_manage(bool do_activate)
{

    ui->p1ones->setEnabled(do_activate);
    ui->p1twos->setEnabled(do_activate);
    ui->p1threes->setEnabled(do_activate);
    ui->p1fours->setEnabled(do_activate);
    ui->p1fives->setEnabled(do_activate);
    ui->p1sixes->setEnabled(do_activate);
    ui->p1toak->setEnabled(do_activate);
    ui->p1foak->setEnabled(do_activate);
    ui->p1fullhouse->setEnabled(do_activate);
    ui->p1smallstraight->setEnabled(do_activate);
    ui->p1largestraight->setEnabled(do_activate);
    ui->p1chance->setEnabled(do_activate);
    ui->p1yahtzee->setEnabled(do_activate);
}


void MainWindow::p2_scoreboard_manage(bool do_activate)
{
    ui->p2ones->setEnabled(do_activate);
    ui->p2twos->setEnabled(do_activate);
    ui->p2threes->setEnabled(do_activate);
    ui->p2fours->setEnabled(do_activate);
    ui->p2fives->setEnabled(do_activate);
    ui->p2sixes->setEnabled(do_activate);
    ui->p2toak->setEnabled(do_activate);
    ui->p2foak->setEnabled(do_activate);
    ui->p2fullhouse->setEnabled(do_activate);
    ui->p2smallstraight->setEnabled(do_activate);
    ui->p2largestraight->setEnabled(do_activate);
    ui->p2chance->setEnabled(do_activate);
    ui->p2yahtzee->setEnabled(do_activate);
}


void MainWindow::p1_scoreboard_init()
{
    ui->indicateturn->setText("PLAYER 1'S TURN");

    if(!p1.isfixed[0])    //버튼 안눌림 >> 해당 버튼의 텍스트 초기화 필요
    {
        capturevalue = p1.Ones();
        ui->p1ones->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[1])
    {
        capturevalue = 2*p1.Twos();
        ui->p1twos->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[2])
    {
        capturevalue = 3*p1.Threes();
        ui->p1threes->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[3])
    {
        capturevalue = 4*p1.Fours();
        ui->p1fours->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[4])
    {
        capturevalue = 5*p1.Fives();
        ui->p1fives->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[5])
    {
        capturevalue = 6*p1.Sixes();
        ui->p1sixes->setText(QString::number(capturevalue));
    }


    capturevalue = p1.Upper_Sum();
    ui->p1sum->setStyleSheet("background-color: black; color: white;");
    ui->p1sum->setText(QString::number(capturevalue));

    capturevalue = p1.Give_Bonus();
    ui->p1bonus->setStyleSheet("background-color: black; color: white;");
    ui->p1bonus->setText(QString::number(capturevalue));


    if(!p1.isfixed[6])
    {
        capturevalue = p1.Toak();
        ui->p1toak->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[7])
    {
        capturevalue = p1.Foak();
        ui->p1foak->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[8])
    {
        capturevalue = p1.Full_house();
        ui->p1fullhouse->setText(QString::number(capturevalue));
    }

    if(!p1.isfixed[9])
    {
        capturevalue = p1.Small_straight();
        ui->p1smallstraight->setText(QString::number(capturevalue));
    }


    if(!p1.isfixed[10])
    {
        capturevalue = p1.Large_straight();
        ui->p1largestraight->setText(QString::number(capturevalue));
    }


    if(!p1.isfixed[11])
    {
        capturevalue = p1.Chance();
        ui->p1chance->setText(QString::number(capturevalue));
    }


    if(!p1.isfixed[12])
    {
        capturevalue = p1.YAHTZEE();
        ui->p1yahtzee->setText(QString::number(capturevalue));
    }

    capturevalue = p1.total_points();
    ui->p1totalscore->setStyleSheet("background-color: black; color: white;");
    ui->p1totalscore->setText(QString::number(capturevalue));

}

void MainWindow::p2_scoreboard_init()
{
    ui->indicateturn->setText("PLAYER 2'S TURN");

    if(!p2.isfixed[0])    //버튼 안눌림 >> 해당 버튼의 텍스트 초기화 필요
    {
        capturevalue = p2.Ones();
        ui->p2ones->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[1])
    {
        capturevalue = 2 * p2.Twos();
        ui->p2twos->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[2])
    {
        capturevalue = 3 * p2.Threes();
        ui->p2threes->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[3])
    {
        capturevalue = 4 * p2.Fours();
        ui->p2fours->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[4])
    {
        capturevalue = 5 * p2.Fives();
        ui->p2fives->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[5])
    {
        capturevalue = 6 * p2.Sixes();
        ui->p2sixes->setText(QString::number(capturevalue));
    }

    capturevalue = p2.Upper_Sum();
    ui->p2sum->setStyleSheet("background-color: black; color: white;");
    ui->p2sum->setText(QString::number(capturevalue));

    capturevalue = p2.Give_Bonus();
    ui->p2bonus->setStyleSheet("background-color: black; color: white;");
    ui->p2bonus->setText(QString::number(capturevalue));


    if(!p2.isfixed[6])
    {
        capturevalue = p2.Toak();
        ui->p2toak->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[7])
    {
        capturevalue = p2.Foak();
        ui->p2foak->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[8])
    {
        capturevalue = p2.Full_house();
        ui->p2fullhouse->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[9])
    {
        capturevalue = p2.Small_straight();
        ui->p2smallstraight->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[10])
    {
        capturevalue = p2.Large_straight();
        ui->p2largestraight->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[11])
    {
        capturevalue = p2.Chance();
        ui->p2chance->setText(QString::number(capturevalue));
    }

    if(!p2.isfixed[12])
    {
        capturevalue = p2.YAHTZEE();
        ui->p2yahtzee->setText(QString::number(capturevalue));
    }

    capturevalue = p2.total_points();
    ui->p2totalscore->setStyleSheet("background-color: black; color: white;");
    ui->p2totalscore->setText(QString::number(capturevalue));
}

QString diceImagePaths[6] = {
    ":/images/dice_1.png",
    ":/images/dice_2.png",
    ":/images/dice_3.png",
    ":/images/dice_4.png",
    ":/images/dice_5.png",
    ":/images/dice_6.png"
};

void MainWindow::init_dice_image(bool is_p1)
{
    QLabel* diceLabels[5] = {ui->dice1, ui->dice2, ui->dice3, ui->dice4, ui->dice5};

    if(count_turn%2)
    {
        p1.Reroll();

        for (int i = 0; i < 5; ++i) //카드 이미지 초기화
        {
            diceLabels[i]->setPixmap(QPixmap(diceImagePaths[p1.dice_origin[i] - 1]));
            diceLabels[i]->setScaledContents(true);  // 이미지 크기 자동 조정
        }
    }
    else
    {
        p2.Reroll();

        for (int i = 0; i < 5; ++i) //카드 이미지 초기화
        {
            diceLabels[i]->setPixmap(QPixmap(diceImagePaths[p2.dice_origin[i] - 1]));
            diceLabels[i]->setScaledContents(true);
        }
    }
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_Rolldice_clicked()
{
    indicate_box();

    if(count_turn%2) // 홀수 일떄 참을 리턴함
    {
        init_dice_image(true);

        p1_scoreboard_manage(true);
        p2_scoreboard_manage(false);

        if(count_p1_roll < 3)
        {
            count_p1_roll ++;
            p1_scoreboard_init();
        }
        else // count = 3
        {
            over_roll();
            count_p1_roll = 1;
        }
    }
    else // 짝수 일떄
    {
        init_dice_image(false);

        p1_scoreboard_manage(false);
        p2_scoreboard_manage(true);

        if(count_p2_roll < 3)
        {
            count_p2_roll++;
            p2_scoreboard_init();
        }
        else
        {
            over_roll();
            count_p2_roll = 1;
        }
    }
}

void MainWindow::on__dice_1_toggled(bool checked)
{
    if(checked)
    {
        p1.is_keeped[0] = true;
    }
    else
    {
        p1.is_keeped[0] = false;
    }
}

void MainWindow::on__dice_2_toggled(bool checked)
{
    if(checked)
    {
        p1.is_keeped[1] = true;
    }
    else
    {
        p1.is_keeped[1] = false;
    }
}

void MainWindow::on__dice_3_toggled(bool checked)
{
    if(checked)
    {
        p1.is_keeped[2] = true;
    }
    else
    {
        p1.is_keeped[2] = false;
    }
}


void MainWindow::on__dice_4_toggled(bool checked)
{
    if(checked)
    {
        p1.is_keeped[3] = true;
    }
    else
    {
        p1.is_keeped[3] = false;
    }
}

void MainWindow::on__dice_5_toggled(bool checked)
{
    if(checked)
    {
        p1.is_keeped[4] = true;
    }
    else
    {
        p1.is_keeped[4] = false;
    }
}

void MainWindow::on_p1ones_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[0] = true;
        p1.score_array[0] = p1.Ones();

        capturevalue = p1.score_array[0];
        ui->p1ones->setText(QString::number(capturevalue));
        ui->p1ones->setStyleSheet("background-color: green; color: white;");

        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1twos_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[1] = true;
        p1.score_array[1] = 2 * p1.Twos();

        capturevalue = p1.score_array[1];
        ui->p1twos->setText(QString::number(capturevalue));
        ui->p1twos->setStyleSheet("background-color: green; color: white;");

        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1threes_clicked()
{
    ui->Rolldice->setEnabled(true);
    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[2] = true;
        p1.score_array[2] = 3 * p1.Threes();

        capturevalue = p1.score_array[2];
        ui->p1threes->setText(QString::number(capturevalue));
        ui->p1threes->setStyleSheet("background-color: green; color: white;");

        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1fours_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[3] = true;
        p1.score_array[3] = 4 * p1.Fours();

        capturevalue = p1.score_array[3];
        ui->p1fours->setText(QString::number(capturevalue));
        ui->p1fours->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1fives_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[4] = true;
        p1.score_array[4] = 5 * p1.Fives();

        capturevalue = p1.score_array[4];
        ui->p1fives->setText(QString::number(capturevalue));
        ui->p1fives->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1sixes_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[5] = true;
        p1.score_array[5] = 6 * p1.Sixes();

        capturevalue = p1.score_array[5];
        ui->p1sixes->setText(QString::number(capturevalue));
        ui->p1sixes->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;

        init_checkbox();
    }
}

void MainWindow::on_p1toak_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[6] = true;
        p1.score_array[6] = p1.Toak();

        capturevalue = p1.score_array[6];
        ui->p1toak->setText(QString::number(capturevalue));
        ui->p1toak->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1foak_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[7] = true;
        p1.score_array[7] = p1.Foak();

        capturevalue = p1.score_array[7];
        ui->p1foak->setText(QString::number(capturevalue));
        ui->p1foak->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1fullhouse_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[8] = true;
        p1.score_array[8] = p1.Full_house();

        capturevalue = p1.score_array[8];
        ui->p1fullhouse->setText(QString::number(capturevalue));
        ui->p1fullhouse->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1smallstraight_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[9] = true;
        p1.score_array[9] = p1.Small_straight();

        capturevalue = p1.score_array[9];
        ui->p1smallstraight->setText(QString::number(capturevalue));
        ui->p1smallstraight->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1largestraight_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[10] = true;
        p1.score_array[10] = p1.Large_straight();

        capturevalue = p1.score_array[10];
        ui->p1largestraight->setText(QString::number(capturevalue));
        ui->p1largestraight->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1chance_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[11] = true;
        p1.score_array[11] = p1.Chance();

        capturevalue = p1.score_array[11];
        ui->p1chance->setText(QString::number(capturevalue));
        ui->p1chance->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p1yahtzee_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (count_turn % 2) // p1일 때
    {
        p1.isfixed[12] = true;
        p1.score_array[12] = p1.YAHTZEE();

        capturevalue = p1.score_array[12];
        ui->p1yahtzee->setText(QString::number(capturevalue));
        ui->p1yahtzee->setStyleSheet("background-color: green; color: white;");
        count_p1_roll = 1;
        count_turn++;
        init_checkbox();
    }
}

void MainWindow::on_p2ones_clicked()
{
    ui->Rolldice->setEnabled(true);

    if(!(count_turn%2))
    {
        p2.isfixed[0] = true;
        p2.score_array[0] = p2.Ones();

        capturevalue = p2.score_array[0];
        ui->p2ones->setText(QString::number(capturevalue));
        ui->p2ones->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2twos_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[1] = true;
        p2.score_array[1] = 2 * p2.Twos();

        capturevalue = p2.score_array[1];
        ui->p2twos->setText(QString::number(capturevalue));
        ui->p2twos->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2threes_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[2] = true;
        p2.score_array[2] = 3 * p2.Threes();

        capturevalue = p2.score_array[2];
        ui->p2threes->setText(QString::number(capturevalue));
        ui->p2threes->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2fours_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[3] = true;
        p2.score_array[3] = 4 * p2.Fours();

        capturevalue = p2.score_array[3];
        ui->p2fours->setText(QString::number(capturevalue));
        ui->p2fours->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2fives_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[4] = true;
        p2.score_array[4] = 5 * p2.Fives();

        capturevalue = p2.score_array[4];
        ui->p2fives->setText(QString::number(capturevalue));
        ui->p2fives->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2sixes_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[5] = true;
        p2.score_array[5] = 6 * p2.Sixes();

        capturevalue = p2.score_array[5];
        ui->p2sixes->setText(QString::number(capturevalue));
        ui->p2sixes->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2toak_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[6] = true;
        p2.score_array[6] = p2.Toak();

        capturevalue = p2.score_array[6];
        ui->p2toak->setText(QString::number(capturevalue));
        ui->p2toak->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2foak_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[7] = true;
        p2.score_array[7] = p2.Foak();

        capturevalue = p2.score_array[7];
        ui->p2foak->setText(QString::number(capturevalue));
        ui->p2foak->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2fullhouse_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[8] = true;
        p2.score_array[8] = p2.Full_house();

        capturevalue = p2.score_array[8];
        ui->p2fullhouse->setText(QString::number(capturevalue));
        ui->p2fullhouse->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2smallstraight_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[9] = true;
        p2.score_array[9] = p2.Small_straight();

        capturevalue = p2.score_array[9];
        ui->p2smallstraight->setText(QString::number(capturevalue));
        ui->p2smallstraight->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2largestraight_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[10] = true;
        p2.score_array[10] = p2.Large_straight();

        capturevalue = p2.score_array[10];
        ui->p2largestraight->setText(QString::number(capturevalue));
        ui->p2largestraight->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2chance_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2)) // p2일 때
    {
        p2.isfixed[11] = true;
        p2.score_array[11] = p2.Chance();

        capturevalue = p2.score_array[11];
        ui->p2chance->setText(QString::number(capturevalue));
        ui->p2chance->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}

void MainWindow::on_p2yahtzee_clicked()
{
    ui->Rolldice->setEnabled(true);

    if (!(count_turn % 2))
    {
        p2.isfixed[12] = true;
        p2.score_array[12] = p2.YAHTZEE();

        capturevalue = p2.score_array[12];
        ui->p2yahtzee->setText(QString::number(capturevalue));
        ui->p2yahtzee->setStyleSheet("background-color: green; color: white;");
        count_p2_roll = 1;
        count_turn++;
        init_checkbox();

        if(count_turn  ==26)
        {
            end_game();
        }
    }
}



