#ifndef API_RESPONSE_H
#define API_RESPONSE_H

#include <string>
#include <vector>
#include <map>

// 定义响应头部信息结构体
struct ApiResponseHeader {
    std::string name;  // 头部字段名
    std::vector<std::string> values;  // 头部字段值
};

// 定义响应数据结构体
struct ApiResponse {
    int statusCode;  // 响应状态码
    std::string body;  // 响应正文
    std::vector<ApiResponseHeader> headers;  // 响应头部信息
};

// 响应处理类
class ApiResponseHandler {
public:
    virtual ~ApiResponseHandler() {}

    // 处理响应数据，返回响应数据结构体
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) = 0;

    // 返回处理器名称
    virtual std::string getName() const = 0;
};

// JSON 格式响应处理器
class JsonApiResponseHandler : public ApiResponseHandler {
public:
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) override {
        // JSON 处理逻辑
        ApiResponse response;
        response.statusCode = statusCode;
        response.body = responseBody;
        response.headers = responseHeaders;
        return response;
    }

    virtual std::string getName() const override {
        return "JsonApiResponseHandler";
    }
};

// XML 格式响应处理器
class XmlApiResponseHandler : public ApiResponseHandler {
public:
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) override {
        // XML 处理逻辑
        ApiResponse response;
        response.statusCode = statusCode;
        response.body = responseBody;
        response.headers = responseHeaders;
        return response;
    }

    virtual std::string getName() const override {
        return "XmlApiResponseHandler";
    }
};

#endif // API_RESPONSE_H
