#include "ApiResponse.h"

// ���캯������ʼ����Ա����
ApiResponse::ApiResponse() : m_code(0), m_body("") {}

// ��ȡ��Ӧ����
int ApiResponse::code() const {
    return m_code;
}

// ������Ӧ����
void ApiResponse::setCode(int code) {
    m_code = code;
}

// ��ȡ��Ӧ��
std::string ApiResponse::body() const {
    return m_body;
}

// ������Ӧ��
void ApiResponse::setBody(const std::string& body) {
    m_body = body;
}

// ����Ӧ�����Ϊ Json ����
Json::Value ApiResponse::toJson() const {
    Json::Value json;
    json["code"] = m_code;
    json["body"] = m_body;
    return json;
}

// �� Json �������Ϊ ApiResponse ����
void ApiResponse::fromJson(const Json::Value& json) {
    m_code = json.get("code", 0).asInt();
    m_body = json.get("body", "").asString();
}
