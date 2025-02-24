#ifndef MAIN_CONTROLLER_H
#define MAIN_CONTROLLER_H

#include "fcu_controller.hpp"

#include <abstract_gateway.hpp>
#include <cockpit_loop.hpp>
#include <frame_fcu_display.hpp>
#include <frame_glareshield_indicator.hpp>

class MainController: public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool connected READ isConnected NOTIFY connection_changed FINAL)

    Q_PROPERTY(FcuController* fcu READ getFcuController CONSTANT)

public:
    explicit MainController(AbstractGateway *pGateway, CockpitLoop *pCockpit);
    virtual ~MainController();

    void start();
    bool isConnected();

    FcuController *getFcuController();

signals:
    void connection_changed();

private slots:
    void onEventReceived(const FrameEvent &event);

private:
    AbstractGateway *m_pGateway;
    CockpitLoop *m_pCockpit;

    FcuController *m_pFcuController;

    FrameFcuDisplay m_fcu;
    FrameGlareshieldIndicator m_glareshiedIndicator;
};

#endif // MAIN_CONTROLLER_H
