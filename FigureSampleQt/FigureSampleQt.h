#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FigureSampleQt.h"

#include <map>
#include <memory>

#include "IShape.h"
#include "FigureScene.h"

class FigureSampleQt : public QMainWindow
{
    Q_OBJECT

public:
    FigureSampleQt(QWidget *parent = nullptr);

private:
    Ui::FigureSampleQtClass ui;

	std::map<QAction *, std::shared_ptr<FigureCommon::IShape>> m_actionMap; //map to associate action with shapes

	QActionGroup *m_shapeActions;// group of shape actions

	FigureScene *m_currentScene;// scene

	//************************************
	// Method:    initializeRegistredTypes - initialize internal shape types
	//************************************
	void initializeRegistredTypes();

	//************************************
	// Method:    initializeRegistredTypes - initialize shapes from plugins
	//************************************
	void initializePlugins();

	//************************************
	// Method:    addShapeAction - add new action to toolbar
	// Parameter: FigureCommon::IShape * shape - shape to initialize
	//************************************
	void addShapeAction(std::shared_ptr<FigureCommon::IShape> shape);

private slots:
	//************************************
	// Method:    onActionToggled - change shape type handler
	// Parameter: bool tgl - true, if shape checked
	//************************************
	void onShapeActionToggled(bool tgl);

};
