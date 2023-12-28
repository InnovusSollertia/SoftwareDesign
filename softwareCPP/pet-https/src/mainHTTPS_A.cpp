// Correct work function freeaddrinfo in MinGW
// In detail - http://stackoverflow.com/a/20306451

#define _WIN32_WINNT 0x501
#include <iostream>
#include <sstream>
#include <string>
#include <WinSock2.h>
#include <WS2tcpip.h>

// For work with sockets

#pragma comment(lib, "Ws2_32.lib")
using std::cerr;

int main()
{
    WSADATA wsaData; // Service structure for correct work server
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);

    // If error download WSAStartup
    if (result != 0) {
        cerr << "WSAStartup failed: " << result << "\n";
        return result;
    }

    struct addrinfo* addr = NULL; // Structure which save IP-adress

    struct addrinfo hints; // Template for initialization structure data
    ZeroMemory(&hints, sizeof(hints));

    hints.ai_family = AF_INET;
    hints.ai_socktype = SOCK_STREAM; // Add type of socket
    hints.ai_protocol = IPPROTO_TCP; // Work with TCP-protocol
    hints.ai_flags = AI_PASSIVE;

    // Our HTTP-server work in 8000-port in localhost
    result = getaddrinfo("127.0.0.1", "8000", &hints, &addr);

    // If error download server
    if (result != 0) {
        cerr << "getaddrinfo failed: " << result << "\n";
        WSACleanup();
        return 1; // exit
    }

    // Create socket
    int listen_socket = socket(addr->ai_family, addr->ai_socktype,
        addr->ai_protocol);

    // If error download socket
    if (listen_socket == INVALID_SOCKET) {
        cerr << "Error at socket: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        WSACleanup();
        return 1; // exit
    }

    // Socket -> IP-adress
    result = bind(listen_socket, addr->ai_addr, (int)addr->ai_addrlen);

    if (result == SOCKET_ERROR) {
        cerr << "bind failed with error: " << WSAGetLastError() << "\n";
        freeaddrinfo(addr);
        closesocket(listen_socket);
        WSACleanup();
        return 1;
    }

    // Initialization a listening-to socket
    if (listen(listen_socket, SOMAXCONN) == SOCKET_ERROR) {
        cerr << "listen failed with error: " << WSAGetLastError() << "\n";
        closesocket(listen_socket);
        WSACleanup();
        return 1; // exit
    }

    const int max_client_buffer_size = 1024;
    char buf[max_client_buffer_size];
    int client_socket = INVALID_SOCKET;

    for (;;) {
        // Accept incoming connections
        client_socket = accept(listen_socket, NULL, NULL);
        if (client_socket == INVALID_SOCKET) {
            cerr << "accept failed: " << WSAGetLastError() << "\n";
            closesocket(listen_socket);
            WSACleanup();
            return 1; // exit
        }

        result = recv(client_socket, buf, max_client_buffer_size, 0);

        std::stringstream response; // Answer for client
        std::stringstream response_body; // Answer-body

        if (result == SOCKET_ERROR) {
            // Error transmiting data
            cerr << "Recv failed: " << result << "\n";
            closesocket(client_socket);
        }
        else if (result == 0) {
            // Client close of connection 
            cerr << "Connection closed...\n";
        }
        else if (result > 0) {
            buf[result] = '\0';

            // Data was received successfully
            // Create HTML-body
            response_body << "<title>Test C++ HTTP Server</title>\n"
                << "<h1>Test page</h1>\n"
                << "<p>This is body of the test page...</p>\n"
                << "<h2>Request headers</h2>\n"
                << "<pre>" << buf << "</pre>\n"
                << "<em><small>Test C++ Http Server</small></em>\n";

            // Create answer and headers
            response << "HTTP/1.1 200 OK\r\n"
                << "Version: HTTP/1.1\r\n"
                << "Content-Type: text/html; charset=utf-8\r\n"
                << "Content-Length: " << response_body.str().length()
                << "\r\n\r\n"
                << response_body.str();

            // Send answer with "send"
            result = send(client_socket, response.str().c_str(),
                response.str().length(), 0);

            // If error with transmition data
            if (result == SOCKET_ERROR) {
                cerr << "send failed: " << WSAGetLastError() << "\n";
            }
            // Close connection
            closesocket(client_socket);
        }
    }

    // Clean up
    closesocket(listen_socket);
    freeaddrinfo(addr);
    WSACleanup();
    return 0;
}