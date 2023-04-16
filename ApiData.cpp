#include "ApiData.h"

#include <iostream>

using namespace std;

// ��ʼ����̬��Ա����
unordered_map<string, ApiData*> ApiData::s_instanceMap;

ApiData::ApiData(const string& name, const string& value) : m_name(name), m_value(value) {
    // ����ǰ������뾲̬ʵ��ӳ�����
    s_instanceMap[name] = this;
}

ApiData::~ApiData() {
    // �Ӿ�̬ʵ��ӳ������Ƴ���ǰ����
    s_instanceMap.erase(m_name);
}

ApiData* ApiData::getInstance(const string& name) {
    // �ھ�̬ʵ��ӳ����в���ָ�����Ƶ�ʵ��
    auto iter = s_instanceMap.find(name);
    if (iter != s_instanceMap.end()) {
        return iter->second;
    }
    return nullptr;
}

void ApiData::printAllInstances() {
    // ������̬ʵ��ӳ������ÿ��ʵ�������ƺ�ֵ
    for (auto& pair : s_instanceMap) {
        cout << "Name: " << pair.second->getName() << ", Value: " << pair.second->getValue() << endl;
    }
}
