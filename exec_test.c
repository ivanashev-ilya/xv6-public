#include "param.h"
#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "fcntl.h"
#include "syscall.h"
#include "traps.h"
#include "memlayout.h"

#define SIZE 6

int main(void) {
    int fd = open("script.c", O_CREATE | O_RDWR);
    char buf[SIZE + 1] = "#!cat\n";
    write(fd, buf, SIZE);
    close(fd);
    
    char *argv[2] = { "script.c", 0 };
    int pid = fork();
	if (pid == 0) {
		exec("script.c", argv);
        exit();
	}
    wait();
    exit();
}


