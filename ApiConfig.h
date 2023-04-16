#ifndef API_CONFIG_H
#define API_CONFIG_H

#include <string>
#include <map>

namespace api {

    // ���� API �ӿ����͵�ö��
    enum ApiType {
        HTTP,   // HTTP �ӿ�
        SOAP,   // SOAP �ӿ�
        REST    // REST �ӿ�
    };

    // ���� API �������������͵�ö��
    enum ApiParamType {
        STRING,     // �ַ�������
        NUMBER,     // ��������
        BOOLEAN     // ��������
    };

    // ���� API ���������ݽṹ��
    struct ApiParam {
        ApiParamType type;          // ��������
        std::string value;          // ����ֵ
    };

    // ���� API �ӿڵ����ýṹ��
    struct ApiConfig {
        ApiType type;                               // �ӿ�����
        std::string name;                           // �ӿ�����
        std::string url;                            // �ӿ� URL
        std::string method;                         // �ӿ����󷽷�
        std::map<std::string, ApiParam> params;     // �ӿڲ����б�

        // ���캯������ʼ����Ա����
        ApiConfig(ApiType t, const std::string& n, const std::string& u, const std::string& m) :
            type(t), name(n), url(u), method(m) {}

        // ��Ӳ����ķ�����������Ӻ�Ĳ�������
        int addParam(const std::string& key, ApiParamType type, const std::string& value) {
            params[key] = ApiParam{ type, value };
            return params.size();
        }

        // ��ȡ�����ķ��������ز���ֵ����������������򷵻ؿ��ַ���
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
