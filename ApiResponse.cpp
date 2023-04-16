#include "ApiResponse.h"

// 构造函数，初始化成员变量
ApiResponse::ApiResponse() : m_code(0), m_body("") {}

// 获取响应代码
int ApiResponse::code() const {
    return m_code;
}

// 设置响应代码
void ApiResponse::setCode(int code) {
    m_code = code;
}

// 获取响应体
std::string ApiResponse::body() const {
    return m_body;
}

// 设置响应体
void ApiResponse::setBody(const std::string& body) {
    m_body = body;
}

// 将响应体解析为 Json 对象
Json::Value ApiResponse::toJson() const {
    Json::Value json;
    json["code"] = m_code;
    json["body"] = m_body;
    return json;
}

// 将 Json 对象解析为 ApiResponse 对象
void ApiResponse::fromJson(const Json::Value& json) {
    m_code = json.get("code", 0).asInt();
    m_body = json.get("body", "").asString();
}
