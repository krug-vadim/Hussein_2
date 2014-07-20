#ifndef COMMANDINTERFACE_H
#define COMMANDINTERFACE_H

#include <QtCore/QtPlugin>
#include <QtCore/QList>

#include "treeinterface.h"

class CommandInterface
{
	public:
		virtual ~CommandInterface() {}

	public slots:
		virtual const TreeSharedPointer execute(const TreeSharedPointer &node) const =0;
};

typedef QList<CommandInterface*> Commands;

Q_DECLARE_INTERFACE(CommandInterface,
                    "shz.Hussein.CommandInterface/1.0")

#endif // COMMANDINTERFACE_H
