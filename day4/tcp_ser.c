#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>               // for close()
#include <arpa/inet.h>           // for inet_addr()
#include <sys/socket.h>
#include <netinet/in.h>

#define PORT 6034
#define BUFFER_SIZE 100

int main() {
    int sockfd, new_sockfd;
    socklen_t length;
    char buf[BUFFER_SIZE], buf1[BUFFER_SIZE];
    struct sockaddr_in server_addr, client_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
    server_addr.sin_port = htons(PORT);

    // Bind socket
    if (bind(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Bind failed");
        close(sockfd);
        exit(1);
    }

    // Listen for incoming connections
    if (listen(sockfd, 5) < 0) {
        perror("Listen failed");
        close(sockfd);
        exit(1);
    }

    printf("Server listening on port %d...\n", PORT);

    length = sizeof(client_addr);
    new_sockfd = accept(sockfd, (struct sockaddr *)&client_addr, &length);
    if (new_sockfd < 0) {
        perror("Accept failed");
        close(sockfd);
        exit(1);
    }

    // Receive message from client
    int k = recv(new_sockfd, buf, BUFFER_SIZE - 1, 0);
    if (k < 0) {
        perror("Receive failed");
        close(new_sockfd);
        close(sockfd);
        exit(1);
    }

    buf[k] = '\0';
    printf("Client says: %s\n", buf);

    // Send response to client
    printf("Enter a message: ");
    fgets(buf1, BUFFER_SIZE, stdin);
    buf1[strcspn(buf1, "\n")] = '\0';  // Remove newline

    if (send(new_sockfd, buf1, strlen(buf1), 0) < 0) {
        perror("Send failed");
    }

    // Close sockets
    close(new_sockfd);
    close(sockfd);

    return 0;
}
