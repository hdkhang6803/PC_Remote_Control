#include <QCoreApplication>
#include <QAudioDevice>
#include <QAudioInput>
#include <QAudioOutput>
#include <QBuffer>
#include <QDebug>
#include <QMediaFormat>
#include <QMediaRecorder>
#include <QMediaPlayer>
#include <QMediaCaptureSession>

int main(int argc, char *argv[])
{
    QMediaCaptureSession* session = new QMediaCaptureSession();
    QAudioInput* audioInput = new QAudioInput();
    QMediaRecorder* recorder = new QMediaRecorder();
    session->setAudioInput(audioInput);
    session->setRecorder(recorder);
    recorder->setMediaFormat(QMediaFormat::Wave);
    recorder->setOutputLocation(QUrl::fromLocalFile("record.wav"));
    recorder->setAudioSampleRate(48000);
    recorder->setAudioChannelCount(1);
    recorder->record();

    qDebug() << "Recording. Press Enter to stop";
    QTextStream stream(stdin);
    stream.readLine();

    // Stop recording
    recorder->stop();

}
