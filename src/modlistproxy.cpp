#include "modlistproxy.h"
#include "organizerproxy.h"
#include "proxyutils.h"

using namespace MOBase;

ModListProxy::ModListProxy(OrganizerProxy* oproxy, IModList* modlist) :
  m_OrganizerProxy(oproxy), m_Proxied(modlist) { }

QString ModListProxy::displayName(const QString& internalName) const
{
  return m_Proxied->displayName(internalName);
}

QStringList ModListProxy::allMods() const
{
  return m_Proxied->allMods();
}

IModList::ModStates ModListProxy::state(const QString& name) const
{
  return m_Proxied->state(name);
}

bool ModListProxy::setActive(const QString& name, bool active)
{
  return m_Proxied->setActive(name, active);
}

int ModListProxy::setActive(const QStringList& names, bool active)
{
  return m_Proxied->setActive(names, active);
}

int ModListProxy::priority(const QString& name) const
{
  return m_Proxied->priority(name);
}

bool ModListProxy::setPriority(const QString& name, int newPriority)
{
  return m_Proxied->setPriority(name, newPriority);
}

bool ModListProxy::onModStateChanged(const std::function<void(const std::map<QString, ModStates>&)>& func)
{
  return m_Proxied->onModStateChanged(MOShared::callIfPluginActive(m_OrganizerProxy, func));
}

bool ModListProxy::onModMoved(const std::function<void(const QString&, int, int)>& func)
{
  return m_Proxied->onModMoved(MOShared::callIfPluginActive(m_OrganizerProxy, func));
}
