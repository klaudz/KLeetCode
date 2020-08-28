
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val = 0, left = nil, right = nil)
        @val = val
        @left = left
        @right = right
    end
end

class TreeNode
    def self.new_from_array(array)
        # Create the tree
        root = TreeNode.new(nil)
        node_queue = [ root ]
        array.each { |n|
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
end

class TreeNode

    #pragma mark - DFS

    #pragma mark - DFS Preorder

    def dfs_preorder
        dfs_preorder_iterator { |node| yield(node) }
    end

    def dfs_preorder_recursion
        def _dfs_preorder_recursion_node(node)
            return if node.nil?
            yield(node)
            _dfs_preorder_recursion_node(node.left) { |node| yield(node) }
            _dfs_preorder_recursion_node(node.right) { |node| yield(node) }
        end
        _dfs_preorder_recursion_node(self) { |node| yield(node) }
    end
    
    def dfs_preorder_iterator
        node_stack = [ self ]
        while node_stack.count > 0
            node = node_stack.pop
            yield(node)
            node_stack.push(node.right) if node.right
            node_stack.push(node.left) if node.left
        end
    end

    #pragma mark - DFS Inorder

    def dfs_inorder
        dfs_inorder_recursion { |node| yield(node) }
    end

    def dfs_inorder_recursion
        def _dfs_inorder_recursion_node(node)
            return if node.nil?
            _dfs_inorder_recursion_node(node.left) { |node| yield(node) }
            yield(node)
            _dfs_inorder_recursion_node(node.right) { |node| yield(node) }
        end
        _dfs_inorder_recursion_node(self) { |node| yield(node) }
    end

    #pragma mark - DFS Postorder

    def dfs_postorder
        dfs_postorder_recursion { |node| yield(node) }
    end

    def dfs_postorder_recursion
        def _dfs_postorder_recursion_node(node)
            return if node.nil?
            _dfs_postorder_recursion_node(node.left) { |node| yield(node) }
            _dfs_postorder_recursion_node(node.right) { |node| yield(node) }
            yield(node)
        end
        _dfs_postorder_recursion_node(self) { |node| yield(node) }
    end

    #pragma mark - BFS

    def bfs
        bfs_iterator { |node| yield(node) }
    end

    def bfs_iterator
        node_queue = [ self ]
        while node_queue.count > 0
            node = node_queue.shift
            yield(node)
            node_queue.push(node.left) if node.left
            node_queue.push(node.right) if node.right
        end
    end

end
