#ifndef API_RESPONSE_H
#define API_RESPONSE_H

#include <string>
#include <vector>
#include <map>

// ������Ӧͷ����Ϣ�ṹ��
struct ApiResponseHeader {
    std::string name;  // ͷ���ֶ���
    std::vector<std::string> values;  // ͷ���ֶ�ֵ
};

// ������Ӧ���ݽṹ��
struct ApiResponse {
    int statusCode;  // ��Ӧ״̬��
    std::string body;  // ��Ӧ����
    std::vector<ApiResponseHeader> headers;  // ��Ӧͷ����Ϣ
};

// ��Ӧ������
class ApiResponseHandler {
public:
    virtual ~ApiResponseHandler() {}

    // ������Ӧ���ݣ�������Ӧ���ݽṹ��
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) = 0;

    // ���ش���������
    virtual std::string getName() const = 0;
};

// JSON ��ʽ��Ӧ������
class JsonApiResponseHandler : public ApiResponseHandler {
public:
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) override {
        // JSON �����߼�
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

// XML ��ʽ��Ӧ������
class XmlApiResponseHandler : public ApiResponseHandler {
public:
    virtual ApiResponse handleResponse(const std::string& responseBody, int statusCode, const std::vector<ApiResponseHeader>& responseHeaders) override {
        // XML �����߼�
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
