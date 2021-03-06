/************************************************************************
 * This file has been generated automatically from                      *
 *                                                                      *
 * src/gui/qgsscalevisibilitydialog.h                                   *
 *                                                                      *
 * Do not edit manually ! Edit header and run scripts/sipify.pl again   *
 ************************************************************************/




class QgsScaleVisibilityDialog : QDialog
{
%Docstring
 A dialog allowing users to enter a scale visibility range.
%End

%TypeHeaderCode
#include "qgsscalevisibilitydialog.h"
%End
  public:

    explicit QgsScaleVisibilityDialog( QWidget *parent /TransferThis/ = 0, const QString &title = QString(), QgsMapCanvas *mapCanvas = 0 );
%Docstring
 Constructor for QgsScaleVisibilityDialog, with specified dialog ``title``. The ``mapCanvas`` argument
 can be used to associate the dialog with a map canvas, allowing use of the current map scale
 within the dialog.
%End

    bool hasScaleVisibility() const;
%Docstring
 Return true if scale based visibilty is enabled.
 :rtype: bool
%End

    double minimumScale() const;
%Docstring
 Returns the selected minimum scale, or 0 if minimum scale is not set.
 The scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.
.. seealso:: maximumScale()
.. seealso:: setMinimumScale()
 :rtype: float
%End

    double maximumScale() const;
%Docstring
 Returns the selected maximum scale, or 0 if maximum scale is not set.
 The scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.
.. seealso:: minimumScale()
.. seealso:: setMaximumScale())
 :rtype: float
%End

  public slots:

    void setScaleVisiblity( bool hasScaleVisibility );
%Docstring
 Set whether scale based visibility is enabled.
.. seealso:: hasScaleVisibility()
%End

    void setMinimumScale( double scale );
%Docstring
 Set the minimum ``scale``, or 0 to indicate the minimum is not set.
 The scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.
.. seealso:: minimumScale()
.. seealso:: setMaximumScale()
%End

    void setMaximumScale( double scale );
%Docstring
 Set the maximum ``scale``, or 0 to indicate the minimum is not set.
 The scale value indicates the scale denominator, e.g. 1000.0 for a 1:1000 map.
.. seealso:: maximumScale()
.. seealso:: setMinimumScale()
%End


};

/************************************************************************
 * This file has been generated automatically from                      *
 *                                                                      *
 * src/gui/qgsscalevisibilitydialog.h                                   *
 *                                                                      *
 * Do not edit manually ! Edit header and run scripts/sipify.pl again   *
 ************************************************************************/
