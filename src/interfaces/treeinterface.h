#ifndef TREEINTERFACE_H
#define TREEINTERFACE_H

class TreeInterface
{
	public:
		virtual ~TreeInterface() {}
};

Q_DECLARE_INTERFACE(TreeInterface,
                    "shz.Hussein.TreeInterface/1.0")

#endif // TREEINTERFACE_H
