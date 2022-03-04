//
// Created by YUNXI on 2022/3/3.
//

#ifndef AAUDIO_FILEUTIL_H
#define AAUDIO_FILEUTIL_H

#include <jni.h>
#include "string"
#include "cstring"
#include "aaudio/AAudio.h"
#include <array>
#include <unistd.h>
//#include <sys/stat.h>
//#include <sys/time.h>
//#include <stdlib.h>
#include <fcntl.h>


using namespace std;

class FileUtil {
public:
    int openFile(string filename);
    jbyte readFile(int fd,jbyte* buf_byte,int len);
    int writeFile(int fd,AAudioStream* recordingStream_,int len);
    int deleteFile(string filename);

    int closeFile(int fd);
};


#endif //AAUDIO_FILEUTIL_H
