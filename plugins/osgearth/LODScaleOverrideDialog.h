#pragma once

#include <QDialog>
#include <sgi/plugins/SGISettingsDialogImpl>

QT_BEGIN_NAMESPACE
class Ui_LODScaleOverrideDialog;
QT_END_NAMESPACE

namespace sgi {

class LODScaleOverrideDialog : public SettingsQDialogImpl
{
    Q_OBJECT

public:
    LODScaleOverrideDialog(QWidget * parent, SGIPluginHostInterface * hostInterface, SGIItemBase * item, ISettingsDialogInfo * info);
    ~LODScaleOverrideDialog() override;

public slots:
    void                    setLabel(const QString & message);
    QString                 label() const;

    void                    setValue(double value);
    double                  value() const;

    void                    setOriginalValue(double value);
    double                  originalValue() const;

    void                    setRange(double minimum, double maximum);

    void                    setDecimals(int decimals);
    int                     decimals() const;

protected slots:
    void                    reset();
    void                    apply();
    void                    sliderChanged(int pos);
    void                    spinBoxChanged(double value);

private:
    double                  _original_value;
    int                     _slider_factor;
    bool                    _ready;

private:  // for now
    Ui_LODScaleOverrideDialog* ui;
};

} // namespace sgi
