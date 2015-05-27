#/**************************************************************************
# *  This file is part of QXmlEdit                                         *
# *  Copyright (C) 2011 by Luca Bellonda and individual contributors       *
# *    as indicated in the AUTHORS file                                    *
# *  lbellonda _at_ gmail.com                                              *
# *                                                                        *
# * This library is free software; you can redistribute it and/or          *
# * modify it under the terms of the GNU Library General Public            *
# * License as published by the Free Software Foundation; either           *
# * version 2 of the License, or (at your option) any later version.       *
# *                                                                        *
# * This library is distributed in the hope that it will be useful,        *
# * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
# * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
# * Library General Public License for more details.                       *
# *                                                                        *
# * You should have received a copy of the GNU Library General Public      *
# * License along with this library; if not, write to the                  *
# * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
# * Boston, MA  02110-1301  USA                                            *
# **************************************************************************/
#-------------------------------------------------
#
# Project created by QtCreator 2012-02-03T22:27:42
#
#-------------------------------------------------

############################ BEGIN INSTALLATION FOLDERS DECLARATION ###########################################
INST_DATA_DIR=$$(QXMLEDIT_INST_DATA_DIR)
isEmpty(INST_DATA_DIR) {
    INST_DATA_DIR = /opt/qxmledit
}

INST_DIR=$$(QXMLEDIT_INST_DIR)
isEmpty(INST_DIR) {
    INST_DIR = /opt/qxmledit
}

INST_DOC_DIR=$$(QXMLEDIT_INST_DOC_DIR)
isEmpty(INST_DOC_DIR) {
    INST_DOC_DIR = /opt/qxmledit
}

INST_LIB_DIR=$$(QXMLEDIT_INST_LIB_DIR)
isEmpty(INST_LIB_DIR) {
    INST_LIB_DIR = /opt/qxmledit
}

INST_TRANSLATIONS_DIR=$$(QXMLEDIT_INST_TRANSLATIONS_DIR)
isEmpty(INST_TRANSLATIONS_DIR) {
    INST_TRANSLATIONS_DIR=$$INST_DATA_DIR/translations
}
############################ END INSTALLATION FOLDERS DECLARATION #############################################

include("../version.pri")

QT       += sql gui

greaterThan(QT_MAJOR_VERSION, 4){
QT       += widgets core
}


TARGET = QXmlEditSessions
os2:TARGET = QXEdtSes
TEMPLATE = lib

greaterThan(QT_MAJOR_VERSION, 4) {
win32 {
    DEFINES += "_NO_W32_PSEUDO_MODIFIERS"
    DEFINES += "NOGDI"
}
}

win32-msvc2010 {

} else {
    QMAKE_CXXFLAGS += -Wall
    QMAKE_CXXFLAGS +=-Werror
}


lessThan(QT_MAJOR_VERSION, 5) {
    QMAKE_CXXFLAGS +=-Wno-unused-local-typedefs
}

#CONFIG += precompile_header
PRECOMPILED_HEADER  = precompiled_lib.h

DEFINES += QXMLEDITSESSIONS_LIBRARY

INCLUDEPATH += $$PWD/include
INCLUDEPATH += ./include
INCLUDEPATH += .
INCLUDEPATH += sessions/include
INCLUDEPATH += ../globals/includes
INCLUDEPATH += ../framework/include

SOURCES += sessionmanager.cpp \
           sessionmanagerprivate.cpp \
           session.cpp \
           sessionprivate.cpp \
           sessionfiltermodel.cpp \
           sessionstatewidget.cpp \
           sessionstatewidgetprivate.cpp \
           sessions.cpp \
           sessiondetaildialog.cpp \
           sessionsmanagementdialog.cpp \
           sessiondrawerwidget.cpp \
           sessiondrawerwidgetprivate.cpp \
    sessiondatamodel.cpp \
    sessionsummary.cpp \
    sessionsummarydata.cpp \
    data_access/testdataaccess.cpp \
    sessionoperationstatus.cpp \
    data_access/sqllitedataaccess.cpp \
    data_access/model/filemodel.cpp \
    data_access/model/SessionModel.cpp \
    data_access/model/accessmodel.cpp \
    data_access/model/sessionlistmodel.cpp \
    widgets/sessiondetailwidget.cpp \
    models.cpp \
    sessionrequester.cpp \
    modelutility.cpp \
    data_access/dataresult.cpp \
    data_access/sqlliteprivatespec.cpp \
    data_access/model/attrfilterprofile.cpp \
    data_access/model/attrfilterdetail.cpp \
    data_access/model/genericpersistentdbdata.cpp \
    data_access/sqllitegenericdata.cpp \
    sessionprivatedefault.cpp

HEADERS +=  precompiled_lib.h \
    sessions.h \
        QXmlEditSessions_global.h \
    sessionmanager.h \
    sessionmanagerprivate.h \
    sessionstatewidget.h \
    session.h \
    sessionsmanagementdialog.h \
    sessiondrawerwidget.h \
    sessiondetaildialog.h \
    sessiondrawerwidgetprivate.h \
    sessionstatewidgetprivate.h \
    sessionprivate.h \
    sessiondatamodel.h \
    sessionsummary.h \
    sessionsummarydata.h \
    SessionDataInterface.h \
    data_access/testdataaccess.h \
    sessionoperationstatus.h \
    data_access/sqllitedataaccess.h \
    data_access/sqllitedataaccessprivate.h \
    data_access/model/filemodel.h \
    data_access/model/sessionlistmodel.h \
    widgets/sessiondetailwidget.h \
    models.h \
    sessionrequester.h \
    sessionfiltermodel.h \
    modelutility.h \
    data_access/dataresult.h \
    data_access/model/attrfilterprofile.h \
    data_access/model/attrfilterdetail.h \
    data_access/model/genericpersistentdbdata.h \
    sessionprivatedefault.h \
    ../framework/include/Notifier.h \
    precompiled_lib.h


FORMS += \
    widgets/sessionstatewidget.ui \
    widgets/sessiondetaildialog.ui \
    widgets/sessiondrawerwidget.ui \
    widgets/sessionsmanagementdialog.ui \
    widgets/sessiondetailwidget.ui

DESTDIR = ../../build
UI_DIR = ../../build/sessions/ui
MOC_DIR = ../../build/sessions/moc
OBJECTS_DIR = ../../build/sessions/obj
RCC_DIR = ../../build/sessions/rcc

TRANSLATIONS = \
   languages/QXmlEditSessions_cs.ts
TRANSL = \
   languages/QXmlEditSessions_cs.qm

translationsfiles.path = $$INST_TRANSLATIONS_DIR
translationsfiles.files = $$TRANSL



symbian {
    MMP_RULES += EXPORTUNFROZEN
    TARGET.UID3 = 0xE39EB967
    TARGET.CAPABILITY = 
    TARGET.EPOCALLOWDLLDATA = 1
    addFiles.sources = QXmlEditSessions.dll
    addFiles.path = !:/sys/bin
    DEPLOYMENT += addFiles
}

unix:!symbian {
    maemo5 {
        target.path = /opt/usr/lib
    } else {
        target.path = $$INST_LIB_DIR
    }
    INSTALLS += target translationsfiles
}

RESOURCES += sessions.qrc

# resources are defined in paths.h
unix:!macx:DEFINES += UNIX_RESOURCES

DEFINES += UNIX_RESOURCE_PATH=$$INST_DATA_DIR
DEFINES += UNIX_DOC_PATH=$$INST_DOC_DIR
