#ifndef FCU_CONTROLLER_HPP
#define FCU_CONTROLLER_HPP

#include <QObject>
#include <cockpit_loop.hpp>
#include <frame_fcu_display.hpp>
#include <frame_glareshield_indicator.hpp>

class FcuController: public QObject
{
    Q_OBJECT

public:
    explicit FcuController(
        CockpitLoop *pCockpit,
        FrameFcuDisplay *pFcu,
        FrameGlareshieldIndicator *pGlarshiedIndicator
    );
    virtual ~FcuController() = default;

    Q_INVOKABLE void speedKnot(int nValue);
    Q_INVOKABLE void speedMach(int nValue);
    Q_INVOKABLE void speedDot(bool bValue);
    Q_INVOKABLE void speedDashed(bool bValue);

    Q_INVOKABLE void heading(int nValue);
    Q_INVOKABLE void headingDot(bool bValue);
    Q_INVOKABLE void headingDashed(bool bValue);
    Q_INVOKABLE void track(bool bValue);
    Q_INVOKABLE void lat(bool bValue);

    Q_INVOKABLE void altitude(int nValue);
    Q_INVOKABLE void altitudeDot(bool bValue);
    Q_INVOKABLE void altitudeDashed(bool bValue);

    Q_INVOKABLE void verticalSpeed(int nValue);
    Q_INVOKABLE void fpa(int nValue);
    Q_INVOKABLE void verticalSpeedDashed(bool bValue);

    Q_INVOKABLE void ap1(bool bValue);
    Q_INVOKABLE void ap2(bool bValue);
    Q_INVOKABLE void athr(bool bValue);
    Q_INVOKABLE void loc(bool bValue);
    Q_INVOKABLE void exped(bool bValue);
    Q_INVOKABLE void appr(bool bValue);

private:
    CockpitLoop *m_pCockpit;
    FrameFcuDisplay *m_pFcu;
    FrameGlareshieldIndicator *m_pGlarshiedIndicator;
};

#endif // FCU_CONTROLLER_HPP
