// Copyright (C) 2017 The Qt Company Ltd.
// SPDX-License-Identifier: LicenseRef-Qt-Commercial OR BSD-3-Clause

#include "audiorecorder.h"
#include "ui_audiorecorder.h"

#include <QAudioBuffer>
#include <QAudioDevice>
#include <QAudioInput>
#include <QDir>
#include <QFileDialog>
#include <QImageCapture>
#include <QMediaDevices>
#include <QMediaFormat>
#include <QMediaRecorder>
#include <QMimeType>
#include <QStandardPaths>
#include <QBuffer>

static QList<qreal> getBufferLevels(const QAudioBuffer &buffer);

AudioRecorder::AudioRecorder() : ui(new Ui::AudioRecorder)
{
    ui->setupUi(this);
    m_audioRecorder = new QMediaRecorder(this);
    m_captureSession.setRecorder(m_audioRecorder);
    m_captureSession.setAudioInput(new QAudioInput(this));
}


void delay()
{
    QTime dieTime= QTime::currentTime().addSecs(3);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

void AudioRecorder::auto_start(){
//    if(m_audioRecorder->recorderState() == QMediaRecorder::RecordingState){
//        qDebug() << "The recorder is already start!\n";
//        return;
//    }
    QAudioDevice dev;
    for (auto device : QMediaDevices::audioInputs()){
        qDebug() << device.description();
        dev = device;
    }
    if (dev.isNull()){
        qDebug() << "No audio input device";
        return;
    }

    m_captureSession.audioInput()->setDevice(dev);

    m_audioRecorder->setMediaFormat(selectedMediaFormat());
    m_audioRecorder->setAudioSampleRate(44100);
    m_audioRecorder->setAudioBitRate(64000);
    m_audioRecorder->setAudioChannelCount(1);
    m_audioRecorder->setQuality(QMediaRecorder::Quality(QImageCapture::NormalQuality));
    m_audioRecorder->setEncodingMode(QMediaRecorder::ConstantBitRateEncoding);

//    // Set the output location for the recorded audio
    QString fileName = "D:\\University\\Year_2\\HK2\\MMT\\Project_3\\recorded_data.m4a"; // Provide the desired file name and extension
    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));

    m_audioRecorder->record();
    qDebug() << "The server is recording";


}
void AudioRecorder::stop_by_msg(){
    m_audioRecorder->stop();
    qDebug() << "stopped by msg";
}
void AudioRecorder::setOutputLocation()
{
//    QString fileName = "D:\\University\\Year_2\\HK2\\MMT\\Project_3\\recorded_data.m4a";
//    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));
//    m_outputLocationSet = true;
//    qDebug() << "The output path is set";
}


QMediaFormat AudioRecorder::selectedMediaFormat() const
{
    QMediaFormat format;
    format.setFileFormat(QMediaFormat::MP3);
    format.setAudioCodec(QMediaFormat::AudioCodec::MP3);
    return format;
}


#include "moc_audiorecorder.cpp"


