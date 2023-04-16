#ifndef API_DATA_H
#define API_DATA_H

#include <string>
#include <vector>
#include <map>

namespace api {

    // 定义数据类型的枚举
    enum DataType {
        STRING,     // 字符串类型
        NUMBER,     // 数字类型
        BOOLEAN,    // 布尔类型
        OBJECT,     // 对象类型
        ARRAY       // 数组类型
    };

    // 定义数据项的结构体
    struct DataItem {
        DataType type;                  // 数据类型
        std::string value;              // 数据值
        std::map<std::string, int> object;    // 对象类型的数据项
        std::vector<DataItem> array;    // 数组类型的数据项

        // 构造函数，初始化成员变量
        DataItem(DataType t = STRING, const std::string& v = "") : type(t), value(v) {}

        // 添加对象类型数据项的方法，返回添加后的数据项数量
        int addObject(const std::string& key, int value) {
            object[key] = value;
            return object.size();
        }

        // 添加数组类型数据项的方法，返回添加后的数据项数量
        int addArrayItem(const DataItem& item) {
            array.push_back(item);
            return array.size();
        }

        // 获取对象类型数据项的方法，返回数据项的值，如果不存在则返回 0
        int getObjectValue(const std::string& key) const {
            if (object.count(key) == 0) {
                return 0;
            }
            else {
                return object.at(key);
            }
        }

        // 获取数组类型数据项的方法，返回数据项的值，如果下标越界则返回空的 DataItem 对象
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

    // 定义数据对象的结构体
    struct DataObject {
        std::map<std::string, DataItem> items;  // 数据项列表

        // 添加数据项的方法，返回添加后的数据项数量
        int addItem(const std::string& key, const DataItem& item) {
            items[key] = item;
            return items.size();
        }

        // 获取数据项的方法，返回数据项的值，如果不存在则返回空的 DataItem 对象
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
