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

#ifndef SCXMLSTATEDIALOG_H
#define SCXMLSTATEDIALOG_H

#include "xmlEdit.h"
#include "modules/specialized/scxml/scxmlinfo.h"
#include "modules/specialized/scxml/dialogs/baseddata.h"

namespace Ui {
class SCXMLStateDialog;
}

class Regola;

class SCXMLStateDialog : public QDialog
{
    Q_OBJECT
    const bool _isInsertOrEdit;
    const bool _isInsertOrAppend;
    Element *_selectedElement;
    BaseDData _d;
    Element *_parentElement;
    SCXMLInfo *_info;
    Regola *_regola ;

    void setupInsert();
    void setupEdit();
    void setupCommon();

public:
    explicit SCXMLStateDialog(QWidget *parent, SCXMLInfo *info, Regola *regola, const bool isInsertOrEdit, const bool isInsertOrAppend,
                              Element *toModifyElement, Element *selectedElement, Element *parentElement);
    ~SCXMLStateDialog();

    void accept();

private:
    Ui::SCXMLStateDialog *ui;
};

#endif // SCXMLSTATEDIALOG_H