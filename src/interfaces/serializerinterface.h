#ifndef SERIALIZERINTERFACE_H
#define SERIALIZERINTERFACE_H

#include <QtCore/QString>

#include "treeinterface.h"

class SerializerInterface
{
	public:
		virtual ~SerializerInterface() {}

		virtual QByteArray serialize(TreeSharedPointer root) =0;
		virtual bool serialize(const QString &fileName, TreeSharedPointer root) =0;

		virtual void deserialize(const QByteArray &data, TreeSharedPointer root) =0;
		virtual bool deserialize(const QString &fileName, TreeSharedPointer root) =0;
};

Q_DECLARE_INTERFACE(SerializerInterface,
                    "shz.Hussein.SerializerInterface/1.0")

#endif // SERIALIZERINTERFACE_H
