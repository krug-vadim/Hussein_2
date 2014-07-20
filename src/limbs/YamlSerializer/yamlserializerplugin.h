#ifndef YAMLSERIALIZERPLUGIN_H
#define YAMLSERIALIZERPLUGIN_H

#include <QtCore/QObject>

#include "../../interfaces/basicinterface.h"
#include "../../interfaces/serializerinterface.h"

#include "../../interfaces/commandinterface.h"

#include <QtCore/QByteArray>
#include <QtCore/QVariant>

namespace YAML
{
	class Emitter;
	class Node;
}

class YamlSerializerPlugin : public QObject,
                             public BasicInterface,
                             public CommandInterface,
                             public SerializerInterface
{
	Q_OBJECT
	Q_PLUGIN_METADATA(IID "org.Hussein.YamlSerializerPlugin")
	Q_INTERFACES(BasicInterface)
	Q_INTERFACES(CommandInterface)
	Q_INTERFACES(SerializerInterface)

	public:
		explicit YamlSerializerPlugin(QObject *parent = 0);

		// BasicInterface
		virtual QString description() const;

		// SerializerInterface
		virtual QByteArray serialize(TreeSharedPointer root);
		virtual bool serialize(const QString &fileName, TreeSharedPointer root);

		virtual void deserialize(const QByteArray &data, TreeSharedPointer root);
		virtual bool deserialize(const QString &fileName, TreeSharedPointer root);

		// CommandInterface
		virtual const TreeSharedPointer execute(const TreeSharedPointer &node) const;

		//
		virtual const Commands &commands(QObject *parent = 0);

	signals:
		void log(const uint event, const QString &message) const;

	private:
		static void serializeNode(YAML::Emitter &out, TreeSharedPointer node);
		static void deserializeRoot(const YAML::Node &node, TreeSharedPointer root);
		static TreeSharedPointer deserializeNode(const YAML::Node &node, const TreeSharedPointer root);

		static bool toYaml(YAML::Emitter &out, const QVariant &data);
		static QVariant fromYaml(const YAML::Node &node);

		Commands _commands;
};

#endif // YAMLSERIALIZERPLUGIN_H
