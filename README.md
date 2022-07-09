本项目是在Qt6.3.1上开发的游戏程序，用QMake进行构建，用MinGW 64位进行编译，需要用到Qt6的动态链接库Qt6Gui.dll、Qt6Multimedia.dll、Qt6Core.dll、Qt6Widgets.dll、QtNetwork.dll。该程序无法在Qt5下运行。

关卡支持自定义，关卡的设计文件在resources/level下，如何进行设计请参考doc/level_description.md。



已知问题：

PitchProjectile的target指向的内存空间可能已经被释放，需要额外处理（两处）。Try Catch语句并不能捕获该系统段错误。