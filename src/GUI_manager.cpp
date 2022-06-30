#include"GUI_manager.h"

void GUIManager::loading()
{
    loadImages(peashooter, "./resources/picture/peashooter/Peashooter_", 8, 1);
	loadImages(normalZombieWalkPictures, "./resources/picture/Zombies/NormalZombie/Zombie/Zombie-", 47, 1);
	loadImages(coneheadZombieWalkPictures, "./resources/picture/Zombies/ConeheadZombie/ConeheadZombie/ConeheadZombie-", 47, 1);
	loadImages(bucketheadZombieWalkPictures, "./resources/picture/Zombies/BucketheadZombie/BucketheadZombie/BucketheadZombie-", 47, 1);
	loadImages(normalZombieEatPictures, "./resources/picture/Zombies/NormalZombie/ZombieAttack/ZombieAttack_", 10, 0);
	loadImages(coneheadZombieEatPictures, "./resources/picture/Zombies/ConeheadZombie/ConeheadZombieAttack/ConeheadZombieAttack_", 10, 0);
	loadImages(bucketheadZombieEatPictures, "./resources/picture/Zombies/BucketheadZombie/BucketheadZombieAttack/BucketheadZombieAttack_", 10, 0);
	loadimage(&background, "./resources/picture/Screen/Background.jpg");
	loadimage(&lawnmower, "./resources/picture/Screen/lawnmower.png",45,35);
    loadimage(&PB,"./resources/picture/Plants/PB00.png");
}

void GUIManager::Draw_background()
{
    putimage(0, 0, &background);
    for (int i = 1; i <= 5; i++)
        drawAlpha(&lawnmower, 0, 100*i);
}

void GUIManager::loadImages(IMAGE imgs[], char path[], int n, int begin)
{
	for (int i = 0; i < n; i++)
	{
		char tmpPath[200], frameNo[4];
		strcpy_s(tmpPath, 200, path);
		strcat(strcat(tmpPath, itoa(i + begin, frameNo, 10)), ".png");
		loadimage(&imgs[i], tmpPath);
	}   
}


void GUIManager::drawAlpha(IMAGE *picture, int picture_x, int picture_y)
{
    DWORD *dst = GetImageBuffer();    							// GetImageBuffer()函数，用于获取绘图设备的显存指针，EASYX自带
	DWORD *draw = GetImageBuffer(); 
	DWORD *src = GetImageBuffer(picture); 						//获取picture的显存指针
	int picture_width = picture->getwidth(); 					//获取picture的宽度，EASYX自带
	int picture_height = picture->getheight(); 					//获取picture的高度，EASYX自带
	int graphWidth = getwidth();       							//获取绘图区的宽度，EASYX自带
	int graphHeight = getheight();     							//获取绘图区的高度，EASYX自带
	int dstX = 0;    											//在显存里像素的角标                                                            
	for (int iy = 0; iy < picture_height; iy++)                 // 实现透明贴图 公式： Cp=αp*FP+(1-αp)*BP ， 贝叶斯定理来进行点颜色的概率计算
	{
		for (int ix = 0; ix < picture_width; ix++)
		{
			int srcX = ix + iy * picture_width;                 //在显存里像素的角标
			int sa = ((src[srcX] & 0xff000000) >> 24);          //0xAArrggbb;AA是透明度
			int sr = ((src[srcX] & 0xff0000) >> 16);            //获取RGB里的R
			int sg = ((src[srcX] & 0xff00) >> 8);               //G
			int sb = src[srcX] & 0xff;                          //B
			if (ix >= 0 && ix <= graphWidth && iy >= 0 && iy <= graphHeight && dstX <= graphWidth * graphHeight)
			{
				dstX = (ix + picture_x) + (iy + picture_y) * graphWidth; //在显存里像素的角标
				int dr = ((dst[dstX] & 0xff0000) >> 16);
				int dg = ((dst[dstX] & 0xff00) >> 8);
				int db = dst[dstX] & 0xff;
				draw[dstX] = ((sr * sa / 255 + dr * (255 - sa) / 255) << 16)  //公式： Cp=αp*FP+(1-αp)*BP  ； αp=sa/255 , FP=sr , BP=dr
					| ((sg * sa / 255 + dg * (255 - sa) / 255) << 8)         //αp=sa/255 , FP=sg , BP=dg
					| (sb * sa / 255 + db * (255 - sa) / 255);              //αp=sa/255 , FP=sb , BP=db
			}
		}
	}
}


void GUIManager::Draw_plant(IMAGE plant_img[])
{
    int plant_temp = Picture_num;
    plant_temp = plant_temp % 8;
    this->drawAlpha(&plant_img[plant_temp], plant_x, plant_y);
}

void GUIManager::Draw_zombie(IMAGE zombie_img[])
{
    int zombie_temp = Picture_num;
    zombie_temp = zombie_temp % 47;
    this->drawAlpha(&zombie_img[zombie_temp], plant_x, plant_y);
}
