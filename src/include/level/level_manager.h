#pragma once
#include <iostream>
#include <string>
#include <io.h>
#include <vector>
#include <stdio.h>
#include "level/level.h"
#include "file.h"
class LevelManager
{
public:
    void SetLevelName();
    void ReadLevel(char name[]);
    void NextLevel();
private:
    std::vector<Level*> levels;
};