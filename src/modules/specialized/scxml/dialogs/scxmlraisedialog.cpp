/**************************************************************************
 *  This file is part of QXmlEdit                                         *
 *  Copyright (C) 2016-2018 by Luca Bellonda and individual contributors  *
 *    as indicated in the AUTHORS file                                    *
 *  lbellonda _at_ gmail.com                                              *
 *                                                                        *
 * This library is free software; you can redistribute it and/or          *
 * modify it under the terms of the GNU Library General Public            *
 * License as published by the Free Software Foundation; either           *
 * version 2 of the License, or (at your option) any later version.       *
 *                                                                        *
 * This library is distributed in the hope that it will be useful,        *
 * but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU      *
 * Library General Public License for more details.                       *
 *                                                                        *
 * You should have received a copy of the GNU Library General Public      *
 * License along with this library; if not, write to the                  *
 * Free Software Foundation, Inc., 51 Franklin Street, Fifth Floor,       *
 * Boston, MA  02110-1301  USA                                            *
 **************************************************************************/

#include "scxmlraisedialog.h"
#include "ui_scxmlraisedialog.h"

#include "regola.h"
#include "modules/specialized/scxml/scxmltoken.h"
#include "modules/xsd/namespacemanager.h"
#include "utils.h"

SCXMLRaiseDialog::SCXMLRaiseDialog(QWidget *parent, SCXMLInfo *info, Regola *regola, const bool isInsertOrEdit, const bool isInsertOrAppend,
                                   Element *toModifyElement, Element *selectedElement, Element *parentElement) :
    QDialog(parent),
    p(info, regola, isInsertOrEdit, isInsertOrAppend, toModifyElement, selectedElement, parentElement),
    d(&p._d),
    ui(new Ui::SCXMLRaiseDialog)
{
    ui->setupUi(this);
    setupCommon();
    if(p._isInsertOrEdit) {
        setupInsert();
    }
    setupEdit();
}

SCXMLRaiseDialog::~SCXMLRaiseDialog()
{
    delete ui;
}

void SCXMLRaiseDialog::setupCommon()
{
}

// use default values
void SCXMLRaiseDialog::setupInsert()
{
    p.assignTag(SCXMLToken::Tag_raise);
}

void SCXMLRaiseDialog::setupEdit()
{
    ui->event->setText(d->attributeString(SCXMLraiseToken::A_event));
}

void SCXMLRaiseDialog::accept()
{
    d->setAttributeString(SCXMLraiseToken::A_event, ui->event->text());

    if(!d->checkNMTOKEN(this, SCXMLraiseToken::A_event, true)) {
        return ;
    }
    QDialog::accept();
}
