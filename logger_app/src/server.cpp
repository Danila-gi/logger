#include <iostream>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>

/* Функция для запуска сервера */
int main(){
    int listener, sock;
    struct sockaddr_in addr;
    char buf[1024];
    int bytes_read;
    bool stop_server = false;

    listener = socket(AF_INET, SOCK_STREAM, 0);

    if (listener < 0){
        std::cerr << "Socket error" << std::endl;
        exit(1);
    }
    
    addr.sin_family = AF_INET;
    addr.sin_port = htons(8000);
    addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if (bind(listener, (struct sockaddr *)&addr, sizeof(addr)) < 0){
        std::cerr << "Bind error" << std::endl;
        exit(1);
    }

    listen(listener, 1);
    std::cout << "Start listen..." << std::endl;

    while (true){
        sock = accept(listener, NULL, NULL);
        if (sock < 0){
            perror("accept");
            exit(3);
        }

        while (true){
            bytes_read = recv(sock, buf, 1024, 0);
            if (bytes_read <= 0)
                break;
            buf[bytes_read] = '\0';
            std::string buf_str = buf;
            if (buf_str.find("STOP SERVER") != std::string::npos){
                stop_server = true;
                break;
            }
            std::cout << buf << std::endl;
        }
    
        close(sock);
        if (stop_server)
            break;
    }
    std::cout << "Stop server..." << std::endl;

    return 0;
}