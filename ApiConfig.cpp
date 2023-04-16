#include "ApiConfig.h"

#include <iostream>
#include <fstream>

// 定义静态成员变量
std::string ApiConfig::s_configFilePath = "config.ini";
int ApiConfig::s_timeout = 10;

// 获取配置文件路径
std::string ApiConfig::GetConfigFilePath() {
    return s_configFilePath;
}

// 设置配置文件路径
void ApiConfig::SetConfigFilePath(const std::string& path) {
    s_configFilePath = path;
}

// 获取超时时间
int ApiConfig::GetTimeout() {
    return s_timeout;
}

// 设置超时时间
void ApiConfig::SetTimeout(int timeout) {
    s_timeout = timeout;
}

// 加载配置文件
void ApiConfig::LoadConfig() {
    std::ifstream configFile(s_configFilePath);

    if (configFile.is_open()) {
        std::string line;

        while (std::getline(configFile, line)) {
            size_t separatorPos = line.find('=');

            if (separatorPos != std::string::npos) {
                std::string key = line.substr(0, separatorPos);
                std::string value = line.substr(separatorPos + 1);

                // 去掉字符串前后的空格
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

// 去掉字符串前后的空格
std::string ApiConfig::Trim(const std::string& str) {
    size_t first = str.find_first_not_of(' ');
    size_t last = str.find_last_not_of(' ');

    if (first == std::string::npos || last == std::string::npos) {
        return "";
    }

    return str.substr(first, last - first + 1);
}
