#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

namespace ApiData {
    // Http请求方法
    enum class HttpMethod {
        GET,
        POST,
        PUT,
        DELETE
    };

    // 请求参数类型
    enum class ParamType {
        STRING,
        INTEGER,
        DOUBLE,
        BOOLEAN
    };

    // 请求参数
    struct RequestParam {
        std::string name;     // 参数名
        ParamType type;       // 参数类型
        std::string value;    // 参数值
    };

    // Http请求配置
    struct RequestConfig {
        HttpMethod method;              // 请求方法
        std::string url;                // 请求url
        std::vector<RequestParam> params;  // 请求参数列表
    };

    // Http响应状态码
    enum class HttpStatus {
        OK = 200,
        BAD_REQUEST = 400,
        UNAUTHORIZED = 401,
        FORBIDDEN = 403,
        NOT_FOUND = 404,
        INTERNAL_SERVER_ERROR = 500
    };

    // Http响应
    struct HttpResponse {
        HttpStatus status;          // 响应状态码
        std::string body;           // 响应体
        std::unordered_map<std::string, std::string> headers;  // 响应头
    };

    // 接口测试函数类型
    typedef std::function<HttpResponse(RequestConfig)> TestFunc;

    // 接口测试数据结构
    struct ApiTest {
        std::string name;           // 接口测试名称
        std::string description;    // 接口测试描述
        TestFunc test_func;         // 接口测试函数
    };

    // Api测试集合
    class ApiTestSuite {
    public:
        // 添加接口测试
        void AddTest(const ApiTest& test);

        // 运行所有接口测试
        void RunAllTests();

        // 获取测试结果
        const std::vector<std::pair<std::string, bool>>& GetTestResults() const;

    private:
        std::vector<ApiTest> m_tests;     // 接口测试列表
        std::vector<std::pair<std::string, bool>> m_results;   // 测试结果列表
    };
}

