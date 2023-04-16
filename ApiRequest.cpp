#include "ApiRequest.h"

ApiRequest::ApiRequest(const std::string& url, const HttpMethod& method)
    : m_url(url), m_method(method) {}

void ApiRequest::setUrl(const std::string& url) {
    if (url.empty()) {
        throw std::invalid_argument("Url cannot be empty.");
    }
    m_url = url;
}

void ApiRequest::setMethod(const HttpMethod& method) {
    m_method = method;
}

void ApiRequest::addHeader(const std::string& key, const std::string& value) {
    if (key.empty()) {
        throw std::invalid_argument("Header key cannot be empty.");
    }
    m_headers[key] = value;
}

void ApiRequest::setBody(const std::string& body) {
    m_body = body;
}

std::string ApiRequest::getUrl() const {
    return m_url;
}

HttpMethod ApiRequest::getMethod() const {
    return m_method;
}

std::map<std::string, std::string> ApiRequest::getHeaders() const {
    return m_headers;
}

std::string ApiRequest::getBody() const {
    return m_body;
}
