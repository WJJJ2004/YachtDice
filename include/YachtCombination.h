#ifndef YACHTCOMBINATION_H
#define YACHTCOMBINATION_H

// #include <iostream>
// #include <algorithm>

#include <cstdlib>
#include<ctime>

class Player_Hands
{
public:

    int* dice_origin;
    bool* isfixed;
    bool* is_keeped;

    int* dice_arranged; // upper arranged

    Player_Hands()
    {
        dice_origin = new int[5];
        dice_arranged = new int[5];
        isfixed = new bool[13];
        is_keeped = new bool[5];

        for(int i =0; i<13 ; i++)
        {
            isfixed[i] = {false};
        }
        for(int i = 0; i < 5; i++)
        {
            is_keeped[i] = {false};
        }

        init_origin();
        init_arranged();
    };

    ~Player_Hands()
    {
        delete[] isfixed;
        delete[] dice_origin;
        delete[] is_keeped;
        delete[] dice_arranged;
    };

    void init_origin();
    void init_arranged();

    int dice_sum() const;

    void Reroll();
};

void Player_Hands::init_origin()
{
    srand(static_cast<unsigned int>(time(0)));

    for(int i = 0; i < 5; i++)
    {
        dice_origin[i] = (rand() % 6) + 1;
    }
};

void Player_Hands::init_arranged()
{
    // std::cout << " dddd" << std::endl;

    for(int i = 0; i < 5; i++)
    {
        dice_arranged[i] = dice_origin[i];
    }

    int temp;
    for(int i = 0; i < 4; i++)
    {
        for(int j = i + 1; j < 5; j++)
        {

            if(dice_arranged[i] > dice_arranged[j])
            {

                temp = dice_arranged[i];
                dice_arranged[i] = dice_arranged[j];
                dice_arranged[j] = temp;
            }
        }
    }
    // std::cout << Player_Hands::dice_arranged[0] <<Player_Hands::dice_arranged[1] <<Player_Hands::dice_arranged[2] <<Player_Hands::dice_arranged[3] <<Player_Hands::dice_arranged[4] << std::endl;
    // std::sort(dice_arranged, dice_arranged + 5);
}

int Player_Hands::dice_sum() const
{
    return (dice_origin[0] + dice_origin[1] +dice_origin[2] +dice_origin[3] +dice_origin[4] );
}

void Player_Hands::Reroll()
{
    srand(static_cast<unsigned int>(time(0)));
    for(int i =0; i< 5; i++)
    {
        if(is_keeped[i] == false)
        {
            dice_origin[i] = (rand() % 6) + 1;
        }
    }
    init_arranged();
}

class Yacht : public Player_Hands
{
public:
    int* score_array;

    Yacht()
    {
        score_array = new int[13];

        for(int i =0;i<13;i++) //init array
        {
            score_array[i] = 0;
        }
    };

    ~Yacht()
    {
        delete [] score_array;
    }

    int Ones() const;
    int Twos() const;
    int Threes() const;
    int Fours() const;
    int Fives() const;
    int Sixes() const;

    int Upper_Sum() const;               // upper class sum
    bool Give_Bonus() const;       // if upper sum 63 or more >> fixed bonus points 35

    int Toak() const;              // Three of a kind >> retruns sum of hands
    int Foak() const;              // four of a kind >> returns sum of hands
    int Full_house() const;        // fixed points 25
    int Small_straight() const;   // fixed point 30
    int Large_straight() const;   // fixed points 40
    int Chance() const;          //total sum of hands
    int YAHTZEE() const;        // five in a kind >> fixed 50 points

    int total_points() const;
};

int Yacht::Ones() const
{
    int count = 0;
    for(int i =0; i < 5; i++)
    {
        if(Yacht::dice_arranged[i] == 1) count++ ;
        else break;
    }
    return count;
}

int Yacht::Twos() const
{
    int count = 0;
    for(int i = 0; i<5; i++)
    {
        if(Yacht::dice_arranged[i] == 2) count++ ;
        else if(Yacht::dice_arranged[i] > 2) break;
    }
    return count;
}

int Yacht::Threes() const
{
    int count = 0;
    for(int i=0;i<5;i++)
    {
        if(Yacht::dice_arranged[i]==3) count ++;
        else if(Yacht::dice_arranged[i] >3) break;
    }
    return count;
}

int Yacht::Fours() const
{
    int count = 0;
    for(int i=0;i<5;i++)
    {
        if(Yacht::dice_arranged[i]==4) count ++;
        else if(Yacht::dice_arranged[i] >4) break;
    }
    return count;
}

int Yacht::Fives() const
{
    int count = 0;
    for(int i=0;i<5;i++)
    {
        if(Yacht::dice_arranged[i]==5) count ++;
        else if(Yacht::dice_arranged[i] >5) break;
    }
    return count;
}

int Yacht::Sixes() const
{
    int count = 0;
    for(int i=0;i<5;i++)
    {
        if(Yacht::dice_arranged[i] == 6) return (5-i);
    }
    return 0;
}

int Yacht::Upper_Sum() const
{
    return (score_array[0] + score_array[1] + score_array[2] + score_array[3]+ score_array[4]+ score_array[5]);
}

bool Yacht::Give_Bonus() const
{
    if(Upper_Sum() > 62) return true;
    else return false;
}

int Yacht::Toak() const
{
    if((Ones() >2) || (Twos() >2)|| (Threes() >2)|| (Fours() >2)|| (Fives() >2) || (Sixes() >2)) return dice_sum();
    else return 0;
}

int Yacht::Foak() const
{
    if((Ones() >3) || (Twos() >3)|| (Threes() >3)|| (Fours() >3)|| (Fives() >3) || (Sixes() >3)) return dice_sum();
    else return 0;
}

int Yacht::Full_house() const
{
    if((Ones() ==3) || (Twos() ==3)|| (Threes() ==3)|| (Fours() ==3)|| (Fives() ==3) || (Sixes() ==3))
    {
        if(!((Ones() == 1) || (Twos() == 1)|| (Threes() == 1)|| (Fours() == 1)|| (Fives() == 1) || (Sixes() == 1))) return 25;
        else return 0;
    }
    else return 0;
}

int Yacht::Small_straight() const
{
    int arranged_def[4];
    int def_sum =0;

    for(int i=0; i <4 ; i ++)
    {
        arranged_def[i] = dice_arranged[i+1] - dice_arranged[i];
        def_sum +=arranged_def[i];
    }
    if(def_sum > 2)
    {
        int count = 0;

        for( int i= 0; i<4;i++)
        {
            if(arranged_def[i] == 1) count ++;
            else continue;
        }

        if(count > 2)
        {
            if((arranged_def[1] ==2)||(arranged_def[2] ==2)) return 0;
            else return 30;
        }
        else return 0;

    }
    else return 0;
}

int Yacht::Large_straight() const
{
    int arranged_def[4];
    int def_sum =0;

    for(int i=0; i <4 ; i ++)
    {
        arranged_def[i] = dice_arranged[i+1] - dice_arranged[i];
        def_sum +=arranged_def[i];
    }
    if(def_sum == 4)
    {
        for(int i=0;i<4;i++)
        {
            if(arranged_def[i] != 1) return 0;
        }
        return 40;
    }
    return 0;
}

int Yacht::Chance() const
{
    return dice_sum();
}

int Yacht::YAHTZEE() const
{
    if((Ones() ==5) || (Twos() ==5)|| (Threes() ==5)|| (Fours() ==5)|| (Fives() ==5) || (Sixes() ==5))
    {
        return 50;
    }
    else return 0;

}

int Yacht::total_points() const
{
    return (Upper_Sum() + 35 * Give_Bonus() + score_array[6]+ score_array[7]+ score_array[8]+ score_array[9]+ score_array[10]+ score_array[11]+ score_array[12]);
}

#endif // YACHTCOMBINATION_H
