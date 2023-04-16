#ifndef APITEST_H
#define APITEST_H

#include "ApiRequest.h"
#include "ApiResponse.h"
#include <iostream>
#include <string>

class ApiTest {
public:
    ApiTest();
    virtual ~ApiTest();

    /**
     * @brief ����HTTP GET����
     * @param url �����URL
     * @param headers ����ͷ����
     * @return ��Ӧ����
     */
    std::string get(const std::string& url, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief ����HTTP POST����
     * @param url �����URL
     * @param params ����Ĳ���
     * @param headers ����ͷ����
     * @return ��Ӧ����
     */
    std::string post(const std::string& url, const std::string& params, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief ����HTTP PUT����
     * @param url �����URL
     * @param data ���������
     * @param headers ����ͷ����
     * @return ��Ӧ����
     */
    std::string put(const std::string& url, const std::string& data, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief ����HTTP DELETE����
     * @param url �����URL
     * @param headers ����ͷ����
     * @return ��Ӧ����
     */
    std::string del(const std::string& url, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

private:
    ApiRequest m_request;
    ApiResponse m_response;
};

#endif // APITEST_H
