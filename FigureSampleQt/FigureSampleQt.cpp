#include "FigureSampleQt.h"

#include "ShapeFactory.h"

#include <QPluginLoader>
#include <QApplication>
#include <QDir>
#include <QMessageBox>

const QString pluginsFolder = "plugins";
const QString pluginExtention = "*.dll";

FigureSampleQt::FigureSampleQt(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	m_shapeActions = new QActionGroup(this);
	m_shapeActions->setExclusive(true);

	m_currentScene = new FigureScene(this);

	ui.graphicsView->setScene(m_currentScene);

	initializeRegistredTypes();
	
	initializePlugins();

	ui.mainToolBar->addActions(m_shapeActions->actions());

	
}

void FigureSampleQt::initializeRegistredTypes()
{
	auto registredTypes = ShapeFactory::registredTypes();

	for (const auto & id : registredTypes) {
		std::shared_ptr<FigureCommon::IShape> shp = ShapeFactory::create(id);
		if (shp != nullptr) {
			addShapeAction(shp);
		}	
	}
}

void FigureSampleQt::initializePlugins()
{
	auto app = QApplication::instance();

	auto pluginsPath = QDir(app->applicationDirPath());

	pluginsPath.cd(pluginsFolder);

	QStringList nameFilters{ pluginExtention };

	for (const QString &fileName : pluginsPath.entryList(nameFilters, QDir::Files))
	{
		QPluginLoader loader(pluginsPath.absoluteFilePath(fileName));
		QObject *plugin = loader.instance();

		if (plugin != nullptr) {
			auto shpRawPtr = qobject_cast<FigureCommon::IShape *>(plugin); 
			auto shp = std::shared_ptr<FigureCommon::IShape>(std::shared_ptr<FigureCommon::IShape>(), shpRawPtr);// Qt Plugin system delete object on unloading, so we don't need to manage it
			addShapeAction(shp);	
		}
		else {
			QMessageBox::warning(this, "Plugin Loader", QString("File %1 is not valid FigureSampleQt plugin!").arg(fileName), QMessageBox::Close);
		}

	}
}

void FigureSampleQt::addShapeAction(std::shared_ptr<FigureCommon::IShape> shape)
{
	QAction *newAction = m_shapeActions->addAction(shape->name());
	newAction->setCheckable(true);

	m_actionMap[newAction] = shape;

	connect(newAction, SIGNAL(toggled(bool)), this, SLOT(onShapeActionToggled(bool)));
}

void FigureSampleQt::onShapeActionToggled(bool tgl)
{
	if (!tgl)
		return;

	QAction *curAction = qobject_cast<QAction *>(sender());

	auto it = m_actionMap.find(curAction);
	if (it != m_actionMap.end()) {
		m_currentScene->setCurrentShape(it->second.get());
	}
	else {
		QMessageBox::warning(this, "Shape Action", QString("Shape %1 is not registred!").arg(curAction->text()), QMessageBox::Close);
	}
}
