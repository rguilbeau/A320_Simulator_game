#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <cockpit_loop.hpp>
#include <main_controller.hpp>
#include <tcp_gateway.hpp>

int main(int argc, char *argv[])
{
    TcpGateway *pGateway = new TcpGateway();
    CockpitLoop *pCockpit = new CockpitLoop(pGateway);

    QCoreApplication *pApp;

    MainController *pMainController = new MainController(pGateway, pCockpit);

    pApp = new QGuiApplication(argc, argv);

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("_mainController", pMainController);
    engine.loadFromModule("a320_simulator_game", "Main");

    pGateway->start();
    pCockpit->start();

    int nReturnCode = pApp->exec();

    delete pApp;

    delete pGateway;
    delete pCockpit;

    return nReturnCode;
}
