#include "yamlserializerplugin.h"

#include <yaml-cpp/yaml.h>

#include <QtCore/QFile>

#include <QtCore/QString>
#include <QtCore/QStringList>
#include <QtCore/QVariant>

static const char subNodesKeyName[] = "items";

YamlSerializerPlugin::YamlSerializerPlugin(QObject *parent) :
    QObject(parent)
{
}

QString YamlSerializerPlugin::description() const
{
	return tr("Simple Yaml Serializer");
}

QByteArray YamlSerializerPlugin::serialize(TreeSharedPointer root)
{
	YAML::Emitter out;

	out << YAML::BeginMap;

	if ( !root->nodes().empty() )
	{
		out << YAML::Key << subNodesKeyName;
		out << YAML::Value << YAML::BeginSeq;

		foreach(TreeSharedPointer node, root->nodes())
			serializeNode(out, node);

		out << YAML::EndSeq;
	}

	out << YAML::EndMap;

	return QByteArray(out.c_str());
}

bool YamlSerializerPlugin::serialize(const QString &fileName, TreeSharedPointer root)
{
	QFile file(fileName);

	if ( file.open(QIODevice::WriteOnly|QIODevice::Text) )
	{
		file.write(serialize(root));
		file.flush();
		file.close();
		return true;
	}
	else
		return false;
}

#include <QDateTime>

void YamlSerializerPlugin::deserialize(const QByteArray &data, TreeSharedPointer root)
{
	emit log(0, "loaded done, parsing");
	YAML::Node node = YAML::Load(data.constData());
	emit log(0, "parsed, creating items");

	deserializeRoot(node, root);

	emit log(0, QString("items created %1").arg(root->nodes().size()));
}

bool YamlSerializerPlugin::deserialize(const QString &fileName, TreeSharedPointer root)
{
	QFile file(fileName);

	if ( file.open(QIODevice::ReadOnly|QIODevice::Text) )
	{
		emit log(0, "deserializing");
		deserialize(file.readAll(), root);
		emit log(0, "stop deserializing");
		file.close();
		return true;
	}
	else
		return false;
}

void YamlSerializerPlugin::serializeNode(YAML::Emitter &out, TreeSharedPointer node)
{
	out << YAML::BeginMap;

	foreach(const QString &role, node->roles())
	{
		out << YAML::Key << role.toStdString();
		toYaml(out, node->data(role));
	}

	if ( !node->nodes().empty() )
	{
		out << YAML::Key << subNodesKeyName;
		out << YAML::Value << YAML::BeginSeq;

		foreach(TreeSharedPointer subNode, node->nodes())
			serializeNode(out, subNode);

		out << YAML::EndSeq;
	}

	out << YAML::EndMap;
}

void YamlSerializerPlugin::deserializeRoot(const YAML::Node &node, TreeSharedPointer root)
{
	if ( node.IsNull() )
		return;

	if ( node.IsMap() )
	{
		if ( !node[subNodesKeyName] )
			return;

		YAML::Node nodes = node[subNodesKeyName];

		if ( nodes.IsNull() )
			return;

		if ( !nodes.IsSequence() )
			return;

		foreach(YAML::Node node, nodes)
		{
			TreeSharedPointer item = deserializeNode(node, root);
			item->setParent(root);
			root->appendNode(item);
		}
	}

	if ( node.IsSequence() )
	{
		foreach(YAML::Node subNode, node)
		{
			TreeSharedPointer item = deserializeNode(subNode, root);
			item->setParent(root);
			root->appendNode(item);
		}
	}
}

TreeSharedPointer YamlSerializerPlugin::deserializeNode(const YAML::Node &node, const TreeSharedPointer root)
{
	if ( node.IsNull() )
		return TreeSharedPointer();

	if ( !node.IsMap() )
		return TreeSharedPointer();

	TreeSharedPointer item(root->create());

	foreach(const QString &role, item->roles())
	{
		if ( node[role.toStdString()] )
			item->setData(role, fromYaml(node[role.toStdString()]));
	}

	if ( !node[subNodesKeyName] )
		return item;

	YAML::Node nodes = node[subNodesKeyName];

	if ( nodes.IsNull() )
		return item;

	if ( !nodes.IsSequence() )
		return item;

	foreach(YAML::Node subNode, nodes)
	{
		TreeSharedPointer subItem = deserializeNode(subNode, item);
		subItem->setParent(item);
		item->appendNode(subItem);
	}

	return item;
}

bool YamlSerializerPlugin::toYaml(YAML::Emitter &out, const QVariant &data)
{
	QStringList list;

	switch ( data.type() )
	{
		case QMetaType::QString:
			out << YAML::Value << data.toString().toStdString();
			break;

		case QMetaType::Int:
			out << YAML::Value << data.toInt();
			break;

		case QMetaType::Bool:
			out << YAML::Value << data.toBool();
			break;

		case QMetaType::QByteArray:
			out << YAML::Value << QString(data.toByteArray().toHex()).toStdString();
			break;

		case QMetaType::QStringList:
			list = data.toStringList();
			out << YAML::Value << YAML::BeginSeq;

			foreach(const QString &string, list)
				out << YAML::Value << string.toStdString();

			out << YAML::EndSeq;
			break;

		default:
			out << YAML::Value << QString("(wrong type %1)").arg(data.type()).toStdString();
			return false;
			break;
	}

	return true;
}

QVariant YamlSerializerPlugin::fromYaml(const YAML::Node &node)
{
	if ( node.IsNull() )
		return QVariant();

//	if ( node.IsMap() )
//	{
//		QHash<QString, QString> map;

//		for(YAML::const_iterator it = node.begin(); it != node.end(); ++it)
//		{
//			if ( it->second.IsNull() )
//				continue;

//			if ( it->second.IsScalar() )
//				map[QString::fromStdString(it->first.as<std::string>())] = QString::fromStdString(it->second.as<std::string>());
//			else if ( it->second.IsSequence() )
//			{
//				QStringList list;
//				foreach(const YAML::Node &seq, it->second)
//					list << QString::fromStdString(seq.as<std::string>());
//				map[QString::fromStdString(it->first.as<std::string>())] = list;
//			}
//		}
//	}

	return QString::fromStdString(node.as<std::string>());
}
