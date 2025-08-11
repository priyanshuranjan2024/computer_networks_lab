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
    int sockfd;
    char buf[BUFFER_SIZE], buf1[BUFFER_SIZE];
    struct sockaddr_in server_addr;

    // Create socket
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    if (sockfd < 0) {
        perror("Socket creation failed");
        exit(1);
    }

    // Set server address
    server_addr.sin_family = AF_INET;
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Loopback address
    server_addr.sin_port = htons(PORT);

    // Connect to the server
    if (connect(sockfd, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
        perror("Connection failed");
        close(sockfd);
        exit(1);
    }

    // Send message to server
    printf("Enter a message: ");
    fgets(buf, BUFFER_SIZE, stdin);
    buf[strcspn(buf, "\n")] = '\0';  // Remove newline

    if (send(sockfd, buf, strlen(buf), 0) < 0) {
        perror("Send failed");
        close(sockfd);
        exit(1);
    }

    // Receive response from server
    int k = recv(sockfd, buf1, BUFFER_SIZE - 1, 0);
    if (k < 0) {
        perror("Receive failed");
        close(sockfd);
        exit(1);
    }

    buf1[k] = '\0';
    printf("Server says: %s\n", buf1);

    // Close socket
    close(sockfd);

    return 0;
}
