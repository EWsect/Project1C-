#ifndef API_REQUEST_H
#define API_REQUEST_H

#include <string>
#include <map>

class ApiRequest {
public:
    ApiRequest(const std::string& method, const std::string& url, const std::map<std::string, std::string>& headers = {}, const std::string& body = "");

    std::string getMethod() const;
    std::string getUrl() const;
    std::map<std::string, std::string> getHeaders() const;
    std::string getBody() const;

private:
    std::string method_;
    std::string url_;
    std::map<std::string, std::string> headers_;
    std::string body_;
};

/**
 * @brief HTTP������
 *
 * ApiRequest�����ڴ���HTTP����
 */
class ApiRequest {
public:
    /**
     * @brief ���캯��
     *
     * ����һ��HTTP�������
     * @param method ���󷽷�����"GET"��"POST"�ȡ�
     * @param url �����URL��
     * @param headers ����ͷ����һ��std::map<std::string, std::string>�����ʾ��
     * @param body �����壬�������е����ݡ�
     */
    ApiRequest(const std::string& method, const std::string& url, const std::map<std::string, std::string>& headers = {}, const std::string& body = "");

    /**
     * @brief ��ȡ���󷽷�
     *
     * @return �������󷽷���
     */
    std::string getMethod() const;

    /**
     * @brief ��ȡ�����URL
     *
     * @return ���������URL��
     */
    std::string getUrl() const;

    /**
     * @brief ��ȡ����ͷ
     *
     * @return ��������ͷ����һ��std::map<std::string, std::string>�����ʾ��
     */
    std::map<std::string, std::string> getHeaders() const;

    /**
     * @brief ��ȡ������
     *
     * @return ���������壬�������е����ݡ�
     */
    std::string getBody() const;

private:
    std::string method_; ///< ���󷽷�
    std::string url_; ///< �����URL
    std::map<std::string, std::string> headers_; ///< ����ͷ
    std::string body_; ///< �����壬�������е�����
};

#endif // API_REQUEST_H
