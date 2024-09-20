#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/select.h>
#include <errno.h>
#include <string.h>

int main() {
    const char *fifo_path = "myfifo2";
    int fd;
    fd_set readfds;
    struct timeval timeout;
    char buffer[100];

    mkfifo(fifo_path, 0666);
    fd = open(fifo_path, O_RDONLY | O_NONBLOCK);
    if (fd == -1) {
        perror("Error opening FIFO");
        return 1;
    }

    FD_ZERO(&readfds);
    FD_SET(fd, &readfds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    int retval = select(fd + 1, &readfds, NULL, NULL, &timeout);

    if (retval == -1) {
        perror("select() failed");
        close(fd);
        return 1;
    } else if (retval == 0) {
        printf("No data within 10 seconds.\n");
    } else {
        if (FD_ISSET(fd, &readfds)) {
            ssize_t bytes_read = read(fd, buffer, sizeof(buffer) - 1);
            if (bytes_read >= 0) {
                buffer[bytes_read] = '\0';
                printf("Received: %s\n", buffer);
            } else {
                perror("Error reading from FIFO");
            }
        }
    }

    close(fd);
    return 0;
}
