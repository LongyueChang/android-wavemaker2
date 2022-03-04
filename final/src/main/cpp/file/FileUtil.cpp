//
// Created by YUNXI on 2022/3/3.
//

#include "FileUtil.h"



int FileUtil::openFile(string fileName) {
    const char *fileChar = fileName.c_str();
    int fd = open(fileChar, O_RDWR|O_CREAT|O_APPEND, S_IRWXO);
    if (fd == -1)
        return -1;

    return fd;
}

jbyte FileUtil::readFile(int fd, jbyte *buf_byte, int len) {
    unsigned char *buf_char=(unsigned char*)buf_byte;
    int readCode=read(fd, buf_char, len);
    return readCode;
}

int FileUtil::writeFile(int fd, AAudioStream* recordingStream_, int len) {
//    unsigned char *buf_char=(unsigned char*)buf_byte;
    int writeCode = write(fd, recordingStream_, len);
    return writeCode;
}


int FileUtil::closeFile(int fd) {
    return close(fd);
}

int FileUtil::deleteFile(string filename) {
    const char *fileChar = filename.c_str();
    int rmvFd = remove(fileChar);
    return rmvFd;
}



