#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "ApiTest.h"
#include "ApiResponse.h"

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ����ApiTest����
    apiTest = new ApiTest();

    // ��apiTest������ź��뵱ǰ����Ĳۺ�������
    connect(apiTest, &ApiTest::requestFinished, this, &MainWindow::on_requestFinished);

    // ����������ѡ�����Ŀ��ӵ���������
    ui->cbxRequestType->addItem("GET");
    ui->cbxRequestType->addItem("POST");
    ui->cbxRequestType->addItem("PUT");
    ui->cbxRequestType->addItem("DELETE");

    // ������Ӧ���ֻ������
    ui->txtResponse->setReadOnly(true);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete apiTest;
}

void MainWindow::on_btnSend_clicked()
{
    // ��ȡ�������͡�����URL����������
    QString requestType = ui->cbxRequestType->currentText();
    QString requestUrl = ui->txtRequestUrl->text();
    QString requestData = ui->txtRequestData->toPlainText();

    // ��������
    apiTest->sendRequest(requestType, requestUrl, requestData);
}

void
