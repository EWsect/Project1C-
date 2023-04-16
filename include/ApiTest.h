#ifndef API_TEST_H
#define API_TEST_H

#include "ApiRequest.h"
#include "ApiResponse.h"

/**
 * @brief 用于测试API请求和响应的类
 */
class ApiTest {
public:
    /**
     * @brief 构造函数
     * @param req ApiRequest对象指针
     * @param res ApiResponse对象指针
     */
    ApiTest(ApiRequest* req, ApiResponse* res)
        : m_request(req)
        , m_response(res)
    {}

    /**
     * @brief 发送API请求并接收响应
     * @return 返回是否成功发送和接收到响应
     */
    bool sendRequest() {
        if (!m_request) {
            return false;
        }

        m_response->reset(); // 重置响应对象

        CURLcode res = m_request->sendRequest(); // 发送请求
        if (res != CURLE_OK) { // 请求发送失败
            return false;
        }

        res = m_response->getResponse(); // 接收响应
        if (res != CURLE_OK) { // 响应接收失败
            return false;
        }

        return true;
    }

private:
    ApiRequest* m_request; // API请求对象指针
    ApiResponse* m_response; // API响应对象指针
};

#endif // API_TEST_H
