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

static QList<qreal> getBufferLevels(const QAudioBuffer &buffer);

AudioRecorder::AudioRecorder() : ui(new Ui::AudioRecorder)
{
    ui->setupUi(this);
    m_audioRecorder = new QMediaRecorder(this);
    m_captureSession.setRecorder(m_audioRecorder);
    m_captureSession.setAudioInput(new QAudioInput(this));
}

void AudioRecorder::updateProgress(qint64 duration)
{
    if (m_audioRecorder->error() != QMediaRecorder::NoError || duration < 2000)
        return;

    ui->statusbar->showMessage(tr("Recorded %1 sec").arg(duration / 1000));
}

void AudioRecorder::onStateChanged(QMediaRecorder::RecorderState state)
{
    QString statusMessage;

    switch (state) {
    case QMediaRecorder::RecordingState:
        statusMessage = tr("Recording to %1").arg(m_audioRecorder->actualLocation().toString());
        ui->recordButton->setText(tr("Stop"));
        ui->pauseButton->setText(tr("Pause"));
        break;
    case QMediaRecorder::PausedState:
        statusMessage = tr("Paused");
        ui->recordButton->setText(tr("Stop"));
        ui->pauseButton->setText(tr("Resume"));
        break;
    case QMediaRecorder::StoppedState:
        statusMessage = tr("Stopped");
        ui->recordButton->setText(tr("Record"));
        ui->pauseButton->setText(tr("Pause"));
        break;
    }

    ui->pauseButton->setEnabled(m_audioRecorder->recorderState() != QMediaRecorder::StoppedState);
    if (m_audioRecorder->error() == QMediaRecorder::NoError)
        ui->statusbar->showMessage(statusMessage);
}


void AudioRecorder::toggleRecord()
{
    if (m_audioRecorder->recorderState() == QMediaRecorder::StoppedState) {

        qDebug() << "record press";
    } else {
        qDebug() << "stop press";
    }
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
    qDebug() << "I ran";
    m_captureSession.audioInput()->setDevice(dev);

    m_audioRecorder->setMediaFormat(selectedMediaFormat());
    m_audioRecorder->setAudioSampleRate(44100);
    m_audioRecorder->setAudioBitRate(64000);
    m_audioRecorder->setAudioChannelCount(1);
    m_audioRecorder->setQuality(QMediaRecorder::Quality(QImageCapture::NormalQuality));
    m_audioRecorder->setEncodingMode(QMediaRecorder::ConstantBitRateEncoding);

    // Set the output location for the recorded audio
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
    QString fileName = "D:\\University\\Year_2\\HK2\\MMT\\Project_3\\recorded_data.m4a";
    m_audioRecorder->setOutputLocation(QUrl::fromLocalFile(fileName));
    m_outputLocationSet = true;
    qDebug() << "The output path is set";
}

void AudioRecorder::togglePause()
{
    if (m_audioRecorder->recorderState() != QMediaRecorder::PausedState){
        m_audioRecorder->pause();
        qDebug() << "tggle pause: pause";
    }
    else{
        m_audioRecorder->record();
        qDebug() << "toggle pause: record";
    }
}

void AudioRecorder::displayErrorMessage()
{
    ui->statusbar->showMessage(m_audioRecorder->errorString());
}

QMediaFormat AudioRecorder::selectedMediaFormat() const
{
    QMediaFormat format;
    format.setFileFormat(QMediaFormat::MP3);
    format.setAudioCodec(QMediaFormat::AudioCodec::MP3);
    return format;
}


// returns the audio level for each channel
QList<qreal> getBufferLevels(const QAudioBuffer &buffer)
{
//    QList<qreal> values;

//    auto format = buffer.format();
//    if (!format.isValid())
//        return values;

//    int channels = buffer.format().channelCount();
//    values.fill(0, channels);

//    int bytesPerSample = format.bytesPerSample();
//    QList<qreal> max_values;
//    max_values.fill(0, channels);

//    const char *data = buffer.constData<char>();
//    for (int i = 0; i < buffer.frameCount(); ++i) {
//        for (int j = 0; j < channels; ++j) {
//            qreal value = qAbs(format.normalizedSampleValue(data));
//            if (value > max_values.at(j))
//                max_values[j] = value;
//            data += bytesPerSample;
//        }
//    }

//    return max_values;
}


#include "moc_audiorecorder.cpp"


