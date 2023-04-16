#ifndef API_DATA_H
#define API_DATA_H

#include <string>
#include <vector>
#include <map>

namespace api {

    // �����������͵�ö��
    enum DataType {
        STRING,     // �ַ�������
        NUMBER,     // ��������
        BOOLEAN,    // ��������
        OBJECT,     // ��������
        ARRAY       // ��������
    };

    // ����������Ľṹ��
    struct DataItem {
        DataType type;                  // ��������
        std::string value;              // ����ֵ
        std::map<std::string, int> object;    // �������͵�������
        std::vector<DataItem> array;    // �������͵�������

        // ���캯������ʼ����Ա����
        DataItem(DataType t = STRING, const std::string& v = "") : type(t), value(v) {}

        // ��Ӷ�������������ķ�����������Ӻ������������
        int addObject(const std::string& key, int value) {
            object[key] = value;
            return object.size();
        }

        // �����������������ķ�����������Ӻ������������
        int addArrayItem(const DataItem& item) {
            array.push_back(item);
            return array.size();
        }

        // ��ȡ��������������ķ����������������ֵ������������򷵻� 0
        int getObjectValue(const std::string& key) const {
            if (object.count(key) == 0) {
                return 0;
            }
            else {
                return object.at(key);
            }
        }

        // ��ȡ��������������ķ����������������ֵ������±�Խ���򷵻ؿյ� DataItem ����
        const DataItem& getArrayItem(int index) const {
            if (index < 0 || index >= array.size()) {
                static DataItem empty;
                return empty;
            }
            else {
                return array[index];
            }
        }
    };

    // �������ݶ���Ľṹ��
    struct DataObject {
        std::map<std::string, DataItem> items;  // �������б�

        // ���������ķ�����������Ӻ������������
        int addItem(const std::string& key, const DataItem& item) {
            items[key] = item;
            return items.size();
        }

        // ��ȡ������ķ����������������ֵ������������򷵻ؿյ� DataItem ����
        const DataItem& getItem(const std::string& key) const {
            if (items.count(key) == 0) {
                static DataItem empty;
                return empty;
            }
            else {
                return items.at(key);
            }
        }
    };

}  // namespace api

#endif  // API_DATA_H
