#pragma once
#include <iostream>
#include <cassert>

#define ASSERT(a, b) assert((a) && (b))

#define DEBUG_INFO(info) std::cout<<__FILE__<<":"<<__LINE__<<" @"<<(info)<<std::endl
