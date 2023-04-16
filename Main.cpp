#include <iostream>
#include "ApiConfig.h"
#include "MainWindow.h"

int main(int argc, char* argv[])
{
    // ��ʼ��ȫ������
    ApiConfig::GetInstance().LoadConfig("config.ini");

    // ����������
    MainWindow mainWindow;

    // ��ʾ������
    mainWindow.show();

    // ������Ϣѭ��
    return QApplication::exec();
}
