#ifndef APICONFIG_H
#define APICONFIG_H

/**
 * @file ApiConfig.h
 * @brief API�����ļ�
 */

#include <string>
#include <vector>
#include <map>

 /**
  * @brief HTTP��������
  */
enum class HttpRequestType {
    GET, /**< GET���� */
    POST, /**< POST���� */
    PUT, /**< PUT���� */
    DELETE, /**< DELETE���� */
};

/**
 * @brief API������
 */
class ApiConfig {
public:
    /**
     * @brief ���캯��
     */
    ApiConfig();

    /**
     * @brief ��������
     */
    ~ApiConfig();

    /**
     * @brief ���API����
     * @param[in] name API����
     * @param[in] url API URL
     * @param[in] type HTTP��������
     */
    void AddApiRequest(const std::string& name, const std::string& url, const HttpRequestType type);

    /**
     * @brief ɾ��API����
     * @param[in] name API����
     */
    void RemoveApiRequest(const std::string& name);

    /**
     * @brief ��ȡAPI����URL
     * @param[in] name API����
     * @return API����URL
     */
    std::string GetApiUrl(const std::string& name) const;

    /**
     * @brief ��ȡAPI��������
     * @param[in] name API����
     * @return API��������
     */
    HttpRequestType GetApiRequestType(const std::string& name) const;

    /**
     * @brief ��ȡ����API��������
     * @return ����API��������
     */
    std::vector<std::string> GetAllApiNames() const;

private:
    std::map<std::string, std::pair<std::string, HttpRequestType>> m_apiRequests; /**< API������Ϣ */
};

#endif // APICONFIG_H
