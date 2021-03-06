#pragma once
#include "abstractnamespaceitem.h"

namespace ConnectionsTree {

class NamespaceItem : public QObject, public AbstractNamespaceItem
{
     Q_OBJECT

public:
    NamespaceItem(const QByteArray& fullPath,                  
                  QSharedPointer<Operations> operations,
                  QWeakPointer<TreeItem> parent,
                  Model& model,
                  uint dbIndex);

    QString getDisplayName() const override;    

    QByteArray getName() const override;

    QByteArray getFullPath() const;

    QString type() const override { return "namespace"; }    

    bool isEnabled() const override;        

    void setRemoved();

protected:
    void load();

    QHash<QString, std::function<void()>> eventHandlers() override;

private:
    QByteArray m_fullPath;    
    QByteArray m_displayName;
    bool m_removed;    
};
}
