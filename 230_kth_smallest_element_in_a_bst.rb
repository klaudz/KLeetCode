#!/usr/bin/ruby

require_relative 'common_ruby/tree'

# @param {TreeNode} root
# @param {Integer} k
# @return {Integer}
def kth_smallest(root, k)
    ret = nil
    i = 0
    root.dfs_inorder { |node|
        ret = node.val if i + 1 == k
        i += 1
    }
    ret
end

def _main_

    tree = TreeNode.new_from_array([ 3, 1, 4, nil, 2 ])
    ret = kth_smallest(tree, 1)
    puts "#{ret}"
        
    tree = TreeNode.new_from_array([ 5, 3, 6, 2, 4, nil, nil, 1 ])
    ret = kth_smallest(tree, 3)
    puts "#{ret}"

end

_main_