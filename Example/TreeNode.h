#ifndef TREENODE_H
#define TREENODE_H

template< typename T > class Tree;

template< typename T >
class TreeNode
{
	friend class Tree< T >;

public:
	TreeNode();
	TreeNode(const T&);

	T get_data() const;

private:
	T _data;
	TreeNode< T >* _left;
	TreeNode< T >* _right;
};

template< typename T >
TreeNode< T >::TreeNode() :
	_left(0),
	_right(0)
{
}

template< typename T >
TreeNode< T >::TreeNode(const T& data) :
	_data(data),
	_left(0),
	_right(0)
{
}

template< typename T >
T TreeNode< T >::get_data() const
{
	return _data;
}

#endif