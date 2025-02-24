#include "main_controller.hpp"


MainController::MainController(AbstractGateway *pGateway, CockpitLoop *pCockpit)
{
    m_pGateway = pGateway;
    m_pCockpit = pCockpit;

    m_pFcuController = new FcuController(m_pCockpit, &m_fcu, &m_glareshiedIndicator);

    connect(pGateway, &AbstractGateway::connection_changed, this, &MainController::connection_changed);
    connect(pCockpit, &CockpitLoop::event_received, this, &MainController::onEventReceived);
}

MainController::~MainController()
{
    delete m_pFcuController;
    m_pFcuController = 0;
}

void MainController::start()
{
    // do nothing
}

bool MainController::isConnected()
{
    return m_pGateway->isConnected();
}

FcuController *MainController::getFcuController()
{
    return m_pFcuController;
}

void MainController::onEventReceived(const FrameEvent &event)
{
    qDebug() << "event ==> " << event.getEvent() << event.getValue();
}
