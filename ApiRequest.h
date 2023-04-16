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
 * @brief HTTP请求类
 *
 * ApiRequest类用于创建HTTP请求。
 */
class ApiRequest {
public:
    /**
     * @brief 构造函数
     *
     * 创建一个HTTP请求对象。
     * @param method 请求方法，如"GET"、"POST"等。
     * @param url 请求的URL。
     * @param headers 请求头，用一个std::map<std::string, std::string>对象表示。
     * @param body 请求体，即请求中的数据。
     */
    ApiRequest(const std::string& method, const std::string& url, const std::map<std::string, std::string>& headers = {}, const std::string& body = "");

    /**
     * @brief 获取请求方法
     *
     * @return 返回请求方法。
     */
    std::string getMethod() const;

    /**
     * @brief 获取请求的URL
     *
     * @return 返回请求的URL。
     */
    std::string getUrl() const;

    /**
     * @brief 获取请求头
     *
     * @return 返回请求头，用一个std::map<std::string, std::string>对象表示。
     */
    std::map<std::string, std::string> getHeaders() const;

    /**
     * @brief 获取请求体
     *
     * @return 返回请求体，即请求中的数据。
     */
    std::string getBody() const;

private:
    std::string method_; ///< 请求方法
    std::string url_; ///< 请求的URL
    std::map<std::string, std::string> headers_; ///< 请求头
    std::string body_; ///< 请求体，即请求中的数据
};

#endif // API_REQUEST_H
