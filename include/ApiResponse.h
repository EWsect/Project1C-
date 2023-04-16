#pragma once

#include <string>
#include <memory>

#include "ApiData.h"

// 定义响应类型的枚举值
enum class ResponseType {
    kSuccess,       // 成功
    kNetworkError,  // 网络错误
    kApiError       // API错误
};

// 定义响应类
class ApiResponse {
public:
    // 默认构造函数，响应类型为成功
    ApiResponse();

    // 构造函数，根据响应类型和消息构造响应对象
    ApiResponse(ResponseType type, const std::string& message = "");

    // 构造函数，根据错误码和消息构造响应对象
    ApiResponse(int errorCode, const std::string& message);

    // 获取响应类型
    ResponseType getType() const { return m_type; }

    // 获取错误码
    int getErrorCode() const { return m_errorCode; }

    // 获取消息
    const std::string& getMessage() const { return m_message; }

    // 设置数据
    void setData(std::shared_ptr<ApiData> data) { m_data = data; }

    // 获取数据
    std::shared_ptr<ApiData> getData() const { return m_data; }

private:
    ResponseType m_type;            // 响应类型
    int m_errorCode;                // 错误码
    std::string m_message;          // 消息
    std::shared_ptr<ApiData> m_data; // 数据
};



/*ApiResponse.h是一个头文件，定义了一个用于表示API响应的类ApiResponse。这个类包含了响应的状态码、响应数据、响应头等信息，并提供了一些操作这些信息的方法。它是用于处理API响应的重要组件之一。在这个项目中，ApiResponse.h和ApiResponse.cpp一起被用于处理API的响应数据。*/
