/*
 * Copyright 2017 The Android Open Source Project
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef WAVEMAKER2_AUDIOENGINE_H
#define WAVEMAKER2_AUDIOENGINE_H

#include <cstdint>
#include <atomic>
#include <memory>
#include <aaudio/AAudio.h>
#include "SoundRecording.h"
#include "file/FileUtil.h"

#if 1
#ifndef MODULE_NAME
#define MODULE_NAME  "AAUDIO-C"
#endif

#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, MODULE_NAME, __VA_ARGS__)
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR,MODULE_NAME, __VA_ARGS__)
#endif

class AudioEngine {

public:
    void start();
    void stop();
    void restart();
    aaudio_data_callback_result_t recordingCallback(float *audioData, int32_t numFrames);
    aaudio_data_callback_result_t playbackCallback(float *audioData, int32_t numFrames);
    void setRecording(bool isRecording);
    void setPlaying(bool isPlaying);
    void setLooping(bool isOn);

private:
    std::atomic<bool> mIsRecording = {false};
    std::atomic<bool> mIsPlaying = {false};
    SoundRecording mSoundRecording;
    AAudioStream* mPlaybackStream = nullptr;
    AAudioStream* mRecordingStream = nullptr;
    FileUtil file_util;
    int32_t record_fd;
    int32_t player_fd;

    void stopStream(AAudioStream *stream) const;
    void closeStream(AAudioStream **stream) const;
};

#endif //WAVEMAKER2_AUDIOENGINE_H
