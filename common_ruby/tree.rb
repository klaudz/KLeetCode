
require_relative 'tree_node'

def create_tree_from_numbers(numbers)
    # Create the tree
    root = TreeNode.new(nil)
    node_queue = [ root ]
    numbers.each { |n|
        node = node_queue.shift
        node.val = n
        node.left = TreeNode.new(nil)
        node.right = TreeNode.new(nil)
        node_queue.push(node.left)
        node_queue.push(node.right)
    }
    # Trim the tree
    root = nil if root.val.nil?
    if root
        node_queue = [ root ]
        while node_queue.count > 0
            node = node_queue.shift
            node.left = nil if node.left and node.left.val.nil?
            node.right = nil if node.right and node.right.val.nil?
            node_queue.push(node.left) if node.left
            node_queue.push(node.right) if node.right
        end
    end
    root
end

#pragma mark - DFS

#pragma mark - DFS Preorder

def tree_search_dfs_preorder(tree)
    tree_search_dfs_preorder_iterator(tree) { |val| yield(val) }
end

def tree_search_dfs_preorder_recursion(tree)
    _tree_search_dfs_preorder_recursion_node(tree) { |val| yield(val) }
end

def _tree_search_dfs_preorder_recursion_node(node)
    return if node.nil?
    yield(node.val)
    _tree_search_dfs_preorder_recursion_node(node.left) { |val| yield(val) }
    _tree_search_dfs_preorder_recursion_node(node.right) { |val| yield(val) }
end

def tree_search_dfs_preorder_iterator(tree)
    return if tree.nil?
    node_stack = [ tree ]
    while node_stack.count > 0
        node = node_stack.pop
        yield(node.val)
        node_stack.push(node.right) if node.right
        node_stack.push(node.left) if node.left
    end
end

#pragma mark - DFS Inorder

def tree_search_dfs_inorder(tree)
    tree_search_dfs_inorder_recursion(tree) { |val| yield(val) }
end

def tree_search_dfs_inorder_recursion(tree)
    _tree_search_dfs_inorder_recursion_node(tree) { |val| yield(val) }
end

def _tree_search_dfs_inorder_recursion_node(node)
    return if node.nil?
    _tree_search_dfs_inorder_recursion_node(node.left) { |val| yield(val) }
    yield(node.val)
    _tree_search_dfs_inorder_recursion_node(node.right) { |val| yield(val) }
end

#pragma mark - DFS Postorder

def tree_search_dfs_postorder(tree)
    tree_search_dfs_postorder_recursion(tree) { |val| yield(val) }
end

def tree_search_dfs_postorder_recursion(tree)
    _tree_search_dfs_postorder_recursion_node(tree) { |val| yield(val) }
end

def _tree_search_dfs_postorder_recursion_node(node)
    return if node.nil?
    _tree_search_dfs_postorder_recursion_node(node.left) { |val| yield(val) }
    _tree_search_dfs_postorder_recursion_node(node.right) { |val| yield(val) }
    yield(node.val)
end

#pragma mark - BFS

def tree_search_bfs(tree)
    tree_search_bfs_iterator(tree) { |val| yield(val) }
end

def tree_search_bfs_iterator(tree)
    return if tree.nil?
    node_queue = [ tree ]
    while node_queue.count > 0
        node = node_queue.shift
        yield(node.val)
        node_queue.push(node.left) if node.left
        node_queue.push(node.right) if node.right
    end
end
