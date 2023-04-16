#ifndef APICONFIG_H
#define APICONFIG_H

/**
 * @file ApiConfig.h
 * @brief API配置文件
 */

#include <string>
#include <vector>
#include <map>

 /**
  * @brief HTTP请求类型
  */
enum class HttpRequestType {
    GET, /**< GET请求 */
    POST, /**< POST请求 */
    PUT, /**< PUT请求 */
    DELETE, /**< DELETE请求 */
};

/**
 * @brief API配置类
 */
class ApiConfig {
public:
    /**
     * @brief 构造函数
     */
    ApiConfig();

    /**
     * @brief 析构函数
     */
    ~ApiConfig();

    /**
     * @brief 添加API请求
     * @param[in] name API名称
     * @param[in] url API URL
     * @param[in] type HTTP请求类型
     */
    void AddApiRequest(const std::string& name, const std::string& url, const HttpRequestType type);

    /**
     * @brief 删除API请求
     * @param[in] name API名称
     */
    void RemoveApiRequest(const std::string& name);

    /**
     * @brief 获取API请求URL
     * @param[in] name API名称
     * @return API请求URL
     */
    std::string GetApiUrl(const std::string& name) const;

    /**
     * @brief 获取API请求类型
     * @param[in] name API名称
     * @return API请求类型
     */
    HttpRequestType GetApiRequestType(const std::string& name) const;

    /**
     * @brief 获取所有API请求名称
     * @return 所有API请求名称
     */
    std::vector<std::string> GetAllApiNames() const;

private:
    std::map<std::string, std::pair<std::string, HttpRequestType>> m_apiRequests; /**< API请求信息 */
};

#endif // APICONFIG_H
