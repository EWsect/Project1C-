#ifndef API_TEST_H
#define API_TEST_H

#include "ApiRequest.h"
#include "ApiResponse.h"

/**
 * @brief ���ڲ���API�������Ӧ����
 */
class ApiTest {
public:
    /**
     * @brief ���캯��
     * @param req ApiRequest����ָ��
     * @param res ApiResponse����ָ��
     */
    ApiTest(ApiRequest* req, ApiResponse* res)
        : m_request(req)
        , m_response(res)
    {}

    /**
     * @brief ����API���󲢽�����Ӧ
     * @return �����Ƿ�ɹ����ͺͽ��յ���Ӧ
     */
    bool sendRequest() {
        if (!m_request) {
            return false;
        }

        m_response->reset(); // ������Ӧ����

        CURLcode res = m_request->sendRequest(); // ��������
        if (res != CURLE_OK) { // ������ʧ��
            return false;
        }

        res = m_response->getResponse(); // ������Ӧ
        if (res != CURLE_OK) { // ��Ӧ����ʧ��
            return false;
        }

        return true;
    }

private:
    ApiRequest* m_request; // API�������ָ��
    ApiResponse* m_response; // API��Ӧ����ָ��
};

#endif // API_TEST_H
