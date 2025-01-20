#include <windows.h>
#include <mmsystem.h>
#include <stdio.h>
#include <thread>
#include <mutex>
#include <queue>

#pragma comment(lib, "winmm.lib")

class SoundPlayer {
private:
    std::thread playbackThread;
    std::mutex mutex;
    std::queue<bool> playRequests;
    bool isRunning;
    bool isPlaying;
    wchar_t soundFilePath[MAX_PATH];

public:
    SoundPlayer() : isRunning(true), isPlaying(false) {
        soundFilePath[0] = L'\0';
        printf("Initializing SoundPlayer...\n");
        playbackThread = std::thread(&SoundPlayer::playbackLoop, this);
        printf("Playback thread started.\n");
    }

    ~SoundPlayer() {
        printf("Cleaning up SoundPlayer...\n");
        isRunning = false;
        if (playbackThread.joinable()) {
            playbackThread.join();
        }
    }

    bool loadWavFile(const char* filename) {
        printf("Setting sound file: %s\n", filename);

        // Convert char* to wchar_t*
        size_t converted;
        mbstowcs_s(&converted, soundFilePath, MAX_PATH, filename, _TRUNCATE);

        // Test if file exists and is readable
        FILE* fp = nullptr;
        fopen_s(&fp, filename, "rb");
        if (!fp) {
            printf("Failed to open file: %s\n", filename);
            return false;
        }
        fclose(fp);

        // Try to load the sound file
        if (!PlaySoundW(soundFilePath, NULL, SND_FILENAME | SND_ASYNC | SND_NODEFAULT)) {
            printf("Failed to test play sound file. Error code: %d\n", GetLastError());
            return false;
        }

        // Stop the test playback
        PlaySoundW(NULL, NULL, 0);
        //printf("Sound file loaded successfully\n");
        return true;
    }

    void requestPlay() {
        std::lock_guard<std::mutex> lock(mutex);
        if (!isPlaying) {
            //printf("Queuing play request...\n");
            playRequests.push(true);
        }
        else {
            //printf("Sound is already playing...\n");
        }
    }

private:
    void playbackLoop() {
        while (isRunning) {
            bool shouldPlay = false;
            {
                std::lock_guard<std::mutex> lock(mutex);
                if (!playRequests.empty() && !isPlaying) {
                    shouldPlay = true;
                    playRequests.pop();
                }
            }

            if (shouldPlay) {
                playSound();
            }

            Sleep(10);
        }
    }

    void playSound() {
        if (soundFilePath[0] == L'\0') {
            printf("No sound file loaded!\n");
            return;
        }

        {
            std::lock_guard<std::mutex> lock(mutex);
            isPlaying = true;
        }


        // Play the sound with SND_SYNC to know when it's done
        if (!PlaySoundW(soundFilePath, NULL, SND_FILENAME | SND_NOSTOP)) {
            printf("Failed to play sound! Error code: %d\n", GetLastError());
        }
        else {
            printf("Playback completed successfully.\n");
        }

        {
            std::lock_guard<std::mutex> lock(mutex);
            isPlaying = false;
        }
    }
};