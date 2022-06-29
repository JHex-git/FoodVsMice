#include "level/level_manager.h"
void LevelManager::SetLevelName(){//赋值每个关卡的名字，初始化的一部分
    Files levelnames;
    levelnames.getFiles("./levels");
    for (auto i = levelnames.files.begin(); i !=levelnames.files.end(); i++)
    {
        Level *newlevel=new Level;
        newlevel->setname((*i));
        levels.push_back(newlevel);
    }
}

void LevelManager::ReadLevel(char name[])//对指定的关卡名，进行读取关卡
{
    int i;
    for (i = 0 ; i != levels.size() ; i++)
    {   
        if(levels[i]->getname()==name){
            break;
        }
    }
    if(i==levels.size()){
        std::cout<<"error in the read level."<<std::endl;
        std::cout<<"do not find this level."<<std::endl;
        return;
    }
    levels[i]->init();
    
}