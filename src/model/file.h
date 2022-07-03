#pragma once
#include <iostream>
#include <string>
#include <io.h>
#include <vector>
#include <stdio.h>
class Files {
public:
    void getFiles(std::string path);
    std::vector<std::string> files;
};
