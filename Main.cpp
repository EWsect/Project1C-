#include <iostream>
#include "ApiConfig.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    // 初始化全局配置
    ApiConfig::GetInstance().LoadConfig("config.ini");

    // 创建主窗口
    MainWindow mainWindow;

    // 显示主窗口
    mainWindow.show();

    // 进入消息循环
    return QApplication::exec();
}
