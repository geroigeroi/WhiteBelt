//
//  main.cpp
//  ball
//
//  Created by  Mister on 01.11.2020.
//

#include <iostream>

class Ball {
private:
    std::string m_ball;
    double m_radius;
    
public:
    Ball(std::string ball = "red", double radius = 20.0) {
        m_ball = ball;
        m_radius = radius;
    }
    
    /* Ball(std::string ball) {
        m_ball = ball;
        m_radius = 20.0;
    } */
    Ball(double radius) {
        m_radius = radius;
        m_ball = "red";
    }
    /* Ball (std::string ball, double radius) {
        m_ball = ball;
        m_radius = radius;
    } */
    
    void print() const {
        std::cout << "color: " << m_ball << ", radius: " << m_radius << std::endl;
    }
};

int main() {
    
    Ball def;
    def.print();
    
    Ball black("black");
    black.print();
    
    Ball thirty(30);
    thirty.print();
    
    Ball blackThirty("black", 30.0);
    blackThirty.print();
    
    return 0;
}
