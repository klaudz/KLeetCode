
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
