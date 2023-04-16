#pragma once

#include <string>
#include <memory>

#include "ApiData.h"

// ������Ӧ���͵�ö��ֵ
enum class ResponseType {
    kSuccess,       // �ɹ�
    kNetworkError,  // �������
    kApiError       // API����
};

// ������Ӧ��
class ApiResponse {
public:
    // Ĭ�Ϲ��캯������Ӧ����Ϊ�ɹ�
    ApiResponse();

    // ���캯����������Ӧ���ͺ���Ϣ������Ӧ����
    ApiResponse(ResponseType type, const std::string& message = "");

    // ���캯�������ݴ��������Ϣ������Ӧ����
    ApiResponse(int errorCode, const std::string& message);

    // ��ȡ��Ӧ����
    ResponseType getType() const { return m_type; }

    // ��ȡ������
    int getErrorCode() const { return m_errorCode; }

    // ��ȡ��Ϣ
    const std::string& getMessage() const { return m_message; }

    // ��������
    void setData(std::shared_ptr<ApiData> data) { m_data = data; }

    // ��ȡ����
    std::shared_ptr<ApiData> getData() const { return m_data; }

private:
    ResponseType m_type;            // ��Ӧ����
    int m_errorCode;                // ������
    std::string m_message;          // ��Ϣ
    std::shared_ptr<ApiData> m_data; // ����
};



/*ApiResponse.h��һ��ͷ�ļ���������һ�����ڱ�ʾAPI��Ӧ����ApiResponse��������������Ӧ��״̬�롢��Ӧ���ݡ���Ӧͷ����Ϣ�����ṩ��һЩ������Щ��Ϣ�ķ������������ڴ���API��Ӧ����Ҫ���֮һ���������Ŀ�У�ApiResponse.h��ApiResponse.cppһ�����ڴ���API����Ӧ���ݡ�*/
