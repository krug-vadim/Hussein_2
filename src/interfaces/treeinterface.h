#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

#include <QtCore/QList>
#include <QtCore/QSharedPointer>
#include <QtCore/QWeakPointer>

#include <QtCore/QVariant>

class TreeInterface;

typedef QSharedPointer<TreeInterface> TreeSharedPointer;
typedef QWeakPointer<TreeInterface> TreeWeakPointer;
typedef QList<TreeInterface> TreeNodes;

class TreeInterface
{
	public:
		TreeInterface() { clear(); }
		virtual ~TreeInterface() { clear(); }

		TreeWeakPointer parent() const { return _parent; }
		void setParent(const TreeWeakPointer &parent) { _parent = parent; }

		const TreeNodes &nodes() const { return _nodes; }

		void clear()
		{
			while( !_nodes.isEmpty() )
				_nodes.takeFirst().clear();
		}

		bool appendNode(const TreeSharedPointer &node)
		{
			if ( node.isNull() )
				return false;

			_nodes.append(node);

			return true;
		}

		bool insertNode(const TreeSharedPointer &node, int position)
		{
			if ( position < 0 || position > nodes().size() )
				return false;

			if ( node.isNull() )
				return false;

			_nodes.insert(position, node);

			return true;
		}

		bool removeNode(int position)
		{
			if ( position < 0 || position > nodes().size() )
				return false;

			_nodes.removeAt(position);

			return true;
		}

		virtual QVariant Task::data(int role) const = 0;
		virtual bool Task::setData(const QVariant &value, int role) = 0;

	private:
		TreeWeakPointer _parent;
		TreeNodes       _nodes;

};

Q_DECLARE_INTERFACE(TreeInterface,
                    "shz.Hussein.TreeInterface/1.0")

#endif // TREEINTERFACE_H
