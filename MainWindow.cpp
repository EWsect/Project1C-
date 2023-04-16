#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ApiTest.h"
#include "ApiResponse.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 创建ApiTest对象
    apiTest = new ApiTest();

    // 将apiTest对象的信号与当前对象的槽函数连接
    connect(apiTest, &ApiTest::requestFinished, this, &MainWindow::on_requestFinished);

    // 将请求类型选项卡的条目添加到下拉框中
    ui->cbxRequestType->addItem("GET");
    ui->cbxRequestType->addItem("POST");
    ui->cbxRequestType->addItem("PUT");
    ui->cbxRequestType->addItem("DELETE");

    // 设置响应框的只读属性
    ui->txtResponse->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete apiTest;
}

void MainWindow::on_btnSend_clicked()
{
    // 获取请求类型、请求URL和请求数据
    QString requestType = ui->cbxRequestType->currentText();
    QString requestUrl = ui->txtRequestUrl->text();
    QString requestData = ui->txtRequestData->toPlainText();

    // 发送请求
    apiTest->sendRequest(requestType, requestUrl, requestData);
}

void
