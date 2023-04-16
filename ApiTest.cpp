#include "ApiTest.h"
#include "ApiRequest.h"
#include "ApiResponse.h"
#include <iostream>

using namespace std;

void ApiTest::testGetRequest() {
    ApiRequest request("https://jsonplaceholder.typicode.com/posts/1");
    request.setHeader("Accept", "application/json");

    ApiResponse response = request.get();

    if (response.isSuccess()) {
        cout << "Get Request Test Passed!" << endl;
        cout << "Response Body:" << endl;
        cout << response.getBody() << endl;
    }
    else {
        cout << "Get Request Test Failed!" << endl;
        cout << "Error Message: " << response.getErrorMessage() << endl;
    }
}

void ApiTest::testPostRequest() {
    ApiRequest request("https://jsonplaceholder.typicode.com/posts");
    request.setHeader("Content-Type", "application/json");
    request.setHeader("Accept", "application/json");

    string body = "{\"title\": \"foo\", \"body\": \"bar\", \"userId\": 1}";
    request.setBody(body);

    ApiResponse response = request.post();

    if (response.isSuccess()) {
        cout << "Post Request Test Passed!" << endl;
        cout << "Response Body:" << endl;
        cout << response.getBody() << endl;
    }
    else {
        cout << "Post Request Test Failed!" << endl;
        cout << "Error Message: " << response.getErrorMessage() << endl;
    }
}

void ApiTest::testPutRequest() {
    ApiRequest request("https://jsonplaceholder.typicode.com/posts/1");
    request.setHeader("Content-Type", "application/json");
    request.setHeader("Accept", "application/json");

    string body = "{\"id\": 1, \"title\": \"foo\", \"body\": \"bar\", \"userId\": 1}";
    request.setBody(body);

    ApiResponse response = request.put();

    if (response.isSuccess()) {
        cout << "Put Request Test Passed!" << endl;
        cout << "Response Body:" << endl;
        cout << response.getBody() << endl;
    }
    else {
        cout << "Put Request Test Failed!" << endl;
        cout << "Error Message: " << response.getErrorMessage() << endl;
    }
}

void ApiTest::testDeleteRequest() {
    ApiRequest request("https://jsonplaceholder.typicode.com/posts/1");
    request.setHeader("Accept", "application/json");

    ApiResponse response = request.del();

    if (response.isSuccess()) {
        cout << "Delete Request Test Passed!" << endl;
    }
    else {
        cout << "Delete Request Test Failed!" << endl;
        cout << "Error Message: " << response.getErrorMessage() << endl;
    }
}
