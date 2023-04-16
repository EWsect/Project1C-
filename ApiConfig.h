#ifndef API_CONFIG_H
#define API_CONFIG_H

#include <string>
#include <map>

namespace api {

    // 定义 API 接口类型的枚举
    enum ApiType {
        HTTP,   // HTTP 接口
        SOAP,   // SOAP 接口
        REST    // REST 接口
    };

    // 定义 API 参数的数据类型的枚举
    enum ApiParamType {
        STRING,     // 字符串类型
        NUMBER,     // 数字类型
        BOOLEAN     // 布尔类型
    };

    // 定义 API 参数的数据结构体
    struct ApiParam {
        ApiParamType type;          // 参数类型
        std::string value;          // 参数值
    };

    // 定义 API 接口的配置结构体
    struct ApiConfig {
        ApiType type;                               // 接口类型
        std::string name;                           // 接口名称
        std::string url;                            // 接口 URL
        std::string method;                         // 接口请求方法
        std::map<std::string, ApiParam> params;     // 接口参数列表

        // 构造函数，初始化成员变量
        ApiConfig(ApiType t, const std::string& n, const std::string& u, const std::string& m) :
            type(t), name(n), url(u), method(m) {}

        // 添加参数的方法，返回添加后的参数数量
        int addParam(const std::string& key, ApiParamType type, const std::string& value) {
            params[key] = ApiParam{ type, value };
            return params.size();
        }

        // 获取参数的方法，返回参数值，如果参数不存在则返回空字符串
        std::string getParamValue(const std::string& key) const {
            if (params.count(key) == 0) {
                return "";
            }
            else {
                return params.at(key).value;
            }
        }
    };

}  // namespace api

#endif  // API_CONFIG_H
