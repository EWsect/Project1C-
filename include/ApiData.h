#pragma once

#include <string>
#include <vector>
#include <unordered_map>
#include <functional>

namespace ApiData {
    // Http���󷽷�
    enum class HttpMethod {
        GET,
        POST,
        PUT,
        DELETE
    };

    // �����������
    enum class ParamType {
        STRING,
        INTEGER,
        DOUBLE,
        BOOLEAN
    };

    // �������
    struct RequestParam {
        std::string name;     // ������
        ParamType type;       // ��������
        std::string value;    // ����ֵ
    };

    // Http��������
    struct RequestConfig {
        HttpMethod method;              // ���󷽷�
        std::string url;                // ����url
        std::vector<RequestParam> params;  // ��������б�
    };

    // Http��Ӧ״̬��
    enum class HttpStatus {
        OK = 200,
        BAD_REQUEST = 400,
        UNAUTHORIZED = 401,
        FORBIDDEN = 403,
        NOT_FOUND = 404,
        INTERNAL_SERVER_ERROR = 500
    };

    // Http��Ӧ
    struct HttpResponse {
        HttpStatus status;          // ��Ӧ״̬��
        std::string body;           // ��Ӧ��
        std::unordered_map<std::string, std::string> headers;  // ��Ӧͷ
    };

    // �ӿڲ��Ժ�������
    typedef std::function<HttpResponse(RequestConfig)> TestFunc;

    // �ӿڲ������ݽṹ
    struct ApiTest {
        std::string name;           // �ӿڲ�������
        std::string description;    // �ӿڲ�������
        TestFunc test_func;         // �ӿڲ��Ժ���
    };

    // Api���Լ���
    class ApiTestSuite {
    public:
        // ��ӽӿڲ���
        void AddTest(const ApiTest& test);

        // �������нӿڲ���
        void RunAllTests();

        // ��ȡ���Խ��
        const std::vector<std::pair<std::string, bool>>& GetTestResults() const;

    private:
        std::vector<ApiTest> m_tests;     // �ӿڲ����б�
        std::vector<std::pair<std::string, bool>> m_results;   // ���Խ���б�
    };
}

