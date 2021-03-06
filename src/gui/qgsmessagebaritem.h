/***************************************************************************
                          qgsmessagebaritem.h  -  description
                             -------------------
    begin                : August 2013
    copyright            : (C) 2013 by Denis Rouzaud
    email                : denis.rouzaud@gmail.com
 ***************************************************************************/

/***************************************************************************
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/
#ifndef qgsmessagebaritem_H
#define qgsmessagebaritem_H

#include <qgsmessagebaritem.h>
#include "qgis.h"
#include <qgsmessagebar.h>

#include <QWidget>
#include <QIcon>
#include <QTextEdit>
#include <QHBoxLayout>
#include "qgis_gui.h"

/** \ingroup gui
 * \class QgsMessageBarItem
 */
class GUI_EXPORT QgsMessageBarItem : public QWidget
{
    Q_OBJECT
  public:
    //! make out a widget containing a message to be displayed on the bar
    QgsMessageBarItem( const QString &text, QgsMessageBar::MessageLevel level = QgsMessageBar::INFO, int duration = 0, QWidget *parent SIP_TRANSFERTHIS = 0 );

    //! make out a widget containing title and message to be displayed on the bar
    QgsMessageBarItem( const QString &title, const QString &text, QgsMessageBar::MessageLevel level = QgsMessageBar::INFO, int duration = 0, QWidget *parent SIP_TRANSFERTHIS = 0 );

    //! make out a widget containing title, message and widget to be displayed on the bar
    QgsMessageBarItem( const QString &title, const QString &text, QWidget *widget, QgsMessageBar::MessageLevel level = QgsMessageBar::INFO, int duration = 0, QWidget *parent SIP_TRANSFERTHIS = 0 );

    //! make out a widget containing a widget to be displayed on the bar
    QgsMessageBarItem( QWidget *widget, QgsMessageBar::MessageLevel level = QgsMessageBar::INFO, int duration = 0, QWidget *parent SIP_TRANSFERTHIS = 0 );

    QgsMessageBarItem *setText( const QString &text );

    QgsMessageBarItem *setTitle( const QString &title );

    QgsMessageBarItem *setLevel( QgsMessageBar::MessageLevel level );

    QgsMessageBarItem *setWidget( QWidget *widget );

    QgsMessageBarItem *setIcon( const QIcon &icon );

    QgsMessageBarItem *setDuration( int duration );

    //! returns the duration in second of the message
    int duration() const { return mDuration; }

    //! returns the level
    QgsMessageBar::MessageLevel level() { return mLevel; }

    //! returns the styleSheet
    QString getStyleSheet() { return mStyleSheet; }

  signals:
    //! emitted when the message level has changed
    void styleChanged( const QString &styleSheet );


  private:
    void writeContent();

    QString mTitle;
    QString mText;
    QgsMessageBar::MessageLevel mLevel;
    int mDuration;
    QWidget *mWidget = nullptr;
    QIcon mUserIcon;
    QHBoxLayout *mLayout = nullptr;
    QLabel *mLblIcon = nullptr;
    QString mStyleSheet;
    QTextEdit *mTextEdit = nullptr;
};

#endif // qgsmessagebaritem_H
