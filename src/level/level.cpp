#include "level/level.h"
void Level::init()//具体数值和接口存疑
{
    char path[] = "./levels/", tmppath[200] = { 0 };
	strcat(strcat(tmppath, path), name.c_str());
	FILE* fp = fopen(tmppath, "rb");
	// ::fread(&mapState, sizeof(mapState), 1, fp);等read操作

    fclose(fp);
}