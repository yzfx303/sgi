#pragma once

#include <QDialog>
#include <QDockWidget>
#include <sgi/plugins/SGISettingsWindowImpl>

QT_BEGIN_NAMESPACE
class Ui_ShaderEditorDialog;
class QTextEdit;
QT_END_NAMESPACE
namespace osg {
    class StateSet;
    class Program;
}
namespace osgEarth {
    class VirtualProgram;
    class PolyShader;
}

namespace sgi {

class ShaderEditorDialog;

class InfoLogDock : public QDockWidget
{
    Q_OBJECT

public:
    InfoLogDock(ShaderEditorDialog * parent=nullptr);
    ~InfoLogDock() override;

    void setInfoLog(const std::string & log);

private:
    QTextEdit * _log;
};

class ShaderEditorDialog : public SettingsQMainWindowImpl
{
    Q_OBJECT

public:
    ShaderEditorDialog(QWidget * parent, SGIPluginHostInterface * hostInterface, SGIItemBase * item, ISettingsDialogInfo * info);
    ~ShaderEditorDialog() override;

public slots:

protected slots:
    void                    reset();
    void                    apply();
    void                    load();
    void                    reload();

    void                    vpFunctionChanged(int index);
    void                    vpFunctionAdd(QAction * action);
    void                    vpFunctionRemove();
    void                    vpFunctionDetails();
    void                    vpInheritShaders(bool b);
    void                    vpLogChanged(bool b);
    void                    vpLogFile(const QString & s);

    void                    progShaderChanged(int index);
    void                    progShaderAdd();
    void                    progShaderRemove();

    void                    openItem();

protected:
    osg::StateSet *         getStateSet(bool create = false);
    osgEarth::VirtualProgram * getVirtualProgram(bool create = false);
    osg::Program *          getProgram(bool create = false);
    osgEarth::PolyShader *  getPolyShader(int index);
    bool                    removeVPShader(int index);
    void                    loadInfoLog();

private:  // for now
    IHostCallbackPtr                _hostCallback;
    Ui_ShaderEditorDialog* ui;
    InfoLogDock * _infoLogDock;
    bool _ready;
    int _currentVPFunctionIndex;
    int _currentProgShaderIndex;
};

} // namespace sgi
