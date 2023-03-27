#pragma once
#include <iostream>
#include <cassert>
#ifdef DEBUG
#define ASSERT(a, b) assert((a) && (b))

#define DEBUG_INFO(info) std::cout<<__FILE__<<":"<<__LINE__<<" @"<<(info)<<std::endl
#else
#define ASSERT(a, b)

#define DEBUG_INFO(info)
#endif
