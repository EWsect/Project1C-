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
     * @brief 发送HTTP GET请求
     * @param url 请求的URL
     * @param headers 请求头参数
     * @return 响应数据
     */
    std::string get(const std::string& url, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief 发送HTTP POST请求
     * @param url 请求的URL
     * @param params 请求的参数
     * @param headers 请求头参数
     * @return 响应数据
     */
    std::string post(const std::string& url, const std::string& params, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief 发送HTTP PUT请求
     * @param url 请求的URL
     * @param data 请求的数据
     * @param headers 请求头参数
     * @return 响应数据
     */
    std::string put(const std::string& url, const std::string& data, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

    /**
     * @brief 发送HTTP DELETE请求
     * @param url 请求的URL
     * @param headers 请求头参数
     * @return 响应数据
     */
    std::string del(const std::string& url, const std::map<std::string, std::string>& headers = std::map<std::string, std::string>());

private:
    ApiRequest m_request;
    ApiResponse m_response;
};

#endif // APITEST_H
