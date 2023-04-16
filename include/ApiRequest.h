#pragma once

#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <sstream>
#include <algorithm>

namespace http {

    // HTTP������
    class ApiRequest {
    public:
        // ���캯��
        ApiRequest(const std::string& url) : url_(url) {}

        // �������ͷ
        void AddHeader(const std::string& key, const std::string& value) {
            headers_.insert(std::make_pair(key, value));
        }

        // ����������
        void SetBody(const std::string& body) {
            body_ = body;
        }

        // ��ȡ�����������ַ���
        std::string GetRequestString() const {
            std::stringstream request_stream;
            request_stream << method_ << " " << url_ << " HTTP/1.1\r\n";
            for (const auto& header : headers_) {
                request_stream << header.first << ": " << header.second << "\r\n";
            }
            if (!body_.empty()) {
                request_stream << "Content-Length: " << body_.size() << "\r\n";
            }
            request_stream << "\r\n";
            if (!body_.empty()) {
                request_stream << body_;
            }
            return request_stream.str();
        }

        // ��������
        void Send() {
            // ���� socket ����
            int sockfd = socket(AF_INET, SOCK_STREAM, 0);
            if (sockfd == -1) {
                throw std::runtime_error("Failed to create socket");
            }

            // ��ȡ IP ��ַ
            struct hostent* server = gethostbyname(url_.c_str());
            if (server == NULL) {
                throw std::runtime_error("Failed to get host by name");
            }
            struct in_addr** addr_list = (struct in_addr**)server->h_addr_list;
            std::string ip_address = inet_ntoa(*addr_list[0]);

            // ���� socket ����
            struct sockaddr_in serv_addr;
            serv_addr.sin_family = AF_INET;
            serv_addr.sin_port = htons(80);
            if (inet_pton(AF_INET, ip_address.c_str(), &serv_addr.sin_addr) <= 0) {
                throw std::runtime_error("Failed to convert IP address");
            }
            if (connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr)) < 0) {
                throw std::runtime_error("Failed to connect to server");
            }

            // ��������
            std::string request_string = GetRequestString();
            const char* request_buffer = request_string.c_str();
            int bytes_sent = send(sockfd, request_buffer, strlen(request_buffer), 0);
            if (bytes_sent < 0) {
                throw std::runtime_error("Failed to send request");
            }

            // ������Ӧ
            char response_buffer[1024] = { 0 };
            std::string response_string;
            int bytes_received = 0;
            while ((bytes_received = recv(sockfd, response_buffer, 1024, 0)) > 0) {
                response_string.append(response_buffer, bytes_received);
            }
            if (bytes_received < 0) {
                throw std::runtime_error("Failed to receive response");
            }

            // �ر� socket ����
            close(sockfd);

            // ������Ӧ
            size_t pos = response_string.find("\r\n\r\n");
            if (pos
