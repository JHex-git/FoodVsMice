#pragma once
#include <iostream>
#include <string>
#include <io.h>
#include <stdio.h>
class Level
{
public:
    void init();//对关卡初始化
    std::string getname(){
        return name;
    }
    void setname(std::string a){
        name=a;
    }
private:
    std::string name;
};

