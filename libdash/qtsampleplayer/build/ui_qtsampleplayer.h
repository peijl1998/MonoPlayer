/********************************************************************************
** Form generated from reading UI file 'qtsampleplayer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTSAMPLEPLAYER_H
#define UI_QTSAMPLEPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Renderer/QTGLRenderer.h"

QT_BEGIN_NAMESPACE

class Ui_QtSamplePlayerClass
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_3;
    QComboBox *cb_mpd;
    QLineEdit *lineEdit_mpd;
    sampleplayer::renderer::QTGLRenderer *videoelement;
    QVBoxLayout *videoLayout;
    QWidget *w_controls;
    QVBoxLayout *verticalLayout;
    QWidget *w_boxes;
    QVBoxLayout *verticalLayout_2;
    QPushButton *button_mpd;
    QPushButton *button_start;
    QPushButton *button_stop;
    QLabel *label_period;
    QComboBox *cb_period;
    QLabel *label;
    QComboBox *cb_video_adaptationset;
    QLabel *label_2;
    QComboBox *cb_video_representation;
    QLabel *label_audio_adaptationset;
    QComboBox *cb_audio_adaptationset;
    QLabel *label_audio_representation;
    QComboBox *cb_audio_representation;
    QLabel *label_5;
    QProgressBar *progressBar_V;
    QLabel *label_6;
    QProgressBar *progressBar_VF;
    QLabel *label_7;
    QProgressBar *progressBar_A;
    QLabel *label_8;
    QProgressBar *progressBar_AC;
    QSpacerItem *verticalSpacer;
    QLabel *bitmovinLogo;
    QLabel *libdashLogo;
    QSpacerItem *verticalSpacer_2;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtSamplePlayerClass)
    {
        if (QtSamplePlayerClass->objectName().isEmpty())
            QtSamplePlayerClass->setObjectName(QStringLiteral("QtSamplePlayerClass"));
        QtSamplePlayerClass->setEnabled(true);
        QtSamplePlayerClass->resize(1020, 685);
        centralWidget = new QWidget(QtSamplePlayerClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setEnabled(true);
        widget->setMinimumSize(QSize(600, 0));
        verticalLayout_3 = new QVBoxLayout(widget);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        cb_mpd = new QComboBox(widget);
        cb_mpd->setObjectName(QStringLiteral("cb_mpd"));

        verticalLayout_3->addWidget(cb_mpd);

        lineEdit_mpd = new QLineEdit(widget);
        lineEdit_mpd->setObjectName(QStringLiteral("lineEdit_mpd"));

        verticalLayout_3->addWidget(lineEdit_mpd);

        videoelement = new sampleplayer::renderer::QTGLRenderer(widget);
        videoelement->setObjectName(QStringLiteral("videoelement"));
        videoelement->setEnabled(true);
        videoelement->setMinimumSize(QSize(100, 100));
        videoLayout = new QVBoxLayout(videoelement);
        videoLayout->setSpacing(6);
        videoLayout->setContentsMargins(11, 11, 11, 11);
        videoLayout->setObjectName(QStringLiteral("videoLayout"));

        verticalLayout_3->addWidget(videoelement);


        horizontalLayout->addWidget(widget);

        w_controls = new QWidget(centralWidget);
        w_controls->setObjectName(QStringLiteral("w_controls"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(w_controls->sizePolicy().hasHeightForWidth());
        w_controls->setSizePolicy(sizePolicy);
        verticalLayout = new QVBoxLayout(w_controls);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(-1, 0, -1, -1);
        w_boxes = new QWidget(w_controls);
        w_boxes->setObjectName(QStringLiteral("w_boxes"));
        w_boxes->setMinimumSize(QSize(200, 0));
        w_boxes->setMaximumSize(QSize(200, 800));
        verticalLayout_2 = new QVBoxLayout(w_boxes);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(-1, 0, -1, -1);
        button_mpd = new QPushButton(w_boxes);
        button_mpd->setObjectName(QStringLiteral("button_mpd"));

        verticalLayout_2->addWidget(button_mpd);

        button_start = new QPushButton(w_boxes);
        button_start->setObjectName(QStringLiteral("button_start"));

        verticalLayout_2->addWidget(button_start);

        button_stop = new QPushButton(w_boxes);
        button_stop->setObjectName(QStringLiteral("button_stop"));

        verticalLayout_2->addWidget(button_stop);

        label_period = new QLabel(w_boxes);
        label_period->setObjectName(QStringLiteral("label_period"));

        verticalLayout_2->addWidget(label_period);

        cb_period = new QComboBox(w_boxes);
        cb_period->setObjectName(QStringLiteral("cb_period"));

        verticalLayout_2->addWidget(cb_period);

        label = new QLabel(w_boxes);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label);

        cb_video_adaptationset = new QComboBox(w_boxes);
        cb_video_adaptationset->setObjectName(QStringLiteral("cb_video_adaptationset"));

        verticalLayout_2->addWidget(cb_video_adaptationset);

        label_2 = new QLabel(w_boxes);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2);

        cb_video_representation = new QComboBox(w_boxes);
        cb_video_representation->setObjectName(QStringLiteral("cb_video_representation"));
        cb_video_representation->setMinimumSize(QSize(0, 0));

        verticalLayout_2->addWidget(cb_video_representation);

        label_audio_adaptationset = new QLabel(w_boxes);
        label_audio_adaptationset->setObjectName(QStringLiteral("label_audio_adaptationset"));

        verticalLayout_2->addWidget(label_audio_adaptationset);

        cb_audio_adaptationset = new QComboBox(w_boxes);
        cb_audio_adaptationset->setObjectName(QStringLiteral("cb_audio_adaptationset"));

        verticalLayout_2->addWidget(cb_audio_adaptationset);

        label_audio_representation = new QLabel(w_boxes);
        label_audio_representation->setObjectName(QStringLiteral("label_audio_representation"));

        verticalLayout_2->addWidget(label_audio_representation);

        cb_audio_representation = new QComboBox(w_boxes);
        cb_audio_representation->setObjectName(QStringLiteral("cb_audio_representation"));

        verticalLayout_2->addWidget(cb_audio_representation);

        label_5 = new QLabel(w_boxes);
        label_5->setObjectName(QStringLiteral("label_5"));

        verticalLayout_2->addWidget(label_5);

        progressBar_V = new QProgressBar(w_boxes);
        progressBar_V->setObjectName(QStringLiteral("progressBar_V"));
        progressBar_V->setValue(24);

        verticalLayout_2->addWidget(progressBar_V);

        label_6 = new QLabel(w_boxes);
        label_6->setObjectName(QStringLiteral("label_6"));

        verticalLayout_2->addWidget(label_6);

        progressBar_VF = new QProgressBar(w_boxes);
        progressBar_VF->setObjectName(QStringLiteral("progressBar_VF"));
        progressBar_VF->setValue(24);

        verticalLayout_2->addWidget(progressBar_VF);

        label_7 = new QLabel(w_boxes);
        label_7->setObjectName(QStringLiteral("label_7"));

        verticalLayout_2->addWidget(label_7);

        progressBar_A = new QProgressBar(w_boxes);
        progressBar_A->setObjectName(QStringLiteral("progressBar_A"));
        progressBar_A->setValue(24);

        verticalLayout_2->addWidget(progressBar_A);

        label_8 = new QLabel(w_boxes);
        label_8->setObjectName(QStringLiteral("label_8"));

        verticalLayout_2->addWidget(label_8);

        progressBar_AC = new QProgressBar(w_boxes);
        progressBar_AC->setObjectName(QStringLiteral("progressBar_AC"));
        progressBar_AC->setValue(24);

        verticalLayout_2->addWidget(progressBar_AC);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        bitmovinLogo = new QLabel(w_boxes);
        bitmovinLogo->setObjectName(QStringLiteral("bitmovinLogo"));
        bitmovinLogo->setMaximumSize(QSize(182, 49));
        bitmovinLogo->setPixmap(QPixmap(QString::fromUtf8("../bin/bitmovin.png")));
        bitmovinLogo->setScaledContents(true);

        verticalLayout_2->addWidget(bitmovinLogo);

        libdashLogo = new QLabel(w_boxes);
        libdashLogo->setObjectName(QStringLiteral("libdashLogo"));
        libdashLogo->setMaximumSize(QSize(182, 62));
        libdashLogo->setPixmap(QPixmap(QString::fromUtf8("../bin/libdash.png")));
        libdashLogo->setScaledContents(true);

        verticalLayout_2->addWidget(libdashLogo);


        verticalLayout->addWidget(w_boxes);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);


        horizontalLayout->addWidget(w_controls);

        QtSamplePlayerClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtSamplePlayerClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtSamplePlayerClass->setStatusBar(statusBar);

        retranslateUi(QtSamplePlayerClass);

        QMetaObject::connectSlotsByName(QtSamplePlayerClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtSamplePlayerClass)
    {
        QtSamplePlayerClass->setWindowTitle(QApplication::translate("QtSamplePlayerClass", "libdash player", Q_NULLPTR));
        cb_mpd->clear();
        cb_mpd->insertItems(0, QStringList()
         << QApplication::translate("QtSamplePlayerClass", "http://dash.akamaized.net/akamai/bbb_30fps/bbb_30fps.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_2_resolutions.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://www-itec.aau.at/~cmueller/libdashtest/showcases/redbull_segment_template.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/1a/netflix/exMPD_BIP_TC1.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/1a/sony/SNE_DASH_SD_CASE1A_REVISED.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/1b/envivio/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/1b/thomson-networks/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/1c/envivio/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/2a/envivio/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/2a/sony/SNE_DASH_CASE_2A_SD_REVISED.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/2a/thomson-networks/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/3a/fraunhofer/ed.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/3b/fraunhofer/elephants_dream_heaac2_0.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/3b/sony/SNE_DASH_CASE3B_SD_REVISED.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/4b/sony/SNE_DASH_CASE4B_SD_REVISED.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/5a/1/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/5b/1/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/6c/envivio/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://dash.edgesuite.net/dash264/TestCases/6c/envivio/manifest2.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://tvnlive.dashdemo.edgesuite.net/live/manifest.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-full-gdr/mp4-full-gdr-mpd-AV-BS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-full-gdr/mp4-full-gdr-mpd-AV-NBS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-live-periods/mp4-live-periods-mpd.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-live/mp4-live-mpd-AV-BS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-live/mp4-live-mpd-AV-NBS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-main-multi/mp4-main-multi-mpd-AV-NBS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-main-ogop/mp4-main-ogop-mpd-AV-BS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-main-ogop/mp4-main-ogop-mpd-AV-NBS.mpd", Q_NULLPTR)
         << QApplication::translate("QtSamplePlayerClass", "http://ftp-itec.uni-klu.ac.at/dash/conformance/mp4-onDemand/mp4-onDemand-mpd-AV.mpd", Q_NULLPTR)
        );
        lineEdit_mpd->setText(QApplication::translate("QtSamplePlayerClass", "http://dash.akamaized.net/akamai/bbb_30fps/bbb_30fps.mpd", Q_NULLPTR));
        button_mpd->setText(QApplication::translate("QtSamplePlayerClass", "Download MPD", Q_NULLPTR));
        button_start->setText(QApplication::translate("QtSamplePlayerClass", "Start", Q_NULLPTR));
        button_stop->setText(QApplication::translate("QtSamplePlayerClass", "Stop", Q_NULLPTR));
        label_period->setText(QApplication::translate("QtSamplePlayerClass", "Period", Q_NULLPTR));
        label->setText(QApplication::translate("QtSamplePlayerClass", "Video AdaptationSet", Q_NULLPTR));
        label_2->setText(QApplication::translate("QtSamplePlayerClass", "Video Representation", Q_NULLPTR));
        label_audio_adaptationset->setText(QApplication::translate("QtSamplePlayerClass", "Audio AdaptationSet", Q_NULLPTR));
        label_audio_representation->setText(QApplication::translate("QtSamplePlayerClass", "Audio Representation", Q_NULLPTR));
        label_5->setText(QApplication::translate("QtSamplePlayerClass", "Video Segment Buffer", Q_NULLPTR));
        label_6->setText(QApplication::translate("QtSamplePlayerClass", "Video Frame Buffer", Q_NULLPTR));
        label_7->setText(QApplication::translate("QtSamplePlayerClass", "Audio Segment Buffer", Q_NULLPTR));
        label_8->setText(QApplication::translate("QtSamplePlayerClass", "Audio Chunk Buffer", Q_NULLPTR));
        bitmovinLogo->setText(QString());
        libdashLogo->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class QtSamplePlayerClass: public Ui_QtSamplePlayerClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTSAMPLEPLAYER_H
