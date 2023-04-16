#include "ApiConfig.h"

#include <iostream>
#include <fstream>

// ���徲̬��Ա����
std::string ApiConfig::s_configFilePath = "config.ini";
int ApiConfig::s_timeout = 10;

// ��ȡ�����ļ�·��
std::string ApiConfig::GetConfigFilePath() {
    return s_configFilePath;
}

// ���������ļ�·��
void ApiConfig::SetConfigFilePath(const std::string& path) {
    s_configFilePath = path;
}

// ��ȡ��ʱʱ��
int ApiConfig::GetTimeout() {
    return s_timeout;
}

// ���ó�ʱʱ��
void ApiConfig::SetTimeout(int timeout) {
    s_timeout = timeout;
}

// ���������ļ�
void ApiConfig::LoadConfig() {
    std::ifstream configFile(s_configFilePath);

    if (configFile.is_open()) {
        std::string line;

        while (std::getline(configFile, line)) {
            size_t separatorPos = line.find('=');

            if (separatorPos != std::string::npos) {
                std::string key = line.substr(0, separatorPos);
                std::string value = line.substr(separatorPos + 1);

                // ȥ���ַ���ǰ��Ŀո�
                key = Trim(key);
                value = Trim(value);

                if (key == "timeout") {
                    s_timeout = std::stoi(value);
                }
            }
        }

        configFile.close();
    }
    else {
        std::cout << "Failed to open config file: " << s_configFilePath << std::endl;
    }
}

// ȥ���ַ���ǰ��Ŀո�
std::string ApiConfig::Trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }

    return str.substr(first, last - first + 1);
}
