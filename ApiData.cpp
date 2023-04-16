#include "ApiData.h"

#include <iostream>

using namespace std;

// 初始化静态成员变量
unordered_map<string, ApiData*> ApiData::s_instanceMap;

ApiData::ApiData(const string& name, const string& value) : m_name(name), m_value(value) {
    // 将当前对象加入静态实例映射表中
    s_instanceMap[name] = this;
}

ApiData::~ApiData() {
    // 从静态实例映射表中移除当前对象
    s_instanceMap.erase(m_name);
}

ApiData* ApiData::getInstance(const string& name) {
    // 在静态实例映射表中查找指定名称的实例
    auto iter = s_instanceMap.find(name);
    if (iter != s_instanceMap.end()) {
        return iter->second;
    }
    return nullptr;
}

void ApiData::printAllInstances() {
    // 遍历静态实例映射表并输出每个实例的名称和值
    for (auto& pair : s_instanceMap) {
        cout << "Name: " << pair.second->getName() << ", Value: " << pair.second->getValue() << endl;
    }
}
