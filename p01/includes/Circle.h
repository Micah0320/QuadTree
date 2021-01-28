#ifndef CIRCLE_H
#define CIRCLE_H
#include "Constants.h"
class color
{
public:
    color(int r, int g, int b)
        :r_(r), g_(g), b_(b)
    {}
    
    color(color & c)
    {
        r_ = c.r();
        g_ =c.g();
        b_ = c.b();
    }
    
    int r()
    {
        return r_;
    }
    int g()
    {return g_;}
    int b()
    {return b_;}
private:
    int r_, g_, b_;
};

class Circle
{
public:
    Circle(double x, double y, int radius, color &c1, color &c2,
           Surface & surface)
        : x_(x), y_(y), radius_(radius), c1_(c1), c2_(c2),
          surface_(surface) 
    {
        color_= 1;
        colided_ = 0;
        direction_ = rand() % 7;
        switch (direction_)
        {
            //North
            case 0:
                dy_ = 5.1;
                dx_ = 0;
                break;
                //North East
            case 1:
                dy_ = 5.1;
                dx_ = 5.1;
                break;
                //East
            case 2:
                dx_ = 5.1;
                dy_ = 0;
                break;
                //South East
            case 3:
                dy_ = -5.1;
                dx_ = 5.1;
                break;
                //South
            case 4:
                dy_ = -5.1;
                dx_ = 0;
                break;
                //South West
            case 5:
                dy_ = -5.1;
                dx_ = -5.1;
                break;
                //West
            case 6:
                dx_ = -5.1;
                dy_ = 0;
                break;
                //North West
            case 7:
                dy_ = 5.1;
                dx_ = -5.1;
                break;
        }
    }
    //Returning the Center of the Circle
    double x() const
    {
        return x_;
    }
    
    double y()const
    {
        return y_;
    }
    //Returning the Extremes of each Circle
    double leftBound()
    {
        return x_ - radius_;
    }
    double rightBound()
    {
        return x_ + radius_;
    }

    double upperBound()
    {
        return y_ - radius_;
    }
    
    double lowerBound()
    {
        return y_ + radius_;
    }
    void changeDirection()
    {
        double UB = upperBound();
        double LB = lowerBound();
        double rB = rightBound();
        double lB = leftBound();
        if (UB <= 0)
        {
            dy_ = -5.1;
        }
        if (LB > H)
        {
            dy_ = 5.1;
        }
        if (lB <= 0)
        {
            dx_ = 5.1;
        }
        if (rB >= W)
        {
            dy_ = -5.1;
        }
    }
    void update()
    {
        dy_ *= -1;
        dx_ *= -1;
        changeColor();
    }
    void changeColor()
    {
        color_ = !(color_);
    }
    //Drawing and Moving
    void draw()
    {
        if (color_)
        {
            surface_.put_circle(x_, y_, radius_,
                                c1_.r(), c1_.g(), c1_.b());
        }
        else
        {
            surface_.put_circle(x_, y_, radius_,
                                c2_.r(), c2_.g(), c2_.b());
        }
    }
    void move()
    {
        x_ += dx_;
        y_ += dy_;

        if (upperBound() <= 0)
        {
            dy_ = 5.1;
            changeColor();
        }
        if (lowerBound() > H)
        {
            dy_ = -5.1;
            changeColor();
        }
        if (leftBound() <= 0)
        {
            dx_ = 5.1;
            changeColor();
        }
        if (rightBound() >= W)
        {
            dx_ = -5.1;
            changeColor();
        }
    }
    
private:
    double x_, y_;
    int radius_;
    int direction_;
    double dx_, dy_;
    color c1_, c2_;
    bool color_, colided_;
    Surface surface_;
    
};

#endif
