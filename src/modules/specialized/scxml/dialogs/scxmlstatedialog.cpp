/**************************************************************************
 *  This file is part of QXmlEdit                                         *
 *  Copyright (C) 2016 by Luca Bellonda and individual contributors       *
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

#include "scxmlstatedialog.h"
#include "ui_scxmlstatedialog.h"
#include "regola.h"
#include "modules/specialized/scxml/scxmltoken.h"
#include "modules/xsd/namespacemanager.h"
#include "utils.h"

SCXMLStateDialog::SCXMLStateDialog(QWidget *parent, SCXMLInfo *info, Regola *regola, const bool isInsertOrEdit, const bool isInsertOrAppend,
                                   Element *toModifyElement, Element *selectedElement, Element *parentElement) :
    QDialog(parent),
    _isInsertOrEdit(isInsertOrEdit),
    _isInsertOrAppend(isInsertOrAppend),
    _d(toModifyElement),
    ui(new Ui::SCXMLStateDialog)
{
    Utils::TODO_THIS_RELEASE("icona");
    _regola = regola;
    _info = info ;
    _selectedElement = selectedElement;
    _parentElement = parentElement;
    ui->setupUi(this);
    setupCommon();
    if(_isInsertOrEdit) {
        setupInsert();
    }
    setupEdit();
}

SCXMLStateDialog::~SCXMLStateDialog()
{
    delete ui;
}

void SCXMLStateDialog::setupCommon()
{
    Utils::TODO_THIS_RELEASE("fare");
    Utils::loadComboTextArrays(ui->initial, "", _info->allStates(), _info->allStates());
}

// use default values
void SCXMLStateDialog::setupInsert()
{
    _d.assignTag(SCXMLToken::Tag_state, _regola, _parentElement);
}

void SCXMLStateDialog::setupEdit()
{
    ui->id->setText(_d.attributeString(SCXMLstateToken::A_id));
    ui->initial->setEditText(_d.attributeString(SCXMLstateToken::A_initial));
}

void SCXMLStateDialog::accept()
{
    Utils::TODO_THIS_RELEASE("fare validazioni");
    Utils::TODO_THIS_RELEASE("set dati in elemento");
    Utils::TODO_THIS_RELEASE("aggiungi attributi obbligatori");

    _d.setAttributeString(SCXMLstateToken::A_id, ui->id->text());
    _d.setAttributeString(SCXMLstateToken::A_initial, ui->initial->currentText());

    if(     !_d.checkIDREFS(this, SCXMLstateToken::A_initial)
        ||  !_d.checkID(this, SCXMLstateToken::A_id) ) {
        return;
    }
    QDialog::accept();
}