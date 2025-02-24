#include "fcu_controller.hpp"

FcuController::FcuController(
    CockpitLoop *pCockpit,
    FrameFcuDisplay *pFcu,
    FrameGlareshieldIndicator *pGlarshiedIndicator
) {
    m_pCockpit = pCockpit;
    m_pFcu = pFcu;
    m_pGlarshiedIndicator = pGlarshiedIndicator;
}

void FcuController::speedKnot(int nValue)
{
    m_pFcu->setKnotSpeed(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::speedMach(int nValue)
{
    m_pFcu->setMachSpeed(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::speedDot(bool bChecked)
{
    m_pFcu->setSpeedDot(bChecked);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::speedDashed(bool bChecked)
{
    m_pFcu->setSpeedDashed(bChecked);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::heading(int nValue)
{
    m_pFcu->setHeading(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::headingDot(bool bValue)
{
    m_pFcu->setHeadingDot(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::headingDashed(bool bValue)
{
    m_pFcu->setHeadingDashed(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::track(bool bValue)
{
    m_pFcu->setTrack(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::lat(bool bValue)
{
    m_pFcu->setLat(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::altitude(int nValue)
{
    m_pFcu->setAltitude(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::altitudeDot(bool bValue)
{
    m_pFcu->setAltitudeDot(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::altitudeDashed(bool bValue)
{
    m_pFcu->setAltitudeDashed(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::verticalSpeed(int nValue)
{
    m_pFcu->setVerticalSpeed(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::fpa(int nValue)
{
    m_pFcu->setFpa(nValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::verticalSpeedDashed(bool bValue)
{
    m_pFcu->setVerticalSpeedDashed(bValue);
    m_pCockpit->update(*m_pFcu);
}

void FcuController::ap1(bool bValue)
{
    m_pGlarshiedIndicator->setAp1(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}

void FcuController::ap2(bool bValue)
{
    m_pGlarshiedIndicator->setAp2(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}

void FcuController::athr(bool bValue)
{
    m_pGlarshiedIndicator->setAutoThrottle(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}

void FcuController::loc(bool bValue)
{
    m_pGlarshiedIndicator->setLoc(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}

void FcuController::exped(bool bValue)
{
    m_pGlarshiedIndicator->setExped(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}

void FcuController::appr(bool bValue)
{
    m_pGlarshiedIndicator->setApproch(bValue);
    m_pCockpit->update(*m_pGlarshiedIndicator);
}
